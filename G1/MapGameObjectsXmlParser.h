#pragma once

#pragma once

#ifndef _MAP_GAME_OBJECTS_XML_PARSER_H_
#define _MAP_GAME_OBJECTS_XML_PARSER_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#include <string>
#include <vector>
#include <variant>
#include <map>

#include "IXmlParser.h"
#include "PrefabGameObjects.h"
#include "IPrefab.h"
#include "XmlComponentParser.h"

#include "XmlTransfromParser.h"

namespace G1 {

	class MapGameObjectsXmlParser : public IXmlParser {
		prefabArgs loadArgs(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			prefabArgs args;
			BOOST_FOREACH(ptree::value_type &obj, val.second.get_child("")) {
				if (obj.first == "args") {
					prefabArgs args;
					BOOST_FOREACH(ptree::value_type &v, obj.second.get_child("")) {
						std::string label = v.first;
						std::string type = v.second.get("<xmlattr>.type", "");

						prefabArg arg;
						if (type == "int") {
							arg = obj.second.get<int>(label);
						}
						else if (type == "float") {
							arg = obj.second.get<float>(label);
						}
						else if (type == "bool") {
							arg = obj.second.get<bool>(label);
						}
						else if (type == "string") {
							arg = obj.second.get<std::string>(label);
						}
						args[label] = arg;
					}
					return args;
				}
			}
			return args;
		}

		std::vector<Component*> loadComponents(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			std::vector<Component*> components;
			XmlComponentParser componentParser;

			BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
				std::string label = v.first;
				if (label != "<xmlattr>") {
					if (label == "component") {
						Component* tmpComponent = componentParser.load(v);
						if (tmpComponent) {
							components.push_back(tmpComponent);
						}
					}
				}
			}

			return components;
		}

	public:
		std::vector<GameObject*> gameObjects;

		void load(const std::string &filename) {
			using namespace boost::property_tree;

			ptree tree;
			read_xml(filename, tree);

			// PARSING RESOURCES / ASSETS
			BOOST_FOREACH(ptree::value_type &node, tree.get_child("GameMap.gameObjects")) {
				ptree subtree = node.second;
				if (node.first == "gameObject") {
					GameObject* newGameObject;

					std::string prefabName = node.second.get("<xmlattr>.prefab", "");
					if (prefabName.empty()) {
						newGameObject = new GameObject();
					} else {
						prefabArgs args = loadArgs(node);

						PrefabGameObjects prefabs;
						newGameObject = prefabs.getInstanceOf(prefabName, args);
						if (newGameObject == NULL) {
							continue;
						}
					}
					
					BOOST_FOREACH(ptree::value_type &v, subtree.get_child("")) {
						std::string label = v.first;
						if (label != "<xmlattr>") {
							if (label == "transform") {
								XmlTransformParser tranParser;
								newGameObject->setTransform(
									tranParser.loadTransform(v)
								);
							}
							else if (label == "layer") {
								newGameObject->setLayer( Layer( 1 << subtree.get<int>(label) ) );
							}
							else if (label == "components") {
								auto components = loadComponents(v);
								for (size_t i = 0; i < components.size(); i++) {
									newGameObject->addComponent(components[i]);
								}
							}
						}
					}
					gameObjects.push_back(newGameObject);
				}
			}

		}
	};
}

#endif //!_MAP_GAME_OBJECTS_XML_PARSER_H_


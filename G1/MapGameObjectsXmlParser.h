#pragma once

#pragma once

#ifndef _MAP_GAME_OBJECTS_XML_PARSER_H_
#define _MAP_GAME_OBJECTS_XML_PARSER_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#include <string>
#include <vector>

#include "IXmlParser.h"
#include "PrefabGameObjects.h"

namespace G1 {

	class MapGameObjectsXmlParser : public IXmlParser {
		Transform loadTransform(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			Transform transform;
			BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
				std::string label = v.first;
				if (label == "position") {
					transform.position.x = v.second.get<float>("x", 0.0f);
					transform.position.y = v.second.get<float>("y", 0.0f);
				}
				else if (label == "scale") {
					transform.scale.x = v.second.get<float>("x", 1.0f);
					transform.scale.y = v.second.get<float>("y", 1.0f);
				}
				else if (label == "rotationX") {
					transform.rotationX = val.second.get<float>(label, 0.0f);
				}
			}
			return transform;
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
						// NO PREFAB/ from scratch
						newGameObject = new GameObject();
					}
					else {
						// CREATE GAME OBJECT FROM PREFAB
						PrefabGameObjects prefabs;
						newGameObject = prefabs.getInstanceOf(prefabName);
					}
					
					BOOST_FOREACH(ptree::value_type &v, subtree.get_child("")) {
						std::string label = v.first;
						if (label != "<xmlattr>") {
							if (label == "transform") {
								// setting transform
								newGameObject->setTransform(
									loadTransform(v)
								);
							}
							else if (label == "layer") {
								// setting layer
								newGameObject->setLayer( Layer( 1 << subtree.get<int>(label) ) );
							}
							else if (label == "components") {
								// ADDING COMPONENTS
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


#pragma once


#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/foreach.hpp"
#include <string>
#include <set>
#include <vector>
#include <exception>
#include <iostream>

#include "MapTile9.h"
#include "IXmlParser.h"

namespace G1 {

	struct MapAssetsXmlParser : public IXmlParser {
		struct resource {
			enum class Type {
				TEXTURE,
				AUDIO
			};
			Type type = Type::TEXTURE;
			std::string path;
			std::string name;

			bool repeted = false;
		};

		std::vector<resource> resources;

		void load(const std::string &filename) {
			using namespace boost::property_tree;

			ptree tree;
			read_xml(filename, tree);

			// PARSING RESOURCES / ASSETS
			BOOST_FOREACH(ptree::value_type &node, tree.get_child("TileMap.resources")) {
				ptree subtree = node.second;
				if (node.first == "texture" || node.first == "soundBuffer") {
					resource res;
					if (node.first == "texture") {
						res.type = resource::Type::TEXTURE;
					}
					else if (node.first == "soundBuffer") {
						res.type = resource::Type::AUDIO;
					}
					BOOST_FOREACH(ptree::value_type &v, subtree.get_child("")) {
						std::string label = v.first;
						if (label != "<xmlattr>") {
							if (label == "path") {
								res.path = subtree.get<std::string>(label);
							}
							else if (label == "name") {
								res.name = subtree.get<std::string>(label);
							}
							else if (label == "repeted") {
								res.repeted = subtree.get<bool>(label);
							}
						}
					}
					resources.push_back(res);
				}
			}

		}
	};
}

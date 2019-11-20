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


struct MapXmlParser {
	std::vector<G1::GameObject*> objects;
	int tileSizeX = 10;
	int tileSizeY = 10;

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

		//tileSizeX = tree.get<int>("TileMap.tile_size.x");
		//tileSizeY = tree.get<int>("TileMap.tile_size.y");

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

			//objects.push_back(v.second.data());
		}

		//BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("TileMap.Tile9")) {
		//	// The data function is used to access the data stored in a node.
		//	objects.push_back(v.second.data());
		//}

	}
};

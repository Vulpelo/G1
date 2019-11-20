#pragma once

#include "MapXmlParser.h"

#include "GameMap.h"
#include "MapTileProperties.h"

class MapLoader {
public:
	void load(GameMap* gameMap, std::string pathToXml) {
		
		MapXmlParser parser;
		parser.load(pathToXml);

		Assets& assets = Assets::getInstance();

		// Loading assets
		for (size_t i = 0; i < parser.resources.size(); i++) {
			switch (parser.resources[i].type)
			{
				case MapXmlParser::resource::Type::TEXTURE: {
					std::string name;
					if (parser.resources[i].name.empty()) {
						name = parser.resources[i].path;
						assets.textures().load(name);
					}
					else {
						name = parser.resources[i].name;
						assets.textures().load(name,
							parser.resources[i].path);
					}
					assets.textures().get(name).setRepeated(
						parser.resources[i].repeted);
				} break;
				case MapXmlParser::resource::Type::AUDIO: {
					if (parser.resources[i].name.empty()) {
						assets.soundBuffers().load(
							parser.resources[i].path);
					}
					else {
						assets.soundBuffers().load(
							parser.resources[i].name,
							parser.resources[i].path);
					}
				} break;
			}
		}

		//MapTileProperties::setTileSize(Vector2(parser.tileSizeX, parser.tileSizeY));
	}
};

#pragma once

#ifndef _MAP_LOADER_H_
#define _MAP_LOADER_H_

#include "MapAssetsXmlParser.h"

#include "GameMap.h"
#include "MapTileProperties.h"

namespace G1 {

class MapLoader {

	void loadAssets(const std::string& path) {
		Assets& assets = Assets::getInstance();
		MapAssetsXmlParser assetsParser;
		assetsParser.load(path);

		for (size_t i = 0; i < assetsParser.resources.size(); i++) {
			MapAssetsXmlParser::resource res = assetsParser.resources[i];
			switch (res.type)
			{
			case MapAssetsXmlParser::resource::Type::TEXTURE: {
				std::string name;
				if (res.name.empty()) {
					name = res.path;
					assets.textures().load(name);
				}
				else {
					name = res.name;
					assets.textures().load(name, res.path);
				}
				assets.textures().get(name).setRepeated(res.repeted);
			} break;
			case MapAssetsXmlParser::resource::Type::AUDIO: {
				if (res.name.empty()) {
					assets.soundBuffers().load(res.path);
				}
				else {
					assets.soundBuffers().load(res.name, res.path);
				}
			} break;
			}
		}
	}

	void loadGameObjects(GameMap* gameMap, const std::string& pathToXml) {

	}

public:
	void load(GameMap* gameMap, const std::string& pathToXml) {
		loadAssets(pathToXml);
		loadGameObjects(gameMap, pathToXml);
	}
};

}

#endif // !_MAP_LOADER_H_

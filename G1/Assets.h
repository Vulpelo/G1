#pragma once

#include <map>
#include "SFML\Graphics\Texture.hpp"

namespace G1 {

	class Assets
	{
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Texture>::iterator textureIter;

		Assets() {};

	public:
		static Assets& getInstance() {
			static Assets assets;
			return assets;
		}

		void loadTexture(const std::string& path);
		sf::Texture& getTexture(const std::string& path);
		/// <summary> Removes texture from memory </summary>
		void unLoadTexture(const std::string& path);
		/// <summary> Removes all textures from memory </summary>
		void unLoadAllTextures();
	};

}

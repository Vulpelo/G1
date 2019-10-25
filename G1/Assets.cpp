#include "Assets.h"

namespace G1 {
	void Assets::loadTexture(const std::string & path)
	{
		sf::Texture texture; texture.loadFromFile(path);
		if ((textureIter = textures.find(path)) != textures.end()) {
			textures.erase(textureIter);
		}
		textures.emplace(path, std::move(texture));
	}

	sf::Texture & Assets::getTexture(const std::string & path)
	{
		if ((textureIter = textures.find(path)) != textures.end()) {
			return textureIter->second;
		}
	}

	const sf::Texture & Assets::getTexture(const std::string & path) const
	{
		return getTexture(path);
	}
	void Assets::unLoadTexture(const std::string & path)
	{
		if ((textureIter = textures.find(path)) != textures.end()) {
			textures.erase(textureIter);
		}
	}

	void Assets::unLoadAllTextures()
	{
		textures.clear();
	}

}

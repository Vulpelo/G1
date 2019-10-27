#pragma once

#include <map>
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Audio.hpp"

#include "Resources.h"

namespace G1 {

	class Assets
	{
		Resources<sf::Texture> textureResource;
		Resources<sf::SoundBuffer> soundBufferResource;

		Assets() {};

	public:
		static Assets& getInstance() {
			static Assets assets;
			return assets;
		}

		Resources<sf::Texture>& textures() { return textureResource; }
		Resources<sf::SoundBuffer>& soundBuffers() { return soundBufferResource; }
	};

}

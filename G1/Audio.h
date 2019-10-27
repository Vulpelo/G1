#pragma once

#include "Assets.h"

#include "SFML\Audio.hpp"

#include <vector>
#include <list>

namespace G1 {

	class Audio {
		static std::list<sf::Sound> soundHolders;

		static sf::Sound& getSoundHolder();
	public:
		static void play(const std::string& name, bool loop = false);
	};

}

#pragma once

#include "Assets.h"

#include "SFML\Audio.hpp"

namespace G1 {

	class Audio {
		static sf::Sound soundHolder;
	public:
		static void play(const std::string& name);
	};

}

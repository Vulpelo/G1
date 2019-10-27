#include "Audio.h"

namespace G1 {

	sf::Sound Audio::soundHolder;

	void Audio::play(const std::string & name)
	{
		soundHolder.setBuffer(Assets::getInstance().soundBuffers().get(name));
		soundHolder.play();
	}

}

#include "Audio.h"

namespace G1 {

	std::list<sf::Sound> Audio::soundHolders;

	sf::Sound & Audio::getSoundHolder() 
	{
		size_t i = 0;
		for (std::list<sf::Sound>::iterator it = soundHolders.begin(); 
			it != soundHolders.end(); 
			it++) 
		{
			if (it->getStatus() == sf::Sound::Stopped) {
				return *it;
			}
		}
		soundHolders.push_back(sf::Sound());
		return soundHolders.back();
	}

	void Audio::play(const std::string & name, bool loop)
	{
		sf::Sound& sound = getSoundHolder();
		sound.setBuffer( Assets::getInstance().soundBuffers().get(name) );
		sound.setLoop(loop);
		sound.play();
	}

}

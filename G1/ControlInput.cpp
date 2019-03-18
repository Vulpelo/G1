#include "ControlInput.h"

namespace G1 {

	ControlInput::ControlInput()
	{
		//window = RenderManager::getWindow();
	}

	ControlInput::ControlInput(sf::RenderWindow * w)
	{
		window = w;
	}

	void ControlInput::mainEventTick()
	{
		while (window->pollEvent(input))
		{
			if (input.type == sf::Event::Closed)
				window->close();
		}
	}

	bool ControlInput::down_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	}
	bool ControlInput::up_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	}
	bool ControlInput::right_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	}
	bool ControlInput::left_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	}
	bool ControlInput::w_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	}
	bool ControlInput::space_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	}
	bool ControlInput::s_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	}
	bool ControlInput::a_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	}
	bool ControlInput::d_KeyboardKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	}
	sf::Vector2i ControlInput::mousePosition()
	{
		return sf::Mouse::getPosition(*window);
	}
	bool ControlInput::leftMouseButtonPressed()
	{
		return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

}

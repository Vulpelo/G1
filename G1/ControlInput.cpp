#include "ControlInput.h"

namespace G1 {

	bool ControlInput::keyDownTable[] = { false };
	bool ControlInput::keyDownTablePrevious[] = { false };


	ControlInput::ControlInput()
	{
	}

	ControlInput& ControlInput::getInstantiate()
	{
		static ControlInput controlInput;
		return controlInput;
	}

	void ControlInput::setRenderWindow(sf::RenderWindow& window)
	{
		this->window = &window;
	}

	void ControlInput::mainEventTick()
	{
		updateKeyDownTable();
	}

	void ControlInput::catchEvents(sf::Event & events)
	{
		if (events.type == sf::Event::Closed)
			window->close();
	}

	void ControlInput::resetKeyDownTable()
	{
		for (unsigned int i = 0; i < (unsigned int)sf::Keyboard::Key::KeyCount; i++) {
			keyDownTable[i] = false;
		}
	}

	void ControlInput::updateKeyDownTable()
	{
		for (unsigned int i = 0; i < (unsigned int)sf::Keyboard::Key::KeyCount; i++) {
			keyDownTablePrevious[i] = keyDownTable[i];
			keyDownTable[i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
		}
	}

	bool ControlInput::isKeyDown(sf::Keyboard::Key key) const
	{
		return sf::Keyboard::isKeyPressed(key);
	}

	bool ControlInput::keyDown(sf::Keyboard::Key key) const
	{
		return keyDownTable[(unsigned int)key] &&
			!keyDownTablePrevious[(unsigned int)key];
	}

	bool ControlInput::keyUp(sf::Keyboard::Key key) const
	{
		return !keyDownTable[(unsigned int)key] &&
			keyDownTablePrevious[(unsigned int)key];
	}

	sf::Vector2i ControlInput::mousePosition()
	{
		return sf::Mouse::getPosition(*window);
	}
	bool ControlInput::isMouseButtonDown(int button)
	{
		switch (button)
		{
		case 0:
			return sf::Mouse::isButtonPressed(sf::Mouse::Left);
		case 1:
			return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
		case 2:
			return sf::Mouse::isButtonPressed(sf::Mouse::Right);
		}
		return false;
	}

}

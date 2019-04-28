#include "ControlInput.h"

namespace G1 {

	ControlInput* ControlInput::controlInput = NULL;

	ControlInput::ControlInput()
	{
		//window = RenderManager::getWindow();
	}

	ControlInput* ControlInput::getInstantiate()
	{
		if (controlInput == NULL) {
			controlInput = new ControlInput();
		}
		return controlInput;
	}

	void ControlInput::setRenderWindow(sf::RenderWindow * window)
	{
		this->window = window;
	}

	void ControlInput::mainEventTick()
	{
		while (window->pollEvent(input))
		{
			if (input.type == sf::Event::Closed)
				window->close();
		}
	}

	bool ControlInput::isKeyDown(Key key)
	{
		switch (key)
		{
		case G1::A:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		case G1::B:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::B);
		case G1::C:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::C);
		case G1::D:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		case G1::E:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::E);
		case G1::F:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::F);
		case G1::G:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::G);
		case G1::H:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::H);
		case G1::I:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::I);
		case G1::J:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::J);
		case G1::K:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::K);
		case G1::L:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::L);
		case G1::M:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::M);
		case G1::N:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::N);
		case G1::O:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::O);
		case G1::P:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::P);
		case G1::Q:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
		case G1::R:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::R);
		case G1::S:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		case G1::T:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::T);
		case G1::U:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::U);
		case G1::V:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::V);
		case G1::W:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		case G1::X:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::X);
		case G1::Y:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
		case G1::Z:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
		case G1::LEFT_ARROW:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		case G1::RIGHT_ARROW:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		case G1::UP_ARROW:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		case G1::DOWN_ARROW:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
		case G1::SPACE:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
		case G1::TAB:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Tab);
		case G1::ENTER:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Menu);
		case G1::LEFT_CTRL:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
		case G1::RIGHT_CTRL:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
		case G1::LEFT_ALT:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
		case G1::RIGHT_ALT:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt);
		case G1::LEFT_SHIFT:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
		case G1::RIGHT_SHIFT:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
		}
		return false;
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

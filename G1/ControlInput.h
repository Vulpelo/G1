#pragma once

#ifndef CONTROLINPUT_H
#define CONTROLINPUT_H

#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>

class ControlInput
{
private:
	sf::Event input;
	sf::RenderWindow * window;

public:
	ControlInput(sf::RenderWindow * w);
	void mainEventTick();

	bool down_KeyboardKeyPressed();
	bool up_KeyboardKeyPressed();
	bool right_KeyboardKeyPressed();
	bool left_KeyboardKeyPressed();
	bool a_KeyboardKeyPressed();
	bool d_KeyboardKeyPressed();
	bool s_KeyboardKeyPressed();
	bool w_KeyboardKeyPressed();

	sf::Vector2i mousePosition();
	bool leftMouseButtonPressed();
};

#endif // !CONTROLINPUT_H

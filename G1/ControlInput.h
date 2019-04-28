#pragma once

#ifndef _CONTROL_INPUT_H_
#define _CONTROL_INPUT_H_

#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>

namespace G1 {

	enum Key {
		A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
		LEFT_ARROW, RIGHT_ARROW, UP_ARROW, DOWN_ARROW,
		SPACE, TAB, ENTER,
		LEFT_CTRL, RIGHT_CTRL,
		LEFT_ALT, RIGHT_ALT,
		LEFT_SHIFT, RIGHT_SHIFT
	};

	class ControlInput
	{
		friend class Engine;

		static ControlInput* controlInput;

		sf::Event input;
		sf::RenderWindow * window;

		void mainEventTick();

	public:
		ControlInput();

		static ControlInput* getInstantiate();

		void setRenderWindow(sf::RenderWindow *window);

		/// <summary> Returns true if selected key is held down </summary>
		bool isKeyDown(Key key);

		/// <summary>Returns position of mouse cursor relative to window</summary>
		sf::Vector2i mousePosition();

		/// <summary>0-left mouse button; 1-middle mouse button; 2-right mouse button</summary>
		/// <returns>True if given mouse button is being pressed</returns>
		bool mouseButtonDown(int button = 0);
	};

}

#endif // !_CONTROL_INPUT_H_

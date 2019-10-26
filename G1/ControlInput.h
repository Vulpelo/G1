#pragma once

#ifndef _CONTROL_INPUT_H_
#define _CONTROL_INPUT_H_

#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>

namespace G1 {

	class ControlInput
	{
		friend class Engine;

		static ControlInput* controlInput;

		static bool keyDownTable[(unsigned int)sf::Keyboard::Key::KeyCount];
		static bool keyDownTablePrevious[(unsigned int)sf::Keyboard::Key::KeyCount];

		sf::Event input;
		sf::RenderWindow * window;

		void mainEventTick();

		void resetKeyDownTable();
		void updateKeyDownTable();

	public:
		ControlInput();

		static ControlInput* getInstantiate();

		void setRenderWindow(sf::RenderWindow& window);

		/// <summary> Returns true if selected key is held down </summary>
		bool isKeyDown(sf::Keyboard::Key key);

		/// <summary>
		/// Returns true if selected key was pressed before this frame
		/// </summary>
		bool keyDown(sf::Keyboard::Key key);
		/// <summary>
		/// Returns true if selected key was release before this frame
		/// </summary>
		bool keyUp(sf::Keyboard::Key key);

		/// <summary>Returns position of mouse cursor relative to window</summary>
		sf::Vector2i mousePosition();

		/// <summary>0-left mouse button; 1-middle mouse button; 2-right mouse button</summary>
		/// <returns>True if given mouse button is being pressed</returns>
		bool mouseButtonDown(int button = 0);
	};

}

#endif // !_CONTROL_INPUT_H_

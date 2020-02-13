#pragma once

#ifndef _CONTROL_INPUT_H_
#define _CONTROL_INPUT_H_

#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include "RenderProperties.h"
#include "Camera.h"

namespace G1 {

	class ControlInput
	{
		friend class Engine;
		friend class RenderManager;
		friend class CollisionDetection;

		static bool keyDownTable[(unsigned int)sf::Keyboard::Key::KeyCount];
		static bool keyDownTablePrevious[(unsigned int)sf::Keyboard::Key::KeyCount];

		static bool mouseDownTable[(unsigned int)sf::Mouse::ButtonCount];
		static bool mouseDownTablePrevious[(unsigned int)sf::Mouse::ButtonCount];

		const void* mouseIsOverlapping = NULL;

		sf::RenderWindow * window;

		void mainEventTick();
		void catchEvents(sf::Event& events);

		void resetKeyDownTable();
		void updateKeyDownTable();

		void setMouseIsOverlapping(const void* ptr) { mouseIsOverlapping = ptr; }

	public:
		ControlInput();

		const void* getMouseIsOverlapping() { return mouseIsOverlapping; }

		static ControlInput& getInstantiate();

		void setRenderWindow(sf::RenderWindow& window);

		/// <summary> Returns true if selected key is held down </summary>
		bool isKeyDown(sf::Keyboard::Key key) const;

		/// <summary>
		/// Returns true if selected key was pressed before this frame
		/// </summary>
		bool keyDown(sf::Keyboard::Key key) const;
		/// <summary>
		/// Returns true if selected key was release before this frame
		/// </summary>
		bool keyUp(sf::Keyboard::Key key) const;

		/// <summary>Returns position of mouse cursor relative to window</summary>
		sf::Vector2i mousePosition();

		/// <summary>0-left mouse button; 1-middle mouse button; 2-right mouse button</summary>
		/// <returns>True if given mouse button is being pressed</returns>
		bool isMouseButtonDown(int button = 0);
		bool mouseButtonDown(sf::Mouse::Button button);
		bool mouseButtonUp(sf::Mouse::Button button);
	};

}

#endif // !_CONTROL_INPUT_H_

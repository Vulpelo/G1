#pragma once

#include "GameObject.h"
#include "ContainerElement.h"

#include "RectangleRenderer.h"
#include "RectangleCollider.h"
#include "CircleCollider.h"

#include "RenderProperties.h"
#include "Text.h"

using namespace G1;

class UIStartButton : public GameObject {
	sf::Font font;
	RectangleRenderer* rr = NULL;

public:
	void startPlay() {
		Layout::ContainerElement* con = new Layout::ContainerElement();
		con->setAnchor(Layout::Anchor::MIDDLE);
		addComponent(con);

		rr = new RectangleRenderer(200, 70, sf::Color::White);
		addComponent(rr);

		//CircleCollider* cc = new CircleCollider(50, 0, 0);
		//addComponent(cc);

		RectangleCollider* rc = new RectangleCollider(200, 70);
		addComponent(rc);

		font.loadFromFile("./assets/fonts/Abalone.otf");
		Text* text = new Text(font, 15, "Start");
		text->setColor(sf::Color::Black);
		text->setPosition(-100, -35);
		addComponent(text);
	};
	void eventTick() {
		//RenderProperties::getWindow().getSize();
		//std::cout << (int)(ControlInput::getInstantiate().mousePosition().x ) << 
		//	" : " << (int)(ControlInput::getInstantiate().mousePosition().y ) << std::endl;
	}
	void mouseStartOverlapping(const Vector2& point) {
		rr->setColor(sf::Color::Color(200, 200, 200));
	}
	void mouseEndOverlapping() {
		rr->setColor(sf::Color::Color(255, 255, 255));
	}
	void onClick(const Vector2& mousePosition, short buttonClicked) {
		MapManager::getInstance().loadMap("map1");
		rr->setColor(sf::Color::Color(50, 50, 50));
	}

};

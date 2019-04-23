#include "GameObject002_Bullet.h"


void GameObject002_Bullet::beginPlay() {
	
	CircleRenderer* cRend = new CircleRenderer(15, sf::Color::Red);
	addComponent(cRend);

	destroy(5.0f);
}

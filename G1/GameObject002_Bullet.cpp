#include "GameObject002_Bullet.h"


void GameObject002_Bullet::beginPlay() {
	CircleRenderer* cRend = new CircleRenderer(30, sf::Color::Red);

	addComponent(cRend);
}

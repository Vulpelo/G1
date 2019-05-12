#include "CollisionDetection.h"

namespace G1 {

	CollisionDetection::CollisionDetection()
	{
		collisionTypes.push_back(new CircleCollidesCircle());
		collisionTypes.push_back(new CircleCollidesRectangle());
		collisionTypes.push_back(new RectangleCollidesRectangle());
	}

	void CollisionDetection::checkCollisions()
	{
		auto gameObjects = MapManager::get_aMap()->getAllObjects();

		for (unsigned int i = 0; i < gameObjects.size(); i++) {
			for (unsigned int j = i+1; j < gameObjects.size(); j++) {
				checkGameObjects(gameObjects.at(i), gameObjects.at(j));
			}
		}

	}

	void CollisionDetection::checkGameObjects(GameObject * gameObject1, GameObject * gameObject2)
	{
		auto components1 = gameObject1->getComponents<Collider>();
		auto components2 = gameObject2->getComponents<Collider>();

		for each (Collider* component1 in *components1)
		{
			if (component1->isEnabled()) {
				for each (Collider* component2 in *components2)
				{
					if (component2->isEnabled()) {
						if (areColliding(component1, component2) == CollisionCheck::COLLIDES) {

							// TODO: physics colision here

							gameObject1->addNewOverlapingObject(gameObject2);
							gameObject2->addNewOverlapingObject(gameObject1);

							return;
						}
					}
				}
			}
		}

	}

	CollisionCheck CollisionDetection::areColliding(Collider * collider1, Collider * collider2)
	{
		CollisionCheck check = CollisionCheck::WRONG_TYPE;
		for (unsigned int i = 0;
			i < collisionTypes.size() && check == CollisionCheck::WRONG_TYPE;
			i++)
		{
			check = collisionTypes.at(i)->checkCollision(collider1, collider2);
		}

		return check;
	}

	CollisionDetection::~CollisionDetection()
	{
	}

}

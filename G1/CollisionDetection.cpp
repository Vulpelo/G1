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

		for (int i = 0; i < gameObjects.size(); i++) {
			for (int j = i+1; j < gameObjects.size(); j++) {
				checkGameObjects(gameObjects.at(i), gameObjects.at(j));
			}
		}

	}

	void CollisionDetection::checkGameObjects(GameObject * gameObject1, GameObject * gameObject2)
	{
		auto components1 = gameObject1->getComponents();
		auto components2 = gameObject2->getComponents();

		Collider* collider1;
		Collider* collider2;

		for (int i = 0; i < components1.size(); i++) {
			
			if ( collider1 = dynamic_cast<Collider*>(components1.at(i)) ) {
				for (int j = 0; j < components2.size(); j++) {
				
					if (collider2 = dynamic_cast<Collider*>(components2.at(j))) {
						if (areColliding(collider1, collider2) == CollisionCheck::COLLIDES) {
							
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
		for (int i = 0;
			i < collisionTypes.size() && check == CollisionCheck::WRONG_TYPE;
			i++)
		{
			check = collisionTypes.at(i)->isColliding(collider1, collider2);
		}

		return check;
	}

	CollisionDetection::~CollisionDetection()
	{
	}

}

#include "CollisionDetection.h"

namespace G1 {

	std::vector<Overlapping*> CollisionDetection::collisionTypes = { 
		new CircleOverlapsCircle(),
		new CircleOverlapsRectangle(),
		new RectangleOverlapsRectangle()
	};


	CollisionDetection::CollisionDetection()
	{
		//collisionTypes.push_back(new CircleOverlapsCircle());
		//collisionTypes.push_back(new CircleOverlapsRectangle());
		//collisionTypes.push_back(new RectangleOverlapsRectangle());
	}

	void CollisionDetection::checkCollisions()
	{
		auto gameObjects = MapManager::getInstance().get_aMap().getAllObjects();

		for (unsigned int i = 0; i < gameObjects.size(); i++) {
			for (unsigned int j = i+1; j < gameObjects.size(); j++) {
				checkGameObjects(gameObjects.at(i), gameObjects.at(j));
			}
		}

	}

	void CollisionDetection::checkGameObjects(GameObject * gameObject1, GameObject * gameObject2)
	{
		if (gameObject1->getComponent<Rigidbody>() || gameObject2->getComponent<Rigidbody>()) {
			auto components1 = gameObject1->getComponents<Collider>();
			auto components2 = gameObject2->getComponents<Collider>();
			bool overlappingFunNotFired1 = true;
			bool overlappingFunNotFired2 = true;

			bool collisionNotCalculated = true;

			for each (Collider* collider1 in components1)
			{
				if (collider1->isEnabled()) {
					for each (Collider* collider2 in components2)
					{
						if (collider2->isEnabled()) {
							if (areColliding(collider1, collider2) == OverlappingCheck::OVERLAPPING) {

								if (overlappingFunNotFired1 && collider1->isOverlappable()) {
									overlappingFunNotFired1 = false;
									gameObject1->addNewOverlapingObject(gameObject2);
								}
								if (overlappingFunNotFired2 && collider2->isOverlappable()) {
									overlappingFunNotFired2 = false;
									gameObject2->addNewOverlapingObject(gameObject1);
								}

								if (collisionNotCalculated && !collider1->isOverlappable() && !collider2->isOverlappable()) {
									collisionCallculation.doCalculation(collider1, collider2);
									gameObject1->isColliding(gameObject2);
									gameObject2->isColliding(gameObject1);
									collisionNotCalculated = false;
								}

							}
						}
					}
				}
			}
		}
	}

	OverlappingCheck CollisionDetection::areColliding(Collider * collider1, Collider * collider2)
	{
		OverlappingCheck check = OverlappingCheck::WRONG_TYPE;
		for (unsigned int i = 0;
			i < collisionTypes.size() && check == OverlappingCheck::WRONG_TYPE;
			i++)
		{
			check = collisionTypes.at(i)->checkCollision(collider1, collider2);
		}

		return check;
	}


}

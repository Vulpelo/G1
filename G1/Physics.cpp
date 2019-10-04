#include "Physics.h"

namespace G1 {



	std::vector<Collider*> Physics::circleOverlaps(const Vector2 & position, float radious, int layers)
	{
		std::vector<Collider*> overlapedColliders;


		std::vector<GameObject*> gameObjects = MapManager::get_aMap()->getAllObjects();

		CircleCollider circleCollider(radious, position.x, position.y);

		for each (GameObject* gameObject in gameObjects)
		{
			if (gameObject->inLayer(layers)) {
				auto colliders = gameObject->getComponents<Collider>();
				for each (Collider* collider in colliders)
				{
					if (CollisionDetection::areColliding(collider, &circleCollider)) {
						overlapedColliders.push_back(collider);
					}
				}
			}
		}

		return overlapedColliders;
	}

}

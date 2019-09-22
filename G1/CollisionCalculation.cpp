#include "CollisionCalculation.h"

namespace G1 {

	CollisionCalculation::CollisionCalculation()
	{
		collisionTypes.push_back(new CircleCollidesCircle());
		collisionTypes.push_back(new RectangleCollidesRectangle());
		collisionTypes.push_back(new CircleCollidesRectangle());
	}

	void CollisionCalculation::doCalculation(Collider* collider1, Collider* collider2)
	{
		for each (Collision* col in collisionTypes)
		{
			if (col->calculate(collider1, collider2) != CollisionCheck::ERROR_TYPE) {
				return;
			}
		}
	}


	CollisionCalculation::~CollisionCalculation()
	{
	}

}

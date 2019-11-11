#include "CollisionCalculation.h"

namespace G1 {

	CollisionCalculation::CollisionCalculation()
	{
		collisionTypes.push_back(new G1::Resolution::CircleCollidesCircle());
		collisionTypes.push_back(new G1::Resolution::RectangleCollidesRectangle());
		collisionTypes.push_back(new G1::Resolution::CircleCollidesRectangle());
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
		for (int i = 0; i < collisionTypes.size(); i++) {
			delete collisionTypes[i];
		}
	}

}

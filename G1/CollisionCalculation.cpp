#include "CollisionCalculation.h"

namespace G1 {

	CollisionCalculation::CollisionCalculation()
	{
		collisionTypes.push_back(new G1::PositionPerfect::CircleCollidesCircle());
		collisionTypes.push_back(new G1::PositionPerfect::RectangleCollidesRectangle());
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
		for (size_t i = 0; i < collisionTypes.size(); i++) {
			delete collisionTypes[i];
		}
	}

}

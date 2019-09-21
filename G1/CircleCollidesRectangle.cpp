#include "CircleCollidesRectangle.h"

namespace G1 {


	CollisionCheck G1::CircleCollidesRectangle::calculate(Collider * collider1, Collider * collider2)
	{
		RectangleCollider* col1 = dynamic_cast<RectangleCollider*>(collider1);
		CircleCollider* col2 = dynamic_cast<CircleCollider*>(collider2);

		if (col1 && col2) {

		}
		else {
			CircleCollider* col1 = dynamic_cast<CircleCollider*>(collider1);
			RectangleCollider* col2 = dynamic_cast<RectangleCollider*>(collider2);

		}


		return CollisionCheck::ERROR_TYPE;
	}

}

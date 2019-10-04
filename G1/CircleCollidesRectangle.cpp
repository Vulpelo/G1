#include "CircleCollidesRectangle.h"

namespace G1 {


	CollisionCheck CircleCollidesRectangle::calculate(Collider * collider1, Collider * collider2)
	{
		if (dynamic_cast<RectangleCollider*>(collider1) && dynamic_cast<CircleCollider*>(collider2) ||
			dynamic_cast<RectangleCollider*>(collider2) && dynamic_cast<CircleCollider*>(collider1)) 
		{
			auto g1 = ((GameObject*)(collider1->getParent()));
			auto g2 = ((GameObject*)collider2->getParent());
			// TODO: world Velocity
			auto rb1 = g1->getComponent<Rigidbody>();
			auto rb2 = g2->getComponent<Rigidbody>();

			// Dynamic x Dynamic
			if (rb1 && rb2) {
				collider1->getParent()->setPosition(
					oneNewColliderPosition(collider1, rb1->getVelocity(), collider2)
				);// TODO: get top parent?


				applyNewVelocity(*rb1, *collider1, *collider2, calculateVelocityDirection(g1, rb1, g2, NULL));
				applyNewVelocity(*rb2, *collider2, *collider1, calculateVelocityDirection(g2, rb2, g1, NULL));

				return CollisionCheck::CALCULATED;
			}

			// Dynamic x Static
			if (rb1 && !rb2) {

				collider1->getParent()->setPosition(
					oneNewColliderPosition(collider1, rb1->getVelocity(), collider2)
				);// TODO: get top parent?

				applyNewVelocity(*rb1, *collider1, *collider2, calculateVelocityDirection(g1, rb1, g2, NULL));
				return CollisionCheck::CALCULATED;
			}// Static x Dynamic
			else if (!rb1 && rb2) {
				collider2->getParent()->setPosition(
					oneNewColliderPosition(collider2, rb2->getVelocity(), collider1)
				);// TODO: get top parent?

				applyNewVelocity(*rb2, *collider2, *collider1, calculateVelocityDirection(g2, rb2, g1, NULL));
				return CollisionCheck::CALCULATED;
			}
		}
		return CollisionCheck::ERROR_TYPE;
	}

	Vector2 CircleCollidesRectangle::oneNewColliderPosition(Collider* dynamicCollider, Vector2 velocityDynamic, Collider * staticCollider) 
	{
		velocityFor = VelocityFor::RECTANGLE;
		Vector2 newPositon;
		{
			RectangleCollider* recDynCol = dynamic_cast<RectangleCollider*>(dynamicCollider);
			CircleCollider* cirStatCol = dynamic_cast<CircleCollider*>(staticCollider);

			if (recDynCol && cirStatCol) {
				RectangleCollider cirAsRecCollider = rectangleFromCircle(*cirStatCol);
				newPositon = rcr.oneNewColliderPosition(recDynCol, velocityDynamic, &cirAsRecCollider);
				return newPositon;
			}
		}

		{ // cirDyn x recStat
			CircleCollider* cirDynCol = dynamic_cast<CircleCollider*>(dynamicCollider);
			RectangleCollider* recStatCol = dynamic_cast<RectangleCollider*>(staticCollider);

			if (recStatCol && cirDynCol) {
				RectangleCollider cirAsRecCollider = rectangleFromCircle(*cirDynCol);
				newPositon = rcr.oneNewColliderPosition(&cirAsRecCollider, velocityDynamic, recStatCol);

				// Static collider boundry points
				Vector2 wPos = recStatCol->getWorldPosition();
				Vector2 p1 = wPos + recStatCol->getFarthestPointVector();
				Vector2 p2 = wPos + recStatCol->getFarthestPointVector().invertX();
				Vector2 p3 = wPos - recStatCol->getFarthestPointVector();
				Vector2 p4 = wPos + recStatCol->getFarthestPointVector().invertY();


				bool outSide = false;
				CircleCollider recApexAsCircle(cirDynCol->getRadious()/2, 0, 0);

				if (p1.y < newPositon.y) {
					if (p1.x < newPositon.x) {
						// 1 apex
						outSide = true;
						recApexAsCircle.setPosition(p1);
					}
					if (p2.x > newPositon.x) { 
						// 2 apex
						outSide = true;
						recApexAsCircle.setPosition(p2);
					}
				} 
				else if (p4.y > newPositon.y) {
					if (p2.x > newPositon.x) {
						// 3 apex
						outSide = true;
						recApexAsCircle.setPosition(p3);
					}
					if (p1.x < newPositon.x) {
						// 4 apex
						outSide = true;
						recApexAsCircle.setPosition(p4);
					}
				}

				// out of boundries for rectangle
				if (outSide) {
 					CircleCollider smallerCirDyn(*(const CircleCollider*) cirDynCol);
					
					smallerCirDyn.setRadious(smallerCirDyn.getRadious() / 2);

					CircleCollidesCircle ccc;
					velocityFor = VelocityFor::CIRCLE;
					return ccc.oneNewColliderPosition(&smallerCirDyn, velocityDynamic, &recApexAsCircle);
				}
			}
		}
		return newPositon;
	}

	RectangleCollider CircleCollidesRectangle::rectangleFromCircle(CircleCollider& circle) {
		float r = circle.getFarthestPoint();
		Vector2 pos = circle.getWorldPosition();
		return RectangleCollider(r * 2, r * 2, pos.x, pos.y);
	}

	Vector2 CircleCollidesRectangle::calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2) {
		// TODO: move setting outside
		Vector2 vec;
		switch (velocityFor)
		{
		case G1::CircleCollidesRectangle::VelocityFor::CIRCLE:
		{
			return cCc.calculateVelocityDirection(gameObject1, rigidbody1, gameObject2, NULL);
		} break;
		case G1::CircleCollidesRectangle::VelocityFor::RECTANGLE:
		{
			return rcr.calculateVelocityDirection(gameObject1, rigidbody1, NULL, NULL);
		} break;
		default:
			break;
		}
		return vec;
	}
}

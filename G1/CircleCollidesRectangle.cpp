#include "CircleCollidesRectangle.h"

namespace G1 {


	CollisionCheck CircleCollidesRectangle::calculate(Collider * collider1, Collider * collider2)
	{
		if (dynamic_cast<RectangleCollider*>(collider1) && dynamic_cast<CircleCollider*>(collider2) ||
			dynamic_cast<RectangleCollider*>(collider2) && dynamic_cast<CircleCollider*>(collider1)) 
		{
			startCalculating(collider1, collider2);
			return CollisionCheck::CALCULATED;
		}
		return CollisionCheck::ERROR_TYPE;
	}

	Vector2 CircleCollidesRectangle::oneNewColliderPosition(Collider* dynamicCollider, const Vector2& velocityDynamic, Collider * staticCollider) 
	{
		velocityFor = VelocityFor::RECTANGLE;

		Vector2 posAddForTopParent = dynamicCollider->getTopParent().getWorldPosition() - dynamicCollider->getWorldPosition();

		Vector2 newPositon;
		{ // TODO: cirStat x recDyn
			RectangleCollider* recDynCol = dynamic_cast<RectangleCollider*>(dynamicCollider);
			CircleCollider* cirStatCol = dynamic_cast<CircleCollider*>(staticCollider);

			if (recDynCol && cirStatCol) {
				RectangleCollider cirAsRecCollider = rectangleFromCircle(*cirStatCol);
				newPositon = rcr.oneNewColliderPosition(recDynCol, velocityDynamic, &cirAsRecCollider);
				return newPositon + posAddForTopParent;
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
				Segment segment;

				if (p1.y < newPositon.y) {
					if (p1.x < newPositon.x) {
						// 1 apex
						outSide = true;
						segment.setPoint1(p1);
					}
					if (p2.x > newPositon.x) { 
						// 2 apex
						outSide = true;
						segment.setPoint1(p2);
					}
				} 
				else if (p4.y > newPositon.y) {
					if (p2.x > newPositon.x) {
						// 3 apex
						outSide = true;
						segment.setPoint1(p3);
					}
					if (p1.x < newPositon.x) {
						// 4 apex
						outSide = true;
						segment.setPoint1(p4);
					}
				}

				// out of boundries for rectangle
				if (outSide) {

					Vector2 velRealMoved = velocityDynamic*Time::getDeltaTime();
					Vector2 worldPositionDyn = dynamicCollider->getWorldPosition();
					segment.setPoint2(segment.getPoint1() - velocityDynamic);
					// TODO: Circle position on rectangle apex
					
					Vector2 c = GMath::orthogonalProjectionPointOnLine(worldPositionDyn, segment);

					float x = dynamicCollider->getFarthestPoint() * dynamicCollider->getFarthestPoint() -
						(worldPositionDyn - c).lengthNoSqrt();

					Vector2 moveJ = (segment.getPoint1() - c).normalize();

					float distance = sqrtf(x) - (segment.getPoint1() - c).length();
					Vector2 move = moveJ * distance;

					newPositon = worldPositionDyn - move;

					velocityFor = VelocityFor::CIRCLE;
					touchedApex = segment.getPoint1();
					circlePosition = cirDynCol->getWorldPosition();
					// TODO: why '+ posAddForTopParent' ?
					return newPositon;
				}
			}
		}
		return newPositon + posAddForTopParent;
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
			Vector2 Vsoj = (touchedApex - circlePosition).normalize();
			Vector2 Vso = Vsoj * (rigidbody1->getVelocity() * Vsoj);
			Vector2 newM = rigidbody1->getVelocity() - (Vso * 2);
			return rigidbody1->getVelocity() - (Vso * 2);
			//return cCc.calculateVelocityDirection(gameObject1, rigidbody1, gameObject2, NULL);
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

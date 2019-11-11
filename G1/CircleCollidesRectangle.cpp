#include "CircleCollidesRectangle.h"

namespace G1 {
	namespace PositionPerfect {

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
			{ // cirStat x recDyn
				RectangleCollider* recDynCol = dynamic_cast<RectangleCollider*>(dynamicCollider);
				CircleCollider* cirStatCol = dynamic_cast<CircleCollider*>(staticCollider);

				// TODO: Rectangle dynamic x circle static. Rectangle moves quickly to side of rectangle instead staying on apex. But sometimes stays on apex. Propably wrong new velocityDirection is calculated
				if (recDynCol && cirStatCol) {
					return oneNewColliderPositionCalc(recDynCol, cirStatCol, velocityDynamic, true);
				}
			}

			{ // cirDyn x recStat
				CircleCollider* cirDynCol = dynamic_cast<CircleCollider*>(dynamicCollider);
				RectangleCollider* recStatCol = dynamic_cast<RectangleCollider*>(staticCollider);

				// TODO: when low speed of circle on apex, then new position jumps to side of rectangle, rather than staing colliding on apex
				if (recStatCol && cirDynCol) {
					return oneNewColliderPositionCalc(recStatCol, cirDynCol, velocityDynamic, false);
				}
			}
			return newPositon + posAddForTopParent;
		}

		Vector2 CircleCollidesRectangle::oneNewColliderPositionCalc(RectangleCollider* rect, CircleCollider* cirl, const Vector2& velocityDynamic, bool firstColiderDynamic) {
			Vector2 newPositon;
			Vector2 worldPositionDyn = cirl->getWorldPosition();
			Vector2 cirlPosition = cirl->getWorldPosition();

			// Static collider boundry points
			Vector2 wPos = rect->getWorldPosition();
			Vector2 p1 = wPos + rect->getFarthestPointVector();
			Vector2 p2 = wPos + rect->getFarthestPointVector().invertX();
			Vector2 p3 = wPos - rect->getFarthestPointVector();
			Vector2 p4 = wPos + rect->getFarthestPointVector().invertY();

			RectangleCollider cirAsRecCollider = rectangleFromCircle(*cirl);
			if (firstColiderDynamic) {
				newPositon = rcr.oneNewColliderPosition(rect, velocityDynamic, &cirAsRecCollider);
				worldPositionDyn = rect->getWorldPosition();
			}
			else {
				newPositon = rcr.oneNewColliderPosition(&cirAsRecCollider, velocityDynamic, rect);
				cirlPosition = newPositon;
			}

			bool outSide = false;
			Segment segment;

			if (p1.y < cirlPosition.y) {
				if (p1.x < cirlPosition.x) {
					// 1 apex
					outSide = true;
					segment.setPoint1(p1);
				}
				if (p2.x > cirlPosition.x) {
					// 2 apex
					outSide = true;
					segment.setPoint1(p2);
				}
			}
			else if (p4.y > cirlPosition.y) {
				if (p2.x > cirlPosition.x) {
					// 3 apex
					outSide = true;
					segment.setPoint1(p3);
				}
				if (p1.x < cirlPosition.x) {
					// 4 apex
					outSide = true;
					segment.setPoint1(p4);
				}
			}

			// out of boundries for rectangle. Need more calculations
			if (outSide) {
				segment.setPoint2(segment.getPoint1() - velocityDynamic);
				Vector2 c = GMath::orthogonalProjectionPointOnLine(cirl->getWorldPosition(), segment);

				float x = cirl->getFarthestPoint() * cirl->getFarthestPoint() -
					(cirl->getWorldPosition() - c).lengthNoSqrt();

				Vector2 moveJ = (segment.getPoint1() - c).normalize();

				float distance = sqrtf(x) - (segment.getPoint1() - c).length();
				Vector2 move = moveJ * distance;

				newPositon = worldPositionDyn - move;

				velocityFor = VelocityFor::CIRCLE;
				touchedApex = segment.getPoint1();
				circlePosition = cirl->getWorldPosition();
			}
			// TODO: why '+ posAddForTopParent' ?

			// TODO : new position equals NaN
			//std::cout << "New Position:" << newPositon.x << ":" << newPositon.y;
			//std::cout << "\n";

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
			case G1::PositionPerfect::CircleCollidesRectangle::VelocityFor::CIRCLE:
			{
				Vector2 Vsoj = (touchedApex - circlePosition).normalize();
				Vector2 Vso = Vsoj * (rigidbody1->getVelocity() * Vsoj);
				Vector2 newM = rigidbody1->getVelocity() - (Vso * 2);
				return rigidbody1->getVelocity() - (Vso * 2);
				//return cCc.calculateVelocityDirection(gameObject1, rigidbody1, gameObject2, NULL);
			} break;
			case G1::PositionPerfect::CircleCollidesRectangle::VelocityFor::RECTANGLE:
			{
				return rcr.calculateVelocityDirection(gameObject1, rigidbody1, NULL, NULL);
			} break;
			default:
				break;
			}
			return vec;
		}
	}

	namespace Resolution {

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
			{ // cirStat x recDyn
				RectangleCollider* recDynCol = dynamic_cast<RectangleCollider*>(dynamicCollider);
				CircleCollider* cirStatCol = dynamic_cast<CircleCollider*>(staticCollider);

				// TODO: Rectangle dynamic x circle static. Rectangle moves quickly to side of rectangle instead staying on apex. But sometimes stays on apex. Propably wrong new velocityDirection is calculated
				if (recDynCol && cirStatCol) {
					return oneNewColliderPositionCalc(recDynCol, cirStatCol, velocityDynamic, true);
				}
			}

			{ // cirDyn x recStat
				CircleCollider* cirDynCol = dynamic_cast<CircleCollider*>(dynamicCollider);
				RectangleCollider* recStatCol = dynamic_cast<RectangleCollider*>(staticCollider);

				// TODO: when low speed of circle on apex, then new position jumps to side of rectangle, rather than staing colliding on apex
				if (recStatCol && cirDynCol) {
					return oneNewColliderPositionCalc(recStatCol, cirDynCol, velocityDynamic, false);
				}
			}
			return newPositon + posAddForTopParent;
		}

		Vector2 CircleCollidesRectangle::oneNewColliderPositionCalc(RectangleCollider* rect, CircleCollider* cirl, const Vector2& velocityDynamic, bool firstColiderDynamic) {
			Vector2 newPositon;
			Vector2 worldPositionDyn = cirl->getWorldPosition();
			Vector2 cirlPosition = cirl->getWorldPosition();

			// Static collider boundry points
			Vector2 wPos = rect->getWorldPosition();
			Vector2 p1 = wPos + rect->getFarthestPointVector();
			Vector2 p2 = wPos + rect->getFarthestPointVector().invertX();
			Vector2 p3 = wPos - rect->getFarthestPointVector();
			Vector2 p4 = wPos + rect->getFarthestPointVector().invertY();

			RectangleCollider cirAsRecCollider = rectangleFromCircle(*cirl);
			if (firstColiderDynamic) {
				newPositon = rcr.oneNewColliderPosition(rect, velocityDynamic, &cirAsRecCollider);
				worldPositionDyn = rect->getWorldPosition();
			}
			else {
				newPositon = rcr.oneNewColliderPosition(&cirAsRecCollider, velocityDynamic, rect);
				cirlPosition = newPositon;
			}

			bool outSide = false;
			Segment segment;
			Vector2 outApex;

			if (p1.y < cirlPosition.y) {
				if (p1.x < cirlPosition.x) {
					// 1 apex
					outSide = true;
					segment.setPoint1(p1);
					outApex = p1;
				}
				if (p2.x > cirlPosition.x) {
					// 2 apex
					outSide = true;
					segment.setPoint1(p2);
					outApex = p2;
				}
			}
			else if (p4.y > cirlPosition.y) {
				if (p2.x > cirlPosition.x) {
					// 3 apex
					outSide = true;
					segment.setPoint1(p3);
					outApex = p3;
				}
				if (p1.x < cirlPosition.x) {
					// 4 apex
					outSide = true;
					segment.setPoint1(p4);
					outApex = p4;
				}
			}

			// out of boundries for rectangle. Need more calculations
			if (outSide) {
				segment.setPoint2(segment.getPoint1() - velocityDynamic);
				Vector2 c = GMath::orthogonalProjectionPointOnLine(cirl->getWorldPosition(), segment);

				float x = cirl->getFarthestPoint() * cirl->getFarthestPoint() -
					(cirl->getWorldPosition() - c).lengthNoSqrt();

				Vector2 moveJ = (segment.getPoint1() - c).normalize();

				float distance = sqrtf(x) - (segment.getPoint1() - c).length();
				Vector2 move = moveJ * distance;

				//newPositon = worldPositionDyn - move;

				velocityFor = VelocityFor::CIRCLE;
				touchedApex = segment.getPoint1();
				circlePosition = cirl->getWorldPosition();
			}
			// TODO: why '+ posAddForTopParent' ?

			// TODO : new position equals NaN
			//std::cout << "New Position:" << newPositon.x << ":" << newPositon.y;
			//std::cout << "\n";

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
			case G1::Resolution::CircleCollidesRectangle::VelocityFor::CIRCLE:
			{
				Vector2 Vsoj = (touchedApex - circlePosition).normalize();
				Vector2 Vso = Vsoj * (rigidbody1->getVelocity() * Vsoj);
				Vector2 newM = rigidbody1->getVelocity() - (Vso * 2);
				return rigidbody1->getVelocity() - (Vso * 2);
				//return cCc.calculateVelocityDirection(gameObject1, rigidbody1, gameObject2, NULL);
			} break;
			case G1::Resolution::CircleCollidesRectangle::VelocityFor::RECTANGLE:
			{
				return rcr.calculateVelocityDirection(gameObject1, rigidbody1, NULL, NULL);
			} break;
			default:
				break;
			}
			return vec;
		}
	}
}

#include "RectangleCollidesRectangle.h"

namespace G1 {

	CollisionCheck RectangleCollidesRectangle::calculate(Collider * collider1, Collider * collider2)
	{
		if (dynamic_cast<RectangleCollider*>(collider1)  && 
			dynamic_cast<RectangleCollider*>(collider2)) 
		{
			startCalculating(collider1, collider2);
			return CollisionCheck::CALCULATED;
		}
		return CollisionCheck::ERROR_TYPE;
	}

	Vector2 RectangleCollidesRectangle::oneNewColliderPosition(Collider * rectangleColliderDynamic, const Vector2& velocityDynamic, Collider * rectangleColliderStatic)
	{
		Vector2 topParentColliderDynPosition = rectangleColliderDynamic->getTopParent().getWorldPosition();
		Vector2 rectangleColliderDynamicWorldPosition = rectangleColliderDynamic->getWorldPosition();

		Vector2 longVec = rectangleColliderDynamic->getFarthestPointVector() + rectangleColliderStatic->getFarthestPointVector();
		Vector2 staticColliderPos = rectangleColliderStatic->getWorldPosition();

		Vector2 p1 = longVec + staticColliderPos;
		Vector2 p2 = longVec.invertX() + staticColliderPos;
		Vector2 p3 = longVec.invert() + staticColliderPos;
		Vector2 p4 = longVec.invertY() + staticColliderPos;

		std::vector<Segment> segments = {
			Segment(p1, p2),
			Segment(p2, p3),
			Segment(p3, p4),
			Segment(p4, p1)
		};

		Segment dynamicColliderSegment = Segment(rectangleColliderDynamicWorldPosition,
			rectangleColliderDynamicWorldPosition - velocityDynamic);

		// getting quadrant to limit number of lines used in calculation of new position of the rectangle
		short quadrant = (rectangleColliderDynamic->getWorldPosition() - rectangleColliderStatic->getWorldPosition()).quadrant();

		Vector2 crossPoint = Vector2(FLT_MAX, FLT_MAX);
		Vector2 tmpCrossPoint;
		size_t segmentIndex;

		bool onlyParaller = true;


		std::cout << "<>";
		std::cout << "Vel:" << velocityDynamic.x << ":" << velocityDynamic.y;

		for (size_t i = static_cast<size_t>(quadrant + 2); i <= static_cast<size_t>(quadrant + 3); i++) {
			segmentIndex = i%segments.size();
			std::cout << "seg: " << segmentIndex;

			if (Segment::areParallel(dynamicColliderSegment, segments.at(segmentIndex))) {
				// TODO: temporary fix
				Segment rotatedDynamicColliderSegment;
				if (i % 2 == 0) {
					// horizontal paraller
					rotatedDynamicColliderSegment = Segment(rectangleColliderDynamicWorldPosition,
						rectangleColliderDynamicWorldPosition - Vector2::up());
				}
				else {
					// vertical paraller
					rotatedDynamicColliderSegment = Segment(rectangleColliderDynamicWorldPosition,
						rectangleColliderDynamicWorldPosition - Vector2::right());
				}
				std::cout << "parallel : ";
				tmpCrossPoint = Segment::crossPointOfLines(rotatedDynamicColliderSegment, segments.at(segmentIndex));
				if (!segments.at(segmentIndex).pointOnSegment(tmpCrossPoint)) {
					continue;
				}
			//	continue;
			}
			else {
				tmpCrossPoint = Segment::crossPointOfLines(dynamicColliderSegment, segments.at(segmentIndex));
			}

			std::cout << "Tmp:" <<  tmpCrossPoint.x << ":" << tmpCrossPoint.y;

			if ((tmpCrossPoint - dynamicColliderSegment.getPoint1()).lengthNoSqrt()
				<
				(crossPoint - dynamicColliderSegment.getPoint1()).lengthNoSqrt())
			{
				sideOfRectangle = SideOfRectangle(segmentIndex);
				crossPoint = tmpCrossPoint;
			}

			std::cout << " > CP:" << crossPoint.x << ":" << crossPoint.y;

			onlyParaller = false;
		}

		if (onlyParaller) {
			crossPoint = rectangleColliderDynamicWorldPosition;
		}

		std::cout << "\n";
			 
		return (crossPoint - rectangleColliderDynamicWorldPosition) + topParentColliderDynPosition;
	}

	Vector2 RectangleCollidesRectangle::calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2)
	{
		Vector2 vec;
		switch (sideOfRectangle)
		{
		case SideOfRectangle::Down: {
			// velocity allready pointing up, so dont change direction
			if (rigidbody1->getVelocity().y <= 0) {
				vec = rigidbody1->getVelocity();
			}
			else {
				vec = rigidbody1->getVelocity().invertY();
			}
		} break;
		case SideOfRectangle::Up: {
			if (rigidbody1->getVelocity().y >= 0) {
				vec = rigidbody1->getVelocity();
			}
			else {
				vec = rigidbody1->getVelocity().invertY();
			}
		} break;
		case SideOfRectangle::Right: {
			if (rigidbody1->getVelocity().x >= 0) {
				vec = rigidbody1->getVelocity();
			}
			else {
				vec = rigidbody1->getVelocity().invertX();
			}
		} break;
		case SideOfRectangle::Left: {
			if (rigidbody1->getVelocity().x <= 0) {
				vec = rigidbody1->getVelocity();
			}
			else {
				vec = rigidbody1->getVelocity().invertX();
			}
		} break;
		} 
		sideOfRectangle = SideOfRectangle::Undefined;
		return vec;
	}

	RectangleCollidesRectangle::~RectangleCollidesRectangle()
	{
	}

}

#include "RectangleCollidesRectangle.h"

namespace G1 {

	CollisionCheck RectangleCollidesRectangle::calculate(Collider * collider1, Collider * collider2)
	{
		RectangleCollider* col1 = dynamic_cast<RectangleCollider*>(collider1);
		RectangleCollider* col2 = dynamic_cast<RectangleCollider*>(collider2);

		if (col1 && col2) {
			auto g1 = ((GameObject*)(col1->getParent()));
			auto g2 = ((GameObject*)col2->getParent());
			// TODO: world Velocity
			auto rb1 = g1->getComponent<Rigidbody>();
			auto rb2 = g2->getComponent<Rigidbody>();

			// Dynamic x Dynamic
			if (rb1 && rb2) {
				col1->getParent()->setPosition(
					oneNewColliderPosition(col1, rb1->getVelocity(), col2)
				);// TODO: get top parent?

				calculateVelocityDirection(g1, rb1, NULL, NULL);
				calculateVelocityDirection(g2, rb2, NULL, NULL);

				return CollisionCheck::CALCULATED;
			}

			// Dynamic x Static
			if (rb1 && !rb2) {

				col1->getParent()->setPosition(
					oneNewColliderPosition(col1, rb1->getVelocity(), col2)
					);// TODO: get top parent?

				calculateVelocityDirection(g1, rb1, NULL, NULL);

				return CollisionCheck::CALCULATED;
			}// Static x Dynamic
			else if (!rb1 && rb2) {
				col2->getParent()->setPosition(
					oneNewColliderPosition(col2, rb2->getVelocity(), col1)
				);// TODO: get top parent?
				
				calculateVelocityDirection(g2, rb2, NULL, NULL);
				return CollisionCheck::CALCULATED;
			}
		}
		return CollisionCheck::ERROR_TYPE;
	}

	Vector2 RectangleCollidesRectangle::oneNewColliderPosition(RectangleCollider * rectangleColliderDynamic, Vector2 velocityDynamic, RectangleCollider * rectangleColliderStatic)
	{
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

		Segment dynamicColliderSegment = Segment(rectangleColliderDynamic->getWorldPosition(),
			rectangleColliderDynamic->getWorldPosition() - velocityDynamic);

		// getting quadrant to limit number of lines used in calculation of new position of the rectangle
		short quadrant = (rectangleColliderDynamic->getWorldPosition() - rectangleColliderStatic->getWorldPosition()).quadrant();

		Vector2 crossPoint = Vector2(FLT_MAX, FLT_MAX);
		Vector2 tmpCrossPoint;
		short segmentIndex;

		// for (int i = quadrant + 3; i <= quadrant + 5; i++) {
		for (int i = quadrant + 2; i <= quadrant + 3; i++) {
			segmentIndex = i%segments.size();
			tmpCrossPoint = Segment::crossPointOfLines(dynamicColliderSegment, segments.at(segmentIndex));

			std::cout << segmentIndex << ".";

			if ((tmpCrossPoint - dynamicColliderSegment.getPoint1()).lengthNoSqrt()
				<
				(crossPoint - dynamicColliderSegment.getPoint1()).lengthNoSqrt())
			{
				sideOfRectangle = SideOfRectangle(segmentIndex);
				crossPoint = tmpCrossPoint;
			}
		}
		return crossPoint;
	}

	void RectangleCollidesRectangle::calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2)
	{
		switch (sideOfRectangle)
		{
		case SideOfRectangle::Down:
		case SideOfRectangle::Up:
			rigidbody1->setVelocity(rigidbody1->getVelocity().invertY());
			break;
		case SideOfRectangle::Right:
		case SideOfRectangle::Left:
			rigidbody1->setVelocity(rigidbody1->getVelocity().invertX());
			break;
		} 
		sideOfRectangle = SideOfRectangle::Undefined;
	}

	RectangleCollidesRectangle::~RectangleCollidesRectangle()
	{
	}

}

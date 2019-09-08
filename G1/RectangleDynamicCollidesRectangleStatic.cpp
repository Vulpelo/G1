#include "RectangleDynamicCollidesRectangleStatic.h"

namespace G1 {
	void RectangleDynamicCollidesRectangleStatic::calculate(RectangleCollider * rectangleColliderDynamic, const Vector2& velocityDynamic, RectangleCollider * rectangleColliderStatic)
	{
		// TODO: Calculations for rotated rectangles 
		//		note: Calculations for Rectangles that ARENT rotated

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

		Segment dynamicColliderSegment = Segment( rectangleColliderDynamic->getWorldPosition(), 
				rectangleColliderDynamic->getWorldPosition() - velocityDynamic);

		// getting quadrant to limit number of lines used in calculation of new position of the rectangle
		short quadrant = (rectangleColliderDynamic->getWorldPosition() - rectangleColliderStatic->getWorldPosition()).quadrant();

		Vector2 crossPoint = Vector2(FLT_MAX, FLT_MAX);
		Vector2 tmpCrossPoint;
		short segmentIndex;

		for (int i = quadrant + 2; i <= quadrant + 3; i++) {
			segmentIndex = i%segments.size();
			tmpCrossPoint = Segment::crossPointOfLines(dynamicColliderSegment, segments.at(segmentIndex));

			if ((tmpCrossPoint - dynamicColliderSegment.getPoint1()).lengthNoSqrt()
				< 
				(crossPoint - dynamicColliderSegment.getPoint1()).lengthNoSqrt())
			{
				sideOfRectangle = SideOfRectangle(segmentIndex);
				crossPoint = tmpCrossPoint;
			}
		}
		/*std::cout << "CP>" << crossPoint.x << ":" << crossPoint.y << " VD>" << velocityDynamic.x << ":" << 
			velocityDynamic.y << " WP>" << rectangleColliderDynamic->getWorldPosition().x << ":" << 
			rectangleColliderDynamic->getWorldPosition().y << " q:" << quadrant << std::endl;*/
		rectangleColliderDynamic->getParent()->setPosition(crossPoint);
	}

}

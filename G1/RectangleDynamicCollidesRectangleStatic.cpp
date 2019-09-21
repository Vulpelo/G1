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
/*

		// rotated
		// TODO: When objects are rotated more than 90 degrees
		Vector2 farDynVec = rectangleColliderDynamic->getFarthestPointVector();
		Vector2 farStaVec = rectangleColliderStatic->getFarthestPointVector();

		float dynRot = rectangleColliderDynamic->getWorldRotation();
		float staRot = rectangleColliderStatic->getWorldRotation();

		float staLen = farStaVec.length();

		Vector2 statQ1; statQ1.setVectorByAngleAndLength(farStaVec.angle() + staRot, staLen);
		Vector2 statQ2; statQ2.setVectorByAngleAndLength(360 - farStaVec.angle() + staRot, staLen);

		farStaVec = farStaVec.invert();
		Vector2 statQ3; statQ3.setVectorByAngleAndLength(farStaVec.angle() + staRot, staLen);
		Vector2 statQ4; statQ4.setVectorByAngleAndLength(360 - farStaVec.angle() + staRot, staLen);


		float dynLen = farDynVec.length();

		Vector2 p18; p18.setVectorByAngleAndLength(farDynVec.angle() + dynRot, dynLen);
		p18 += staticColliderPos;
		Vector2 p23; p23.setVectorByAngleAndLength(360 - farDynVec.angle() + dynRot, dynLen);
		p23 += staticColliderPos;

		farDynVec = farDynVec.invert();
		Vector2 p67; p67.setVectorByAngleAndLength(farDynVec.angle() + dynRot, dynLen);
		p67 += staticColliderPos;
		Vector2 p45; p45.setVectorByAngleAndLength(360 - farDynVec.angle() + dynRot, dynLen);
		p45 += staticColliderPos;
		//

		std::vector<Segment> segments = {
			Segment(p18 + statQ1, p23 + statQ1), ///
			Segment(p23 + statQ1, p23 + statQ2), 
			Segment(p23 + statQ2, p45 + statQ2), ///
			Segment(p45 + statQ2, p45 + statQ3),
			Segment(p45 + statQ3, p67 + statQ3),///
			Segment(p67 + statQ3, p67 + statQ4),
			Segment(p67 + statQ4, p18 + statQ4),///
			Segment(p18 + statQ4, p18 + statQ1)
		};
		*/
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

		/*std::cout << "CP>" << crossPoint.x << ":" << crossPoint.y << " VD>" << velocityDynamic.x << ":" << 
			velocityDynamic.y << " DWP>" << rectangleColliderDynamic->getWorldPosition().x << ":" << 
			rectangleColliderDynamic->getWorldPosition().y << " q:" << quadrant << std::endl;*/
		
		rectangleColliderDynamic->getParent()->setPosition(crossPoint);// TODO: get top parent?
	}

}

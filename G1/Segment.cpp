#include "Segment.h"

namespace G1 {

	Segment::Segment(const Vector2 & point1, const Vector2 & point2) :
		point1(point1),
		point2(point2)
	{
		//this->point1 = point1;
		//this->point2 = point2;
	}

	bool Segment::areParallel(const Segment & segment1, const Segment & segment2) {
		float A = segment1.point1.y - segment1.point2.y;
		float A2 = segment2.point1.y - segment2.point2.y;
		float B = segment1.point2.x - segment1.point1.x;
		float B2 = segment2.point2.x - segment2.point1.x;

		return A*B2 == A2*B;
	}

	Vector2 Segment::crossPointOfLines(const Segment & segment1, const Segment & segment2)
	{
		// line going thru points of the dynamic collider
		float A = segment1.point1.y - segment1.point2.y;
		float B = segment1.point2.x - segment1.point1.x;
		float C = (segment1.point2.x * segment1.point1.y - segment1.point1.x * segment1.point2.y);

		float A2 = segment2.point1.y - segment2.point2.y;
		float B2 = segment2.point2.x - segment2.point1.x;
		float C2 = (segment2.point2.x * segment2.point1.y - segment2.point1.x * segment2.point2.y);

		return Vector2(-(C2*B - C*B2) / (A*B2 - A2*B),
					   -(A2*C - A*C2) / (A*B2 - A2*B));
	}
}

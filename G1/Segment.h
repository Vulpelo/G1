#pragma once

#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "Vector2.h"

namespace G1 {

	class Segment
	{
		Vector2 point1;
		Vector2 point2;

	public:
		Segment() {};
		Segment(const Vector2& point1, const Vector2& point2);
		Segment(const Segment& segment) { this->point1 = segment.point1; this->point2 = segment.point2; };

		const Vector2& getPoint1() const { return point1; }
		const Vector2& getPoint2() const { return point2; }

		void setPoint1(const Vector2& point) { point1 = point; }
		void setPoint2(const Vector2& point) { point2 = point; }

		/// <summary>
		/// Calculates cross point of two lines. First/Second line goes thru points of segment1/segment2.
		/// </summary>
		static Vector2 crossPointOfLines(const Segment& segment1, const Segment& segment2);
		static bool Segment::areParallel(const Segment & segment1, const Segment & segment2);
		bool pointOnSegment(const Vector2& point) const;

		/// <summary>
		/// point relative to line. 
		/// Returns number. If >0 then on one side of line, <0 other side, =0 on line (exacly on line)
		/// eg. p1(0.f, 0.f), p2(0.f, 10.f), point(5.f, 5.f) - then returns >0
		/// </summary>
		float pointRelativeLine(const Vector2& point) const;
	};

}

#endif // !_SEGMENT_H_

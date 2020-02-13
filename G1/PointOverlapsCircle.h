#pragma once

#ifndef _POINT_OVERLAPS_CIRCLE_H_
#define _POINT_OVERLAPS_CIRCLE_H_

#include "OverlapsPoint.h"
#include "CircleCollider.h"

class PointOverlapsCircle : public OverlapsPoint
{
public:
	OverlappingCheck overlaps(const Vector2& point, Collider* collider) {
		auto cCol = dynamic_cast<CircleCollider*>(collider);
		if (cCol) {
			if (cCol->getFarthestPoint() * cCol->getFarthestPoint() >= (point - cCol->getWorldPosition()).lengthNoSqrt()) {
				return OverlappingCheck::OVERLAPPING;
			}
			return OverlappingCheck::NOT_OVERLAPPING;
		}
		return OverlappingCheck::WRONG_TYPE;
	};
};


#endif // !_POINT_OVERLAPS_CIRCLE_H_

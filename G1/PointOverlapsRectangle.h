#pragma once

#ifndef _POINT_OVERLAPS_RECTANGLE_H_
#define _POINT_OVERLAPS_RECTANGLE_H_

#include "OverlapsPoint.h"
#include "RectangleCollider.h"

class PointOverlapsRectangle : public OverlapsPoint
{
public:
	OverlappingCheck overlaps(const Vector2& point, Collider* collider) {
		if (dynamic_cast<RectangleCollider*>(collider)) {
			Vector2 size = collider->getFarthestPointVector();
			Vector2 relPos = collider->getWorldPosition() - point;
			
			if (relPos.x <= size.x && -size.x <= relPos.x &&
				relPos.y <= size.y && -size.y <= relPos.y) 
			{
				return OverlappingCheck::OVERLAPPING;
			}
			return OverlappingCheck::NOT_OVERLAPPING;
		}
		return OverlappingCheck::WRONG_TYPE;
	}
};


#endif // !_POINT_OVERLAPS_RECTANGLE_H_

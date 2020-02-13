#pragma once

#ifndef _OVERLAPS_POINT_H_
#define _OVERLAPS_POINT_H_

#include "Collider.h"
#include "OverlappingCheck.h"

class OverlapsPoint {
public:
	virtual OverlappingCheck overlaps(const Vector2& point, Collider* collider) = 0;
};

#endif // !_OVERLAPS_POINT_H_

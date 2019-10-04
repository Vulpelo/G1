#pragma once

#include <vector>
#include "CollisionDetection.h"
#include "Collider.h"

namespace G1 {

	class Physics
	{
	public:
		/// <summary>
		/// Gets all colliders that circle overlaped and are belonging to one of given layers
		/// </summary>
		/// <param name="position"></param>
		/// <param name="radious"></param>
		/// <param name="layers"></param>
		/// <returns>List of all overlaping colliders</returns>
		static std::vector<Collider*> circleOverlaps(const Vector2& position, float radious, int layers = static_cast<int>(LayerGroups::ALL_LAYERS));
	};

}

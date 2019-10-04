#pragma once

#ifndef _COLLIDER_H_
#define _COLLIDER_H_

#include "MathFunctions.h"
#include "Component.h"

namespace G1 {

	enum class Combine {
		MINIMUM,
		AVERAGE,
		MULTIPLY,
		MAXIMUM
	};

	struct PhysicMaterial {
		float friction = 0.f;
		float bounciness = 0.f;

		Combine frictionCombine = Combine::AVERAGE;
		Combine bouncyCombine = Combine::MAXIMUM;
	};

	class Collider : public Component, public Transformable
	{
		bool overlappable;
		
		PhysicMaterial physicMaterial;

	protected:
		char collisionType;
		float farthestPoint;
		float nearestPoint;
		//not actually used
		void draw(sf::RenderWindow * w);
		bool rectangleOverlapsCircle(Collider*rect, Collider*cirl);
		bool rectangleOverlapsRectangle(Collider*rect, Collider*otherRect);
		bool rectangleOverlapsPoint(Vector2 point);

	public:
		Collider();
		char getCollisionType();
		virtual bool isCollidingWith(Collider *otherCollider) = 0;

		bool isOverlappable();
		void setOverlappable(bool overlappable);

		virtual Vector2 getFarthestPointVector();
		// returns distance from origin of colider to the farthest point on the colider
		float getFarthestPoint() const;
		// returns distance from origin of colider to the nearest point on the colider
		float getNearestPoint();

		/// <summary>Gets Transform of this object in relative to parent. Rotation is 0.0f if collider is not overlappable</summary>
		Transform getTransform();

		/// <summary>
		/// If not collider is not overlappable then returns 0.0f
		/// </summary>
		float getWorldRotation();

		void setPhysicMaterial(const PhysicMaterial& physicMaterial) { this->physicMaterial = physicMaterial; }
		const PhysicMaterial& getPhysicMaterial() const { return this->physicMaterial; }
	};

}

#endif // !_COLLIDER_H_

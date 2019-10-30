#pragma once

#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_

#include "Component.h"
#include "Time.h"

namespace G1 {

	class Rigidbody :
		public Component, public Transformable
	{
		Vector2 velocity;
		float drag = 0.0f;
		Vector2 gravity = Vector2(0.0, 100.0);
		float mass = 1.f;

	public:
		Rigidbody();
		~Rigidbody();

		void mainEventTick();

		Vector2 getVelocity() const;
		void setVelocity(Vector2 velocity);
		void addForce(Vector2 force);

		/// <summary>
		/// Returns drag that tells how much slower gameobject moves. 
		/// e.g how much less gravity effects gameobject. 1.f no gravity effect, 0.f normal gravity
		/// </summary>
		float getDrag() const { return drag; }
		/// <summary>
		/// Drag value should be between 0.f - 1.f
		/// </summary>
		void setDrag(float drag);

		/// <summary>
		/// Used when calculating collision of two dynamic gameobjects. 
		/// If mass is 0.f then it is ignored in calculations
		/// </summary>
		/// <returns></returns>
		float getMass() const { return mass; };
		float setMass(float mass) { this->mass = mass; };

		void setGravity(const Vector2& gravity) { this->gravity = gravity; }
		const Vector2& getGravity() const { return gravity; }
	};

}

#endif // !_RIGIDBODY_H_

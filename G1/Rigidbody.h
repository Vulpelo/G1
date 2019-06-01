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

	public:
		Rigidbody();
		~Rigidbody();
		void mainEventTick();
		void addForce(Vector2 force);
		Vector2 getVelocity();
		void setVelocity(Vector2 velocity);
	};

}

#endif // !_RIGIDBODY_H_

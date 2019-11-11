#pragma once

#ifndef _TRANSFORMABLE_H_
#define _TRANSFORMABLE_H_

#include "Transform.h"

namespace G1 {

	class Transformable {
	protected:
		Transformable* parent = NULL;
		Transform transform;

	public:
		Transformable() {}

		Transformable& getTopParent();

		Transformable* getParent() {return parent; };
		void setParent(Transformable* parent) { this->parent = parent; };

		void setPosition(float x, float y);
		void setPosition(const Vector2& position);

		/// <summary>
		/// Adds x and y to actual position.
		/// Moves object by additional given offset
		/// </summary>
		void move(float x, float y);
		void move(const Vector2& moveBy);

		/// <summary>Sets rotation of an object</summary>
		void setRotation(float x) { transform.rotationX = x; };
		void setScale(float x, float y) { transform.scale.x = x; transform.scale.y = y; }
		void setScale(const Vector2& scale) { transform.scale = scale; }

		/// <summary> Sets Transform of this object in relative to parent</summary>
		void setTransform(Transform transform) { this->transform = transform; };
		/// <summary> gets Transform of this object in relative to parent</summary>
		virtual Transform getTransform() { return this->transform; };

		/// <summary> Returns copy of world position of this object in world space</summary>
		Vector2 getWorldPosition();
		virtual float getWorldRotation();
		virtual Vector2 getWorldScale();
	};

}

#endif // !_TRANSFORMABLE_H_

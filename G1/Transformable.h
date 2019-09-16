#pragma once

#ifndef _TRANSFORMABLE_H_
#define _TRANSFORMABLE_H_

#include "Transform.h"

namespace G1 {

	class Transformable {
	protected:
		Transformable* parent;
		Transform transform;

	public:
		Transformable() {
			parent = NULL;
		}

		Transformable* getParent() {
			return parent;
		};

		void setParent(Transformable* parent) {
			this->parent = parent;
		};

		void setPosition(float, float);
		void setPosition(const Vector2& position);

		/// /// <summary> Returns copy of world position of this object in world space</summary>
		Vector2 getWorldPosition();

		/// <summary> Sets Transform of this object in relative to parent</summary>
		void setTransform(Transform transform);
		/// <summary> gets Transform of this object in relative to parent</summary>
		virtual Transform getTransform();

		virtual float getWorldRotation();
		/// <summary>Sets rotation of an object</summary>
		void setRotation(float x);
	};

}

#endif // !_TRANSFORMABLE_H_

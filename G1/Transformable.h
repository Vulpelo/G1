#pragma once

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
		/// <summary> Returns copy of world position of this object in world space</summary>
		Vector2 getWorldPosition();

		/// <summary> Sets Transform of this object in relative to parent</summary>
		void setTransform(Transform transform);
		/// <summary> gets Transform of this object in relative to parent</summary>
		Transform getTransform();

		float getWorldRotation();
		/// <summary>Sets rotation of an object</summary>
		void setRotation(float x);
	};

}

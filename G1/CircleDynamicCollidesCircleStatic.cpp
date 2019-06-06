#include "CircleDynamicCollidesCircleStatic.h"

namespace G1 {

	CircleDynamicCollidesCircleStatic::CircleDynamicCollidesCircleStatic()
	{
	}

	void CircleDynamicCollidesCircleStatic::calculate(CircleCollider* circleColliderDynamic, Vector2 velocityDynamic, CircleCollider* circleColliderStatic)
	{
		// there can be only one collider in gameobject tree hierarchy. Only First gameObect (with paret=null) can have collider
		// collider cant have offset.
		// get worldPosition of circleColliderDynamic as position
		Transform cirTran = circleColliderDynamic->getParent()->getTransform();

		Vector2 V1j = velocityDynamic.normalize(); // creating unitary vector
		
		// distance between centero of dynamic collider and cross point of straight perpendicular going thru center of static collider
		// to velocity vector
		float h = V1j * (circleColliderDynamic->getWorldPosition() - circleColliderStatic->getWorldPosition());

		Vector2 hv = V1j * h;

		Vector2 G1 = circleColliderDynamic->getWorldPosition() - hv;

		float d = circleColliderDynamic->getFarthestPoint() + circleColliderStatic->getFarthestPoint();

		float hh = (G1 - circleColliderStatic->getWorldPosition()).length();

		float b = d*d - hh*hh;
		float x = sqrtf( fabsf(b) );

		Vector2 S1 = (V1j * x - G1) * (-1);

		float rest = (circleColliderDynamic->getWorldPosition() - velocityDynamic - S1).length();

		// setting new position
		cirTran.position = S1;

		circleColliderDynamic->getParent()->setTransform(cirTran);
	}


	CircleDynamicCollidesCircleStatic::~CircleDynamicCollidesCircleStatic()
	{
	}

}

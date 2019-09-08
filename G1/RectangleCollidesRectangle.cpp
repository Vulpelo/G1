#include "RectangleCollidesRectangle.h"

namespace G1 {

	RectangleCollidesRectangle::RectangleCollidesRectangle()
	{
	}

	CollisionCheck RectangleCollidesRectangle::calculate(Collider * collider1, Collider * collider2)
	{
		RectangleCollider* col1 = dynamic_cast<RectangleCollider*>(collider1);
		RectangleCollider* col2 = dynamic_cast<RectangleCollider*>(collider2);

		if (col1 && col2) {
			auto g1 = ((GameObject*)(col1->getParent()));
			auto g2 = ((GameObject*)col2->getParent());
			// TODO: world Velocity
			auto rb1 = g1->getComponent<Rigidbody>();
			auto rb2 = g2->getComponent<Rigidbody>();

			// Dynamic x Dynamic
			if (rb1 && rb2) {
				//cirDynCirDyn.calculate(col1, rb1->getVelocity(), col2, rb2->getVelocity());
				return CollisionCheck::CALCULATED;
			}

			// Dynamic x Static
			if (rb1 && !rb2) {
				dynamicXStatic.calculate(col1, rb1->getVelocity(), col2);
				calculateVelocityDirection(g1, rb1, g2, NULL);
				return CollisionCheck::CALCULATED;
			}// Static x Dynamic
			else if (!rb1 && rb2) {
				dynamicXStatic.calculate(col2, rb2->getVelocity(), col1);
				calculateVelocityDirection(g2, rb2, g1, NULL);
				return CollisionCheck::CALCULATED;
			}
		}
		return CollisionCheck::ERROR_TYPE;
	}

	void RectangleCollidesRectangle::calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2)
	{
		switch (dynamicXStatic.sideOfRectangle)
		{
		case SideOfRectangle::Down:
		case SideOfRectangle::Up:
			rigidbody1->setVelocity(rigidbody1->getVelocity().invertY());
			break;
		case SideOfRectangle::Right:
		case SideOfRectangle::Left:
			rigidbody1->setVelocity(rigidbody1->getVelocity().invertX());
			break;
		} 
		dynamicXStatic.sideOfRectangle = SideOfRectangle::Undefined;
		//Vector2 Vsoj = (gameObject1->getWorldPosition() - gameObject2->getWorldPosition()).normalize();
		//Vector2 Vso = Vsoj * (rigidbody1->getVelocity() * Vsoj);
		//rigidbody1->setVelocity(rigidbody1->getVelocity() - (Vso * 2));
	}


	RectangleCollidesRectangle::~RectangleCollidesRectangle()
	{
	}

}

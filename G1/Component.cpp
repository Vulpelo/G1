#include "Component.h"

namespace G1 {

	Component::Component()
		: name("") {}

	Component::~Component()
	{
		newOverlapingComponents.clear();
		overlapingComponents.clear();
		//startOverlapingComp.clear();
		//isOverlapingComp.clear();
		//endOverlapingComp.clear();
		//delete collision;
	}

	//std::vector<Component*>& Component::getStartOverlapingComp()
	//{
	//	return startOverlapingComp;
	//}
	//
	//std::vector<Component*>& Component::getIsOverlapingComp()
	//{
	//	return isOverlapingComp;
	//}
	//
	//std::vector<Component*>& Component::getEndOverlapingComp()
	//{
	//	return endOverlapingComp;
	//}

	void Component::addOverlapComponent(Component * newComponent)
	{
		newOverlapingComponents.push_back(newComponent);
	}

	//Collision* Component::getCollider()
	//{
	//	return collision;
	//}

	//bool Component::collides(Collision *otherCollider)
	//{
	//	//if (collision != NULL) // is checked earlier
	//		return collision->isCollidingWith(otherCollider);
	//	//return false;
	//}



	//double Component::getXWorldPosition()
	//{ 
	//	if (localPositionX != 0 && localPositionY != 0)
	//	{
	//		double beginRotFromObject = GMath::vectorAngle(localPositionX, localPositionY);
	//
	//		double c = sqrt((localPositionX)*(localPositionX)
	//			+(localPositionY)*(localPositionY));
	//		double lPX = c * sin((transform.rotationX + beginRotFromObject)*M_PI / 180);
	//
	//		return transform.position.X + lPX;
	//	}
	//	return transform.position.X + localPositionX;
	//};
	//
	//double Component::getYWorldPosition()
	//{
	//	if (localPositionX != 0 && localPositionY != 0)
	//	{
	//		double beginRotFromObject = GMath::vectorAngle(localPositionX, localPositionY);
	//		double minuendOfRot;
	//		if (beginRotFromObject > 270)
	//			minuendOfRot = 450;
	//		else if (beginRotFromObject > 90)
	//			minuendOfRot = 270;
	//		else
	//			minuendOfRot = 90;
	//
	//		double c = sqrt((localPositionX)*(localPositionX)
	//			+(localPositionY)*(localPositionY));
	//		double lPX = c * sin((transform.rotationX + beginRotFromObject)*M_PI / 180);
	//
	//		double lPY = 0;
	//		if (transform.rotationX >= minuendOfRot - beginRotFromObject && transform.rotationX <= minuendOfRot + 180 - beginRotFromObject)
	//		{
	//			lPY = sqrt(c*c - lPX*lPX);
	//		}
	//		else
	//		{
	//			lPY = -sqrt(c*c - lPX*lPX);
	//		}
	//		if (minuendOfRot == 270)
	//			lPY = -lPY;
	//
	//		return -transform.position.Y + lPY;
	//	}
	//	return -transform.position.Y - localPositionY;
	//};


	void Component::setName(char* name)
	{
		this->name = name;
	}

	char* Component::getName() const
	{
		return name;
	}



	//void Component::overlapingEndMain()
	//{
	//	startOverlapingComp.clear();
	//	isOverlapingComp.clear();
	//	endOverlapingComp.clear();
	//
	//	for (int i = 0; i < overlapingComponents.size(); i++)
	//	{
	//		bool overlaping = false;
	//		int j = 0;
	//		for (j = 0; j < newOverlapingComponents.size(); j++)
	//		{
	//			if (overlapingComponents.at(i) == newOverlapingComponents.at(j))
	//			{
	//				//czyli isOverlaping
	//				overlaping = true;
	//				break;
	//			}
	//		}
	//
	//		if (overlaping == false)
	//		{
	//			endOverlapingComp.push_back(overlapingComponents.at(i));
	//			//obj->endOverlapingComponent(name, overlapingComponents.at(i));
	//			overlapingComponents.erase(overlapingComponents.begin() + i--);
	//		}
	//		else
	//		{
	//			isOverlapingComp.push_back(overlapingComponents.at(i));
	//			//obj->isOverlapingComponent(name, overlapingComponents.at(i));
	//			if (!newOverlapingComponents.empty())
	//				newOverlapingComponents.erase(newOverlapingComponents.begin() + j);
	//		}
	//	}
	//	for (int i = 0; i < newOverlapingComponents.size(); i++)
	//	{
	//		startOverlapingComp.push_back(newOverlapingComponents.at(i));
	//		//obj->startOverlapingComponent(name, newOverlapingComponents.at(i));
	//		overlapingComponents.push_back(newOverlapingComponents.at(i));
	//	}
	//	newOverlapingComponents.clear();
	//}

}

#include "OverlapingGameObjectsStates.h"

namespace G1 {

	void OverlapingGameObjectsStates::manageStatesAndFireFunctions()
	{
		auto gameObjects = MapManager::get_aMap()->getAllObjects();

		for each (GameObject* gameObject in gameObjects)
		{
			/*== Making events for Object ==*/
			std::vector<GameObject*>& ovObj = gameObject->getOverlapingObjects();
			std::vector<GameObject*>& nOvObj = gameObject->getNewOverlapingObjects();

			for (int i = 0; i < ovObj.size(); i++)
			{
				bool overlaping = false;
				int j = 0;
				for (j = 0; j < nOvObj.size(); j++)
				{
					if (ovObj.at(i) == nOvObj.at(j))
					{
						overlaping = true;
						break;
					}
				}

				if (overlaping == false)
				{
					gameObject->endOverlaping(ovObj.at(i));
					ovObj.erase(ovObj.begin() + i--);
				}
				else
				{
					gameObject->isOverlaping(ovObj.at(i));
					if (!nOvObj.empty())
						nOvObj.erase(nOvObj.begin() + j);
				}
			}
			for (int i = 0; i < nOvObj.size(); i++)
			{
				gameObject->startOverlaping(nOvObj.at(i));
				ovObj.push_back(nOvObj.at(i));
			}
			nOvObj.clear();
		}
	}

}

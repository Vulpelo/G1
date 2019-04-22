#pragma once

#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

#include "GameObject.h"

#include "GameObjectsData.h"
#include <vector>

#include <SFML\Graphics.hpp>

namespace G1 {

	class GameMap
	{
		//friend class PhysicsHandle;
	protected:
		std::vector <GameObject *> objects;
	public:
		GameMap();
		/// <summary> Return's a colection of Objects that where
		/// created in this GameMap </summary>
		std::vector <GameObject*> getAllObjects();
		void mainBeginPlay();
		void mainEventTick();
		virtual void eventTick(); //rdzen ustalany od postaci
		void setInput(ControlInput * input);
	};

}

#endif // !_GAME_MAP_H_

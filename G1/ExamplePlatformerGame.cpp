#include "ExamplePlatformerGame.h"

void ExamplePlatformerGame::beginPlay()
{
	MapManager::getInstance().loadMap( MapPlatformer01() );
}

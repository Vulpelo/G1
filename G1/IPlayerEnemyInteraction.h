#pragma once

class IPlayerEnemyInteraction {
public:
	virtual void takeDamage(int) = 0;
	virtual void bounce() = 0;
};

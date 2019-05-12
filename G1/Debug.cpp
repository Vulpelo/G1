#include "Debug.h"

using namespace std;

float Debug::waitTime = 500;
float Debug::target = clock() + Debug::waitTime;
bool Debug::block = false;
bool Debug::debugOn = false;

Debug::Debug()
{
}

void Debug::update()
{
	block = true;
	if (target <= clock()) {
		//system("cls");
		target = clock() + Debug::waitTime;
		block = false;
		printf("\n");
	}
}

void Debug::addText(const char *t)
{
	if (!block && debugOn)
		printf("%s", t);
		//printText += t;
}

void Debug::addText(int number)
{
	if (!block && debugOn)
		printf("%d", number);
		//printText += to_string(number);
}

void Debug::addText(const char * t, int number)
{
	if (!block && debugOn)
		printf("%s %i", t, number);
		//printText += t + to_string(number);
}

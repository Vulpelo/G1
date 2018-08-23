#include "Debug.h"

using namespace std;

float Debug::waitTime = 500;
clock_t Debug::target = clock() + Debug::waitTime;
bool Debug::block = false;

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
	if (!block)
		printf("%s", &t);
		//printText += t;
}

void Debug::addText(int number)
{
	if (!block)
		printf("%d", &number);
		//printText += to_string(number);
}

void Debug::addText(const char * t, int number)
{
	if (!block)
		printf("%s %i", t, number);
		//printText += t + to_string(number);
}


Debug::~Debug()
{
}

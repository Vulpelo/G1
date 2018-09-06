#pragma once

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <ctime>

class Debug
{
	static bool debugOn;
	static clock_t target;
	static float waitTime;
	static bool block;
public:
	Debug();
	static void update();
	static void addText(const char*);
	static void addText(int);
	static void addText(const char*, int);

	~Debug();
};

#endif // !DEBUG_H

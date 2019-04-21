#pragma once

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <ctime>

class Debug
{
	Debug();
	Debug(const Debug&);
	static bool debugOn;
	static float target;
	static float waitTime;
	static bool block;
public:
	static void update();
	static void addText(const char*);
	static void addText(int);
	static void addText(const char*, int);
};

#endif // !DEBUG_H

#pragma once

#include "Object.h"

struct Ray {
	Transform transform;
	Object* colidedObject;
};

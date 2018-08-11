#pragma once

#include "Mesh.h"
#include <vector>

class MeshesObject
{
protected:
	std::vector <Mesh*> meshes;
public:
	MeshesObject();
	~MeshesObject();
};


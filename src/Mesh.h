#pragma once
#include <iostream>
#include <vector>
#include "GL/glew.h"

using namespace std;

struct vertex
{
	vector<float> position; 
	vector<float> color;
};


class Mesh
{
private:
	vertex Vertex;

public:
	Mesh(vector<float> data, GLuint buffer);

	void setupMesh(GLuint buffer);


};


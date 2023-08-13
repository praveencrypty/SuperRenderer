#pragma once
#include <iostream>
#include <vector>
#include "GL/glew.h"

using namespace std;



	


class Mesh
{
private:
	vector<float> position;
	vector<float> color;

	vector<float> vertex;

public:
	Mesh(vector<float> pos, vector<float> col, GLuint buffer);

	void setupMesh(GLuint buffer);

	void drawMesh();
};


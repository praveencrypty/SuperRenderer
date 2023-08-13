#include "Mesh.h"

Mesh::Mesh(vector<float> pos, vector<float> col, GLuint buffer) : position(pos), color(col)
{

	vertex = {};
	vertex.insert(vertex.end(), position.begin(), position.end());
	vertex.insert(vertex.end(), color.begin(), color.end());


	for (int e = 0; e < vertex.size(); e++) {
		cout << vertex[e] << endl;
	}

	Mesh::setupMesh(buffer);
}

void Mesh::setupMesh(GLuint buffer)
{
	
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, (vertex.size())*sizeof(GL_FLOAT), vertex.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), 0);													//The First Variable in Vertex Shader
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)position.size());					//The Second Variable in Vertex Shader

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

}

void Mesh::drawMesh() {
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
 
 
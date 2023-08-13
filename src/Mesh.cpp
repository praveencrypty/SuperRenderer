#include "Mesh.h"

Mesh::Mesh(vector<float> data, GLuint buffer) : Vertex({ data })
{


	

	Mesh::setupMesh(buffer);
}

void Mesh::setupMesh(GLuint buffer)
{
	
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, (Vertex.position.size()+ Vertex.color.size())*sizeof(GL_FLOAT), &Vertex, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), 0);													//The First Variable in Vertex Shader
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)Vertex.position.size());					//The Second Variable in Vertex Shader

}


 
 
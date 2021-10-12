#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 36;
	triCount = 12;

	vertices = new Vertex[vertexCount];


	setVertexPosition(vertices, vertexCount, 0, { -0.5,  0.5, -0.5 });	//A
	setVertexPosition(vertices, vertexCount, 0, {  0.5,  0.5,  0.5 });	//B
	setVertexPosition(vertices, vertexCount, 0, {  0.5, -0.5, -0.5 });	//C
	setVertexPosition(vertices, vertexCount, 0, { -0.5, -0.5,  0.5 });	//D
	setVertexPosition(vertices, vertexCount, 0, {  0.5,  0.5, -0.5 });	//E
	setVertexPosition(vertices, vertexCount, 0, { -0.5,  0.5,  0.5 });	//F
	setVertexPosition(vertices, vertexCount, 0, { -0.5, -0.5, -0.5 });	//G
	setVertexPosition(vertices, vertexCount, 0, {  0.5, -0.5,  0.5 });	//H

	return vertices;
}

void Cube::setVertexPosition(Vertex* vertices, int vertexCount, int index, glm::vec3 position)
{
	for (int i = index; i < vertexCount; i += 8)
	{
		vertices[i].position = glm::vec4(position, 1.0f);
		vertices[i].normal = glm::vec4(position, 0.0f);
		vertices[i].color = m_color;
	}
}

#include "RabbitWorld.h"

void RabbitWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, 135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light
	m_light = new Light(
		{ -0.45f, 0.0f, 0.0f }, 
		{ 0.4f, 0.4f, 0.4f, 0.4f }, 
		{ 0.4f, 0.4f, 0.4f, 0.4f }, 
		{ 0.0f, 0.0f, 0.0f, 0.0f }
	);
	add(m_light);



	//Rabbit
	m_rabbit = new OBJMesh();
	m_rabbit->load("Bunny.obj");
	m_rabbit->getTransform()->setScale({ 0.1f, 0.1f, 0.1f });
	add(m_rabbit);

	//Cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.8f, 0.2f, 0.4, 1.0f));
	add(m_cube);
}

void RabbitWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_rabbit);
}
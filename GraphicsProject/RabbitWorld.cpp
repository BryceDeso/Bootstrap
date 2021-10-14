#include "RabbitWorld.h"

void RabbitWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light
	m_light = new Light(
		{ 1.0f, 1.0f, 1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	m_light->setDirection({ -40.0f, -100.0f, 0.0f });
	add(m_light);

	//Dragon
	m_rabbit = new OBJMesh();
	m_rabbit->load("Bunny.obj");
	m_rabbit->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f });
	m_rabbit->getTransform()->setScale(glm::vec3(0.2f));
	add(m_rabbit);

	//Cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.6f, 0.2f, 0.4f, 1.0f));
	add(m_cube);
}

void RabbitWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_rabbit);
	destroy(m_cube);
}

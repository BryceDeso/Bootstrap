#include "RabbitWorld.h"

void RabbitWorld :: onStart()
{
	//Initializing camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);

	setCamera(m_camera);
	add(m_camera);

	//Initializing first light
	m_light = new Light(
		{ 1.0f, 0.0f, 1.0f },
		{ 0.5f, 0.2f, 0.5f, 1.0f },
		{ 0.2f, 0.2f, 0.7f, 1.0f },
		{ 0.2f, 1.0f, 0.5f, 1.0f },
		0
	);
	m_light->setDirection({ -1.0f, -0.5f, -1.0f });
	add(m_light);

	//initalizing second light
	m_light2 = new Light(
		{ 0.2f, 0.4f, 0.1f },
		{ 0.7f, 0.2f, 0.4f, 1.0f },
		{ 0.9f, 0.2f, 0.2f, 1.0f },
		{ 0.2f, 0.7f, 0.1f, 1.0f },
		1
	);
	m_light2->setDirection({ 1.0f, 0.5f, 1.0f });
	add(m_light2);

	//Initalizing rabbit object
	m_rabbit = new OBJMesh();
	m_rabbit->load("Bunny.obj");
	m_rabbit->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f });
	m_rabbit->getTransform()->setScale(glm::vec3(0.2f));
	add(m_rabbit);

	//Initializing cube
	m_cube = new Cube();
	m_cube->setColor({ 0.5f,0.5f,0.5f,1.0f });
	m_cube->getTransform()->setPosition({ 3.0f, 0.0f, 0.0f });
	add(m_cube);

	//Ininitailizing texture plane
	m_plane = new TexturePlane("earth_diffuse.jpg", { 0.5f, 0.5f, 0.5f, 1.0f });
	add(m_plane);

}

void RabbitWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_light2);
	destroy(m_rabbit);
	destroy(m_cube);
}

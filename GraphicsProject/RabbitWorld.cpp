#include "RabbitWorld.h"

void RabbitWorld :: onStart()
{
	//camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);

	setCamera(m_camera);
	add(m_camera);

	//light
	m_light = new Light(
		0,
		{ 0.4f, 0.3f, 0.6f },
		{ 0.5f, 0.3f, 0.7f, 0.5f },
		{ 0.2f, 0.6f, 0.4, 0.5f },
		{ 0.0f, 0.0f, 0.0f, 0.0f }
	);
	m_light->setDirection({ -1.0f, -0.5f, -0.5f });
	add(m_light);

	m_light2 = new Light(
		1,
		{ 0.2f, 0.6f, 0.3f },
		{ 0.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 0.0f },
		{ 0.6f, 0.6f, 0.6f, 1.0f }
	);
	m_light2->setDirection({ -1.0f, -0.6f, -0.3f });
	add(m_light2);

	//dragon
	m_rabbit = new OBJMesh();
	m_rabbit->load("Bunny.obj");
	m_rabbit->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f });
	m_rabbit->getTransform()->setScale(glm::vec3(0.2f));
	add(m_rabbit);

	m_cube = new Cube();
	m_cube->setColor({ 0.5f,0.5f,0.5f,1.0f });
	m_cube->getTransform()->setPosition({ 3.0f, 0.0f, 0.0f });
	add(m_cube);

	m_map = new TexturePlane("earth_diffuse.jpg", { 0.25f, 0.25f, 0.25f, 1.0f });
	add(m_map);

}

void RabbitWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_light2);
	destroy(m_rabbit);
	destroy(m_cube);
}

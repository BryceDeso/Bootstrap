#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Cube.h"
#include "Quad.h"

class RabbitWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light = nullptr;
	Light* m_light2 = nullptr;
	OBJMesh* m_rabbit = nullptr;
	Cube* m_cube = nullptr;
	Quad* m_quad = nullptr;
};


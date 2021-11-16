#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "Cube.h"
#include "TexturePlane.h"
#include "OBJMesh.h"

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
	TexturePlane* m_plane = nullptr;
};
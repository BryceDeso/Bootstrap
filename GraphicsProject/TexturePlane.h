#pragma once
#include "Quad.h"
#include "Texture.h"

class TexturePlane : public Quad
{
public:
	TexturePlane() : m_fileName(" "), Quad() {}
	TexturePlane(const char* fileName, glm::vec4 color) : m_fileName(fileName), Quad(color) {}

	void onStart() override;
	void onDraw() override;

private:
	const char* m_fileName;
	aie::Texture m_texture;
};


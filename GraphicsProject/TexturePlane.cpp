#include "TexturePlane.h"
#include <gl_core_4_4.h>
#include "GLFW/glfw3.h"


void TexturePlane::onStart()
{
	Quad::onStart();
	if (!m_texture.load(m_fileName)) {
		printf("Failed to load texture");
	}
}

void TexturePlane::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("no shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, m_texture.getHandle());
	Quad::onDraw();
}

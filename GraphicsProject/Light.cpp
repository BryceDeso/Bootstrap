#include "Light.h"
#include "gl_core_4_4.h"
#include <string>

Light::Light(int term, glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
{
	m_term = term;
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;
}

void Light::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}

	std::string bound = ("iDirection" + std::to_string(m_term));
	int lightDirection = glGetUniformLocation(program, bound.c_str());
	bound = ("iAmbient" + std::to_string(m_term));
	int lightAmbient = glGetUniformLocation(program, bound.c_str());
	bound = ("iDiffuse" + std::to_string(m_term));
	int lightDiffuse = glGetUniformLocation(program, bound.c_str());
	bound = ("iSpecular" + std::to_string(m_term));
	int lightSpecular = glGetUniformLocation(program, bound.c_str());

	if (lightDirection >= 0) {
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection, direction.x, direction.y, direction.z);
	}
	if (lightAmbient >= 0) {
		glUniform3f(lightAmbient, m_ambient.x, m_ambient.y, m_ambient.z);
	}
	if (lightDiffuse >= 0) {
		glUniform3f(lightDiffuse, m_diffuse.x, m_diffuse.y, m_diffuse.z);
	}
	if (lightSpecular >= 0) {
		glUniform3f(lightSpecular, m_specular.x, m_specular.y, m_specular.z);
	}
}

glm::vec3 Light::getDirection()
{
	return getTransform()->getForward();
}

void Light::setDirection(glm::vec3 direction)
{
	getTransform()->setForward(direction);
}

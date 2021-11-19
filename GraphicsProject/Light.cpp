#include "Light.h"
#include "gl_core_4_4.h"
#include <string>

Light::Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, int lightType)
{
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;
	m_lightType = lightType;
}

void Light::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}

	int lightDirection = 0;
	int lightAmbient = 0;
	int lightDiffuse = 0;
	int lightSpecular = 0;

	//Checks if the light is of type 0 or 1 to determind which shader to use.
	if (m_lightType == 0)
	{
		std::string bound = ("iDirection");
		lightDirection = glGetUniformLocation(program, bound.c_str());
		bound = ("iAmbient");
		lightAmbient = glGetUniformLocation(program, bound.c_str());
		bound = ("iDiffuse");
		lightDiffuse = glGetUniformLocation(program, bound.c_str());
		bound = ("iSpecular");
		lightSpecular = glGetUniformLocation(program, bound.c_str());
	}
	else if (m_lightType == 1)
	{
		std::string bound = ("iDirection2");
		lightDirection = glGetUniformLocation(program, bound.c_str());
		bound = ("iAmbient2");
		lightAmbient = glGetUniformLocation(program, bound.c_str());
		bound = ("iDiffuse2");
		lightDiffuse = glGetUniformLocation(program, bound.c_str());
		bound = ("iSpecular2");
		lightSpecular = glGetUniformLocation(program, bound.c_str());
	}

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

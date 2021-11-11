#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;

in vec4 fPositionTwo;
in vec4 fNormalTwo;
in vec4 fColorTwo;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

uniform vec3 kAmbientTwo;
uniform vec3 kDiffuseTwo;
uniform vec3 kSpecularTwo;
uniform float kSpecularPowerTwo;

uniform vec3 iDirection;
uniform vec3 iAmbient;
uniform vec3 iDiffuse;
uniform vec3 iSpecular;

uniform vec3 iDirectionTwo;
uniform vec3 iAmbientTwo;
uniform vec3 iDiffuseTwo;
uniform vec3 iSpecularTwo;

uniform vec3 cameraPosition;

out vec4 pColor;

out vec4 pColorTwo;

void main() {
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal = normalize(iDirection);

	//Calculate ambient color
	vec3 ambientColor = (fColor.xyz + kAmbient) * iAmbient;

	//Calculate diffuse color
	float lambertTerm = dot(kNormal, -iNormal);
	lambertTerm = max(0.0f, min(1.0f, lambertTerm));
	vec3 diffuseColor = (fColor.xyz + kDiffuse) * iDiffuse * lambertTerm;

	//Calculate specular color
	vec3 surfaceToView = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal = reflect(iNormal, kNormal);
	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0.0f, specularTerm);
	specularTerm = pow(specularTerm, kSpecularPower);
	vec3 specularColor = (fColor.xyz + kSpecular) * iSpecular * specularTerm;

	pColor = vec4(ambientColor + diffuseColor + specularColor, 1.0f);
	


	vec3 kNormalTwo = normalize(fNormalTwo.xyz);
	vec3 iNormalTwo = normalize(iDirectionTwo);

	//Calculate ambient color
	vec3 ambientColorTwo = (fColorTwo.xyz + kAmbientTwo) * iAmbientTwo;

	//Calculate diffuse color
	float lambertTermTwo = dot(kNormalTwo, -iNormalTwo);
	lambertTermTwo = max(0.0f, min(1.0f, lambertTermTwo));
	vec3 diffuseColorTwo = (fColorTwo.xyz + kDiffuseTwo) * iDiffuseTwo * lambertTermTwo;

	//Calculate specular color
	vec3 surfaceToViewTwo = normalize(cameraPosition - fPositionTwo.xyz);
	vec3 reflectionNormalTwo = reflect(iNormalTwo, kNormalTwo);
	float specularTermTwo = dot(surfaceToViewTwo, reflectionNormalTwo);
	specularTermTwo = max(0.0f, specularTermTwo);
	specularTermTwo = pow(specularTermTwo, kSpecularPowerTwo);
	vec3 specularColorTwo = (fColorTwo.xyz + kSpecularTwo) * iSpecularTwo * specularTermTwo;

	pColorTwo = vec4(ambientColorTwo + diffuseColorTwo + specularColorTwo, 1.0f);

	//Snow
	//if (kNormal.y > 0.5f)
	//{
	//	vec4 red = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	//	pColor = red;
	//}
}

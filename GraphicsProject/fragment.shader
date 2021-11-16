#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;
in vec2 fTexCoord;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

uniform vec3 iDirection;
uniform vec3 iAmbient;
uniform vec3 iDiffuse;
uniform vec3 iSpecular;

uniform vec3 iDirection2;
uniform vec3 iAmbient2;
uniform vec3 iDiffuse2;
uniform vec3 iSpecular2;

uniform vec3 cameraPosition;
uniform sampler2D diffuseTexture;

out vec4 pColor;

void main() {
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal = normalize(iDirection);
	vec3 iNormal2 = normalize(iDirection2);

	//Light 1
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

	vec4 color = vec4(ambientColor + diffuseColor + specularColor, 1.0f);

	//Light 2
	//Calculate ambient color
	vec3 ambientColor2 = (fColor.xyz + kAmbient) * iAmbient2;

	//Calculate diffuse color
	float lambertTerm2 = dot(kNormal, -iNormal2);
	lambertTerm2 = max(0.0f, min(1.0f, lambertTerm2));
	vec3 diffuseColor2 = (fColor.xyz + kDiffuse) * iDiffuse2 * lambertTerm2;

	//Calculate specular color
	vec3 surfaceToView2 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal2 = reflect(iNormal2, kNormal);
	float specularTerm2 = dot(surfaceToView2, reflectionNormal2);
	specularTerm2 = max(0.0f, specularTerm2);
	specularTerm2 = pow(specularTerm2, kSpecularPower);
	vec3 specularColor2 = (fColor.xyz + kSpecular) * iSpecular2 * specularTerm2;

	vec4 color2 = vec4(ambientColor2 + diffuseColor2 + specularColor2, 1.0f);

	vec4 texColor = fColor * texture(diffuseTexture, fTexCoord);

	pColor = texColor + color + color2;
}

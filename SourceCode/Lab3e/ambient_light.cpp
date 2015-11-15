#include "ambient_light.h"

AmbientLight::AmbientLight()
{
}

AmbientLight::~AmbientLight()
{
}

void AmbientLight::Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation)
{
	// Setting up the ambient light array.
	GLfloat Light_Ambient[] = {0.4f, 0.4f, 0.4f, 1.0f};

	// Setting the light properties from the light values created above.
	glLightfv(GL_LIGHT3, GL_AMBIENT,  Light_Ambient);

	// Turn on this light.
	glEnable(GL_LIGHT3);
}
#include "directional_light.h"

DirectionalLight::DirectionalLight()
{
}

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation)
{
	// Setting up the diffuse light array.
	// This shows the colour of the light.
	GLfloat Light_Diffuse[] = {light_diffuse.getX(), light_diffuse.getY(), light_diffuse.getZ(), 1.0f};

	// Setting up the light position array.
	// This array is where the light will be placed in the scene.
	// Last value is 0.0f because it is directional and not a point/spot light.
	GLfloat Light_Position[] = {light_position.getX(), light_position.getY(), light_position.getZ(), 0.0f};

	// Setting the light properties from the light values created above.
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  Light_Diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Position);
	/*glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0f);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0f);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.5f);*/

	// Turn on this light.
	glEnable(GL_LIGHT0);
}
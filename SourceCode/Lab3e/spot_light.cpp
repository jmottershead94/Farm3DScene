#include "spot_light.h"

SpotLight::SpotLight()
{
}

SpotLight::~SpotLight()
{
}

void SpotLight::Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation)
{
	glRotatef(rotation.getX(), 0.0f, 1.0f, 0.0f);
	glRotatef(rotation.getY(), 1.0f, 0.0f, 0.0f);

	// Setting up the colour of the spot light.
	GLfloat Light_Diffuse[] = {light_diffuse.getX(), light_diffuse.getY(), light_diffuse.getZ(), 1.0f};
	
	// Setting up the position of the spot light.
	// Like point light, the last value is 1.0f.
	GLfloat Light_Position[] = {light_position.getX(), light_position.getY(), light_position.getZ(), 1.0f};
	
	light_bulb_.DrawTriangle(light_position, Vec2(1.0f, 1.0f), Vec2(0.0f, 0.0f), Vec2(0.0f, 0.0f));

	// This will determine the direction that the spot light is pointing in.
	// Negatively along the y axis in this instance, downwards.
	GLfloat Light_Direction[] = {0.0f, -1.0f, 0.0f};

	// Setting the light properties.
	glLightfv(GL_LIGHT2, GL_DIFFUSE,  Light_Diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, Light_Position);
	/*glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 2.0f);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 1.0f);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.5f);*/
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Light_Direction);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0f);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 50.0f);

	// Turn on this light.
	glEnable(GL_LIGHT2);
}
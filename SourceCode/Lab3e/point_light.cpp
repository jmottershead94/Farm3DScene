#include "point_light.h"

PointLight::PointLight()
{
}

PointLight::~PointLight()
{
}

void PointLight::Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation)
{
	glRotatef(rotation.getX(), 0.0f, 1.0f, 0.0f);
	glRotatef(rotation.getY(), 1.0f, 0.0f, 0.0f);

	// Setting up the color of the point light.
	GLfloat Light_Diffuse[] = {light_diffuse.getX(), light_diffuse.getY(), light_diffuse.getZ(), 1.0f};

	// Setting up the position of the point light.
	// Different from directional lighting.
	// Last value is 1.0f because it is a point light.
	GLfloat Light_Position[] = {light_position.getX(), light_position.getY(), light_position.getZ(), 1.0f};

	light_bulb_.DrawDisc(light_position, Vec2(1.0f, 1.0f), Vec2(0.0f, 0.0f), Vec2(1.0f, 1.0f), 20);
	
	// Setting the light properties from the light values created above.
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  Light_Diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position);

	// Turn on this light.
	glEnable(GL_LIGHT1);
}
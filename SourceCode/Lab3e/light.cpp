#include "light.h"

Light::Light()
{
	// Enable lighting features when a light is created.
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
}

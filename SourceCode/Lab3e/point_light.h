// Jason Mottershead, Student Number 1300455.

// PointLight class header file.
// This class will provide instances of point lights when I require them.
// Useful for lighting up a room, it can act like a bulb.
// I will use this to provide a point light that can be moved throughout the scene.

// Header guard.
#ifndef _POINTLIGHT_H_
#define _POINTLIGHT_H_

// Include files here.
#include "light.h"

// Point light IS A light, therefore it inherits from light.
class PointLight : public Light
{
	public:
		PointLight();
		~PointLight();

		// This function overrides the base light class init function.
		// This function will place the light in the scene with a specified colour and position.
		void Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation);
};

#endif
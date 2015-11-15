// Jason Mottershead, Student Number 1300455.

// SpotLight class header file.
// This class will provide instances of spot lights when I require them.

// Header guard.
#ifndef _SPOTLIGHT_H_
#define _SPOTLIGHT_H_

// Include files here.
#include "light.h"

// Spot light IS A light, therefore it inherits from light.
class SpotLight : public Light
{
	public:
		SpotLight();
		~SpotLight();

		// This function overrides the base light class init function.
		// This function will place the light in the scene with a specified colour and position.
		void Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation);
};

#endif
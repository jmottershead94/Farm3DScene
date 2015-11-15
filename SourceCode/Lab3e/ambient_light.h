// Jason Mottershead, Student Number 1300455.

// AmbientLight class header file.
// This class will provide an instance of the ambient light when I require it.
// This will be used to provide minimum light values for my scene.

// Header guard.
#ifndef _AMBIENT_LIGHT_H_
#define _AMBIENT_LIGHT_H_

// Include files here.
#include "light.h"

// Ambient light IS A light, therefore it inherits from light.
class AmbientLight : public Light
{
	public:
		// Methods.
		AmbientLight();
		~AmbientLight();

		// This function overrides the base light class init function.
		// This allows me to make each init for every derived light class unique to it's own light properties.
		// This function will place the light in the scene with a specified colour and position.
		void Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation);
};

#endif
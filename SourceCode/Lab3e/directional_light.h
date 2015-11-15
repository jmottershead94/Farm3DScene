// Jason Mottershead, Student Number 1300455.

// DirectionalLight class header file.
// This class will provide an instance of the directional light when I require it.
// This will be used to provide "Sunlight" for my scene.

// Header guard.
#ifndef _DIRECTIONAL_LIGHT_H_
#define _DIRECTIONAL_LIGHT_H_

// Include files here.
#include "light.h"

// Directional light IS A light, therefore it inherits from light.
class DirectionalLight : public Light
{
	public:
		// Methods.
		DirectionalLight();
		~DirectionalLight();

		// This function overrides the base light class init function.
		// This allows me to make each init for every derived light class unique to it's own light properties.
		// This function will place the light in the scene with a specified colour and position.
		void Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation);
};

#endif
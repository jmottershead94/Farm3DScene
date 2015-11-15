// Jason Mottershead, Student Number 1300455.

// Skybox class header file.
// This class provides the skybox for the scene.
// Might be used for creating another scene once the f key has been pressed.

// Header guard.
#ifndef _SKYBOX_H_
#define _SKYBOX_H_

// Include files here.
#include "Shape.h"

// Skybox IS A shape, therefore inherits from shape.
class Skybox : public Shape
{
	public:
		// Attributes.
		float rotation_;
		GLuint sky_box_;

		// Methods.
		Skybox();
		~Skybox();
		void Init(Vec3 position, Vec3 camera);
};

#endif
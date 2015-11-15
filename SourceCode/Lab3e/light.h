// Jason Mottershead, Student Number 1300455.

// Light class header file.
// This class is the base for all of the other light classes in the project.
// This class sets the functions that other lights MUST have.
// In this case not much other than an Init function for each derived class.

// Header guard.
#ifndef _LIGHT_H_
#define _LIGHT_H_

// Include files here.
#include <windows.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "vec2.h"
#include "vec3.h"
#include "shape.h"

class Light
{
	protected:
		Shape light_bulb_;

		// Methods.
		Light();

		// Virtual destructor.
		virtual ~Light() 
		{
		}

		// Pure virtual function.
		// Every light class derived from this class WILL have an Init function with these parameters.
		virtual void Init(Vec3 light_diffuse, Vec3 light_position, Vec3 rotation) = 0;
};

#endif
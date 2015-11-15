// Jason Motterhsead, Student Number 1300455.

// Field class header file.
// This will be the outside area.
// The buildings will be placed accordingly in this class.
// Shadows will come off of the buildings from directional light?

//////////////////////////////////////////////////////////////////////////
//			To do:														//
//				 - Place the buildings in the correct place.			//
//				 - Try creating shadows on the grass plane.				//
//				 - If there is spare time, place in trees and flowers.	//
//				 - Make a gap for a flowing river?						//
//////////////////////////////////////////////////////////////////////////

// Header guard.
#ifndef _FIELD_H_
#define _FIELD_H_

// Include files here.
#include "vec2.h"
#include "vec3.h"
#include "directional_light.h"
#include "point_light.h"
#include "spot_light.h"
#include "mesh.h"
#include "house.h"
#include "windmill.h"

// The field IS A mesh, therefore it inherits from mesh.
class Field : public Mesh
{
	public:
		// Attributes.
		Vec3 point_light_position_;
		Windmill windmill_;
		
		// Methods.
		Field();
		~Field();
		void Init();
		void Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, int recursive_number, bool draw_shadow);
		void DrawShadowMatrixScene(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, int recursive_number, bool draw_shadow);
		void GenerateShadowMatrix(float matrix[16], float light_pos[4], GLfloat v0[3], GLfloat v1[3], GLfloat v2[3]);

	private:
		// Attributes.
		float mshadowMatrix[16];
		GLuint grass_;
		DirectionalLight directional_light_;
		PointLight point_light_;
		House house_;		
};

#endif
// Jason Mottershead, Student Number 1300455.

// Mesh class header file.
// Creates the basis for all 3D objects in the world.
// This class creates 2D primitive/basic shapes.
// Collectively, these objects will build and create 3D objects.

// Header guard.
#ifndef _MESH_H_
#define _MESH_H_

// Include files here.
#include <windows.h>
#include <math.h>
#include <vector>
#include <gl/gl.h>
#include <gl/glu.h>
#include "SOIL.h"
#include "SOIL_old.h"
#include "vec2.h"
#include "vec3.h"

class Mesh
{
	public:
		// Attributes.
		GLuint my_texture_;

		// Methods.
		Mesh();
		~Mesh();

		// Pass in the texture filename to create the texture.
		GLuint TextureInit(const char* texture_filename);

		// Draw the triangle using the vector 3 class, stores x, y, and z position.
		// Vec2 stores the texture u and v coordinates.
		// The final Vec2 stores the texture width and height.
		// Segments means the amount of triangles to make up the disc/quad etc.
		void DrawTriangle(Vec3 position, Vec2 dimension, Vec2 texture_coordinates, Vec2 texture_dimension);
		void DrawDisc(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, int segments);
		void DrawQuad(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals);
		void DrawPlane(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, int recursive_number);

		// Methods.
		// This will bind a texture onto a mesh, so that textures can be applied to them.
		void BindTexture(GLuint& texture, GLenum pname_near, GLenum pname_far, GLint param_near, GLint param_far);

		// Getters.
		// This will return the position of the meshes.
		inline std::vector<Vec3> GetPosition() { return positions_; };

	protected:
		// Attributes.
		Vec3 origin_;
		std::vector<Vec3> positions_;

		//// Methods.
		//// This will bind a texture onto a mesh, so that textures can be applied to them.
		//void BindTexture(GLuint texture, GLenum pname_near, GLenum pname_far, GLint param_near, GLint param_far);

	//private:
		// Attributes.
		//GLuint my_texture_;
};

#endif
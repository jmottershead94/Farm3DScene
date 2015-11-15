// Jason Mottershead, Student Number 1300455.

// Shape class header file.
// Here is where most/all of the scene objects are created from.
// This class includes vertex arrays rendering.
// As well as a selection of 3D objects created through 2D meshes.

// Header guard.
#ifndef _SHAPE_H_
#define _SHAPE_H_

// Include files here.
#include "mesh.h"

// Shape IS A mesh, therefore shape inherits from mesh.
class Shape : public Mesh
{
	public:
		// Attributes.
		GLuint fabric_wallpaper_, window_, ladder_;

		// Methods.
		// These three render functions are different ways of rendering vertex arrays.
		void render1();
		void render2();
		void render3();

		// This will draw a sphere with a specified number of segments, the more segments, the more detail.
		void DrawSphere(int segments);

		// This will draw a dome (half a sphere) with a specified number of segments, the more segments, the more detail.
		void DrawDome(int segments);
		
		// This will draw a cylinder with a specified number of segments, the more segments, the more detail.
		void DrawCylinder(int segments);

		// This will draw a cube at the specified position.
		// With a specified width and height.
		// With a set of texture coordinates and dimensions.
		// This function will be used a lot in this application.
		void DrawCube(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, bool reflective);
		
		// This will draw a cube with holes in any of the faces.
		// This will be used for windows and doors.
		void DrawRoomCube(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, int recursions, bool reflective, bool has_front_door, bool has_leftside_door, bool has_back_door, bool has_rightside_door, bool has_front_window, bool has_left_window, bool has_back_window, bool has_right_window, bool has_upstairs_access, bool has_downstairs_access);
};

#endif 

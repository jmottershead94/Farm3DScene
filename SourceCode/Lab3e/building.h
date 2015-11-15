// Jason Mottershead, Student Number 1300455.

// Building class header file.
// This class will contain the basic data/functionality to create a building.
// This will include multiple rooms, which are represented by cubes.
// This will be used to create all of the big structures in my scene (House, Barn, Windmill).

// Header guard.
#ifndef _BUILDING_H_
#define _BUILDING_H_

// Include files here.
#include "room.h"

// Building IS A shape, therefore it inherits from shape.
class Building : public Shape
{
	public:
		// Attributes.
		GLuint building_dlist_, red_;

	protected:
		// Attributes.
		Vec2 dimensions_;

		// Methods.
		Building();
		~Building();

		// This will load in any textures that are used in this class.
		void Init();

		// This function will place a building at the specified position.
		// With the specified width and height.
		// Along with the texture coordinates and dimensions.
		// And finally, how many rooms/floors the building has.
		virtual void Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec2 interior);

		// This creates a roof for the building, two triangles, and two quads.
		void CreateRoof(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension);

	private:
		// Methods.
		// This creates a plain basic room inside of the building.
		virtual void CreateRoom(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension);

	
};

#endif
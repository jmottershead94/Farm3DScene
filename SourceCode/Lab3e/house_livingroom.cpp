#include "house_livingroom.h"

HouseLivingRoom::HouseLivingRoom()
{
}

HouseLivingRoom::~HouseLivingRoom()
{
}

void HouseLivingRoom::Init()
{
	// Initialising the textures.
	fabric_crosshatch_ = TextureInit("Converted_Textures/fabric_crosshatch.png");
	fabric_light_ = TextureInit("Converted_Textures/fabric_light.png");
	fabric_rough_carpet_ = TextureInit("Converted_Textures/fabric_rough_carpet.png");
	painting_brightfields_ = TextureInit("Converted_Textures/painting_brightfields.jpg");
	painting_farm_ = TextureInit("Converted_Textures/painting_farm.jpg");
	painting_trees_ = TextureInit("Converted_Textures/painting_trees.jpg");

	// Initialising the room.
	Room::Init();
}

void HouseLivingRoom::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, no_floor, false, false, true, true, true, true, false, false, false, false);
	
	// Insert room specific things here.
	// Inside of the room.
	glPushMatrix();
			
		// Places in a light shade.
		CreateLightShade(Vec3((dimension.getX() / 2.0f), -dimension.getY(), (-dimension.getX() / 2.0f)), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
		
		// To the floor.
		glPushMatrix();
			
			BindTexture(fabric_rough_carpet_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.125f, -dimension.getX());
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			DrawPlane(position, dimension, texture_coordinate, texture_dimension, Vec3(1.0f, 1.0f, 1.0f), 4);

		// Back to the living room.
		glPopMatrix();

		// Places in a couch.
		CreateCouch(Vec3(6.25f, 0.01f, -0.5f), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
	
		// Places in a lamp.
		CreateLamp(Vec3(11.25f, 0.0f, -1.0f), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
		
		// To the living room chairs.
		glPushMatrix();

			glTranslatef(4.25f, 0.01f, -6.0f);
			glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);

			// Places in the first chair.
			CreateChair(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glTranslatef(-1.5f, 0.0f, -4.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);

			// Places in the second chair.
			CreateChair(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the living room.
		glPopMatrix();

		// To the table.
		glPushMatrix();

			glTranslatef(6.5f, 0.01f, -6.0f);
			glScalef(1.0f, 0.75f, 0.25f);

			// Places in a table.
			CreateTable(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the living room.
		glPopMatrix();

		// To the room paintings.
		glPushMatrix();

			glTranslatef(2.0f, 4.0f, -13.5f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_brightfields.jpg");

			glTranslatef(8.5f, 0.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_farm.jpg");

			glTranslatef(0.975f, 0.0f, 3.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_trees.jpg");

		// Back to the living room.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}
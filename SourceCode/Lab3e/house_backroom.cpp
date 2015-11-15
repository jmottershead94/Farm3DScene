#include "house_backroom.h"

HouseBackroom::HouseBackroom()
{
}

HouseBackroom::~HouseBackroom()
{
}

void HouseBackroom::Init()
{
	// Initialising textures.
	fabric_crosshatch_ = TextureInit("Converted_Textures/fabric_crosshatch.png");
	fabric_rough_carpet_ = TextureInit("Converted_Textures/fabric_rough_carpet.png");
	painting_house_ = TextureInit("Converted_Textures/painting_house.jpg");
	painting_trees_ = TextureInit("Converted_Textures/painting_trees.jpg");

	// Initialising the room.
	Room::Init();
}

void HouseBackroom::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, no_floor, true, false, false, true, false, false, false, false, false, false);
	
	// Draw the rest of the room here.
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

		// Back to the back room.
		glPopMatrix();

		// To the table.
		glPushMatrix();

			glTranslatef((dimension.getX() / 2.0f) - 3.0f, 0.0f, (-dimension.getX() / 2.0f) + 1.0f);
			glScalef(1.25f, 0.875f, 0.375f);
			CreateTable(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the back room.
		glPopMatrix();

		// To the chairs.
		glPushMatrix();

			glTranslatef((dimension.getX() / 2.0f), 0.0f, (-dimension.getX() / 2.0f) + 1.375f);
			CreateChair(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
			glTranslatef(-2.0f, 0.0f, 0.0f);
			CreateChair(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
			glTranslatef(-1.75f, 0.0f, -2.5f);
			glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
			CreateChair(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(-3.0f, 0.0f, 1.0625f);
			CreateChair(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glTranslatef(-2.0f, 0.0f, 0.0f);
			CreateChair(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
		// Back to the back room.
		glPopMatrix();

		// To the paintings.
		glPushMatrix();

			glTranslatef(-1.0f, 6.0f, -6.5f);
			glScalef(1.5f, 1.5f, 1.5f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_house.jpg");

			glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef((dimension.getX() / 2.0f) - 1.0f, -1.0f, -5.0f);
			glScalef(1.5f, 1.0f, 1.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_trees.jpg");
			
		// Back to the back room.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

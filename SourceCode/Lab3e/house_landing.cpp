#include "house_landing.h"

HouseLanding::HouseLanding()
{
}

HouseLanding::~HouseLanding()
{
}

void HouseLanding::Init()
{
	// Initialising the textures.
	painting_farm_ = TextureInit("Converted_Textures/painting_farm.jpg");

	// Initialising the room.
	Room::Init();
}

void HouseLanding::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, true, false, true, true, false, true, false, false, true, false, true);
	
	// Draw the rest of the room here.
	// Inside of the room.
	glPushMatrix();

		// Places in a light shade.
		CreateLightShade(Vec3((dimension.getX() / 2.0f), -dimension.getY(), (-dimension.getX() / 2.0f)), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
		
		// Moving everything up to the second floor.
		glTranslatef(0.0f, (dimension.getY() / 8.0f), 0.0f);

		// To the table.
		glPushMatrix();

			glTranslatef(0.0f, -1.5f, (-dimension.getX() / 2.0f) - 3.0f);
			glScalef(0.5f, 0.75f, 0.375f);
			CreateTable(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
		// Back to the landing.
		glPopMatrix();

		// To the landing painting.
		glPushMatrix();

			glTranslatef(-1.5f, 2.0f, -10.5f);
			glScalef(1.5f, 1.5f, 1.5f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_farm.jpg");

		// Back to the landing.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

#include "house_bathroom.h"

HouseBathroom::HouseBathroom()
{
}

HouseBathroom::~HouseBathroom()
{
}

void HouseBathroom::Init()
{
	// Initialising the textures.
	floor_dark_diamonds_ = TextureInit("Converted_Textures/floor_dark_diamonds.png");
	marble_ = TextureInit("Converted_Textures/marble.png");
	wood_light_ = TextureInit("Converted_Textures/wood_light.png");

	// Initialising the room.
	Room::Init();
}

void HouseBathroom::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, no_floor, true, true, false, false, false, false, true, false, false, false);
	
	// Draw the rest of the room here.
	// Inside of the room.
	glPushMatrix();
	
		// Places in a light shade.
		CreateLightShade(Vec3((dimension.getX() / 2.0f), -dimension.getY(), (-dimension.getX() / 2.0f)), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
		
		// To the floor.
		glPushMatrix();
			
			BindTexture(floor_dark_diamonds_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.01f, -dimension.getX());
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			DrawPlane(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), 3);

		// Back to the bathroom.
		glPopMatrix();

		// Moving everything up to the second floor.
		glTranslatef(0.0f, (dimension.getY() / 8.0f), 0.0f);

		// To the bath tub.
		glPushMatrix();
			
			glTranslatef(8.0f, -1.5f, -10.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			CreateBathTub(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
		// Back to the bath room.
		glPopMatrix();

		// To the drawers.
		glPushMatrix();
			
			glTranslatef(11.0f, -1.5f, -6.0f);
			glScalef(1.0f, 1.25f, 1.0f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			CreateDrawers(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
		// Back to the bath room.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

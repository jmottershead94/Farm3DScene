#include "house_bedroom.h"

HouseBedroom::HouseBedroom()
{
}

HouseBedroom::~HouseBedroom()
{
}

void HouseBedroom::Init()
{
	// Initialising the textures.
	bed_covers_ = TextureInit("Converted_Textures/bed_covers.png");
	bed_sheets_ = TextureInit("Converted_Textures/bed_sheets.png");
	fabric_rough_carpet_ = TextureInit("Converted_Textures/fabric_rough_carpet.png");
	marble_ = TextureInit("Converted_Textures/marble.png");
	matress_cover_ = TextureInit("Converted_Textures/matress_cover.png");
	pillow_ = TextureInit("Converted_Textures/pillow.png");
	poster_batman_v_superman_ = TextureInit("Converted_Textures/poster_batman_v_superman.png");
	poster_breaking_bad_ = TextureInit("Converted_Textures/poster_breaking_bad.jpg");
	poster_the_walking_dead_ = TextureInit("Converted_Textures/poster_the_walking_dead.jpg");
	wood_light_ = TextureInit("Converted_Textures/wood_light.png");
	wooden_board_ = TextureInit("Converted_Textures/wooden_board.png");
	chocobo_.Load("Models/Chocobo/Chocobo.obj", "Models/Chocobo/0053_player14_tpltex00.png");

	// Initialising the room.
	Room::Init();
}

void HouseBedroom::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, no_floor, true, false, false, true, false, true, false, false, false, false);
	
	// Draw the rest of the room here.
	// Inside of the room.
	glPushMatrix();
		
		// Places in a light shade.
		CreateLightShade(Vec3((dimension.getX() / 2.0f), -dimension.getY(), (-dimension.getX() / 2.0f)), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
		
		// To the floor.
		glPushMatrix();
			
			BindTexture(fabric_rough_carpet_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.01f, -dimension.getX());
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			DrawPlane(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), 3);

		// Back to the bedroom.
		glPopMatrix();

		// Moving everything up to the second floor.
		glTranslatef(0.0f, (dimension.getY() / 8.0f), 0.0f);

		// To the bed.
		glPushMatrix();
			
			glTranslatef((dimension.getX() / 2.0f), -1.5f, -12.0f);
			glScalef(0.75f, 1.0f, 0.75f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			CreateBed(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, false);
			
			glTranslatef(-1.5f, 1.65f, -0.75f);
			glScalef(0.0078125f, -0.0078125f, 0.0078125f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			chocobo_.Render();

		// Back to the bed room.
		glPopMatrix();

		// To the table.
		glPushMatrix();

			glTranslatef(0.5f, -1.5f, (-dimension.getX() / 2.0f) - 2.0f);
			glScalef(0.5f, 0.5f, 0.375f);
			CreateTable(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the bed room.
		glPopMatrix();
				
		// To the lamp.
		glPushMatrix();
			
			glTranslatef(1.5f, -0.25f, (-dimension.getX() / 2.0f) - 3.25f);
			glScalef(0.25f, 0.25f, 0.25f);
			CreateLamp(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the bed room.
		glPopMatrix();

		// To the bed room posters.
		glPushMatrix();
			
			glTranslatef(2.0f, 2.0f, -13.75f);
			glScalef(1.25f, 1.5f, 1.5f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/poster_batman_v_superman.png");
			
			glTranslatef(3.0f, 0.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/poster_the_walking_dead.jpg");
			
			glTranslatef(3.0f, 0.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/poster_breaking_bad.jpg");
			
		// Back to the bed room.
		glPopMatrix();

		// To the drawers.
		glPushMatrix();

			glTranslatef(7.0f, -1.5f, -12.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			CreateDrawers(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
						
			glRotatef(-270.0f, 0.0f, 1.0f, 0.0f);

			glTranslatef(-4.0f, 0.0f, 11.875f);
			glScalef(2.0f, 1.0f, 1.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			CreateDrawers(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
		// Back to the bed room.
		glPopMatrix();
		
	// Back to the original scene.
	glPopMatrix();
}

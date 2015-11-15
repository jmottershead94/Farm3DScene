#include "house_masterbedroom.h"

HouseMasterBedroom::HouseMasterBedroom()
{
}

HouseMasterBedroom::~HouseMasterBedroom()
{
}

void HouseMasterBedroom::Init()
{
	// Initialising the textures.
	bed_covers_ = TextureInit("Converted_Textures/bed_covers.png");
	bed_sheets_ = TextureInit("Converted_Textures/bed_sheets.png");
	fabric_rough_carpet_ = TextureInit("Converted_Textures/fabric_rough_carpet.png");
	marble_ = TextureInit("Converted_Textures/marble.png");
	matress_cover_ = TextureInit("Converted_Textures/matress_cover.png");
	painting_trees_ = TextureInit("Converted_Textures/painting_trees.jpg");
	pillow_ = TextureInit("Converted_Textures/pillow.png");
	wood_light_ = TextureInit("Converted_Textures/wood_light.png");
	wooden_board_ = TextureInit("Converted_Textures/wooden_board.png");

	// Initialising the room.
	Room::Init();
}

void HouseMasterBedroom::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, no_floor, false, false, true, true, true, false, false, false, false, false);
	
	// Draw the rest of the room here.
	glPushMatrix();
		
		// Places in a light shade.
		CreateLightShade(Vec3((dimension.getX() / 2.0f), -dimension.getY(), (-dimension.getX() / 2.0f)), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
		
		// To the floor.
		glPushMatrix();
			
			BindTexture(fabric_rough_carpet_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.01f, -dimension.getX());
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			DrawPlane(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), 3);

		// Back to the master bedroom.
		glPopMatrix();

		// Moving everything up to the second floor.
		glTranslatef(0.0f, (dimension.getY() / 8.0f), 0.0f);

		// To the double bed.
		glPushMatrix();
			
			glTranslatef((dimension.getX() / 2.0f) - 3.0f, -1.5f, -0.25f);
			glScalef(0.5f, 1.0f, 0.75f);
			CreateBed(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, true);
			
		// Back to the master bed room.
		glPopMatrix();
		
		// To the tables.
		glPushMatrix();
			
			glTranslatef(0.5f, -1.5f, -0.5f);
			glScalef(0.5f, 0.5f, 0.25f);
			CreateTable(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
			glTranslatef(14.0f, 0.0f, 0.0f);
			CreateTable(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the master bed room.
		glPopMatrix();

		// To the lamps.
		glPushMatrix();
			
			glTranslatef(1.5f, -0.25f, -1.0f);
			glScalef(0.25f, 0.25f, 0.25f);
			CreateLamp(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
			glTranslatef(28.0f, 0.0f, 0.0f);
			CreateLamp(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
		// Back to the master bed room.
		glPopMatrix();

		// To the painting.
		glPushMatrix();
			
			glTranslatef(-1.5f, 2.5f, -6.5f);
			glScalef(2.0f, 1.0f, 2.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_trees.jpg");
			
		// Back to the master bed room.
		glPopMatrix();

		// To the drawers.
		glPushMatrix();
			
			glTranslatef(0.25f, -1.5f, -12.0f);
			glScalef(2.0f, 1.5f, 1.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			CreateDrawers(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
			glTranslatef(0.0f, 0.0f, -1.0f);
			CreateDrawers(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
			
		// Back to the master bed room.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

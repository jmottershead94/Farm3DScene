#include "house_kitchen.h"

HouseKitchen::HouseKitchen()
{
}

HouseKitchen::~HouseKitchen()
{
}

void HouseKitchen::Init()
{
	// Initialising the textures that the kitchen needs.
	floor_dark_diamonds_ = TextureInit("Converted_Textures/floor_dark_diamonds.png");
	marble_ = TextureInit("Converted_Textures/marble.png");
	wood_light_ = TextureInit("Converted_Textures/wood_light.png");

	// Loading in the teapot model.
	teapot_.Load("Models/teapot.obj", "Converted_Textures/white.png");
	
	// Initialising the textures that are used in all rooms.
	Room::Init();
}

void HouseKitchen::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, no_floor, true, true, false, false, false, false, false, false, false, false);
	
	// Draw the rest of the room here.
	// Inside of the room.
	glPushMatrix();
		
		// Creating the stencil before we create the scene.
		glEnable(GL_STENCIL_TEST);
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
		glStencilFunc(GL_ALWAYS, 1, 1);

		//// We aren't rendering to the frame, so always pass the stencil test.
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

		// Disable depth testing.
		glDisable(GL_DEPTH_TEST);

		// To the floor.
		glPushMatrix();
			
			BindTexture(floor_dark_diamonds_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.125f, -dimension.getX());
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			DrawPlane(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), 3);

		// Back to the kitchen.
		glPopMatrix();
	
		glEnable(GL_DEPTH_TEST);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

		// Turn on rendering to the frame buffer.
		glStencilFunc(GL_EQUAL, 1, 1);
		
		// Don't change the stencil values.
		glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

		// To the reflected worktop.
		glPushMatrix();
			
			// Making the kitchen objects upside down.
			glScalef(1.0f, -1.0f, 1.0f);

			// Placing the worktop exactly where I want it.
			glTranslatef((dimension.getX() / 2.0f) - 0.5f, 0.0f, -12.45f);
			glScalef(1.25f, 1.75f, 1.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			CreateWorkTop(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glRotatef(-270.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(5.0f, 0.0f, 3.75f);
			glScalef(1.25f, 1.0f, 1.0f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			CreateWorkTop(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the reflected kitchen.
		glPopMatrix();

		// To the reflected teapot model.
		glPushMatrix();

			glScalef(1.0f, -1.0f, 1.0f);
			glTranslatef((dimension.getX() / 2.0f) + 1.0f, 3.125f, (dimension.getX() / 2.0f) - 18.0f);
			glScalef(0.03125f, 0.03125f, 0.03125f);
			teapot_.Render();

		// Back to the reflected kitchen.
		glPopMatrix();

		// To the reflected cupboards.
		glPushMatrix();

			glScalef(1.0f, -1.0f, 1.0f);
			glTranslatef((dimension.getX() / 2.0f), 5.0f, -12.45f);
			glScalef(1.0f, 1.25f, 1.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glTranslatef(0.0f, 0.0f, -3.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glRotatef(-270.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(3.0f, 0.0f, 1.0f);
			glScalef(1.5f, 1.0f, 1.0f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glTranslatef(0.0f, 0.0f, -3.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the kitchen.
		glPopMatrix();

		// No longer need the stencil test.
		glDisable(GL_STENCIL_TEST);

		// To combine the flow and rendered reflection of the object.
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Lighting not really needed.
		glDisable(GL_LIGHTING);
		
		// To the floor.
		glPushMatrix();
					
			BindTexture(floor_dark_diamonds_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.125f, -dimension.getX());
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			DrawPlane(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), 3);

		// Back to the kitchen.
		glPopMatrix();

		glEnable(GL_LIGHTING);
		//glEnable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);

		// To the light shade.
		glPushMatrix();
			
			// Places in a light shade.
			CreateLightShade(Vec3((dimension.getX() / 2.0f), -dimension.getY(), (-dimension.getX() / 2.0f)), Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);
		
		// Back to the kitchen.
		glPopMatrix();

		// To the worktop.
		glPushMatrix();
			
			glTranslatef((dimension.getX() / 2.0f) - 0.5f, 0.0f, -12.45f);
			glScalef(1.25f, 1.75f, 1.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			CreateWorkTop(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glRotatef(-270.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(5.0f, 0.0f, 3.75f);
			glScalef(1.25f, 1.0f, 1.0f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			CreateWorkTop(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the kitchen.
		glPopMatrix();

		// To the teapot model.
		glPushMatrix();

			glTranslatef((dimension.getX() / 2.0f) + 1.0f, 3.125f, (dimension.getX() / 2.0f) - 18.0f);
			glScalef(0.03125f, 0.03125f, 0.03125f);
			teapot_.Render();

		// Back to the kitchen.
		glPopMatrix();

		// To the cupboards.
		glPushMatrix();

			glTranslatef((dimension.getX() / 2.0f), 5.0f, -12.45f);
			glScalef(1.0f, 1.25f, 1.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glTranslatef(0.0f, 0.0f, -3.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glRotatef(-270.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(3.0f, 0.0f, 1.0f);
			glScalef(1.5f, 1.0f, 1.0f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

			glTranslatef(0.0f, 0.0f, -3.0f);
			CreateCupboard(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the kitchen.
		glPopMatrix();
		
	// Back to the original 3D scene.
	glPopMatrix();
}

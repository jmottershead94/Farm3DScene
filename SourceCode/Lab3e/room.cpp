#include "room.h"

Room::Room()
{
}

Room::~Room()
{
}

void Room::Init()
{
	// Initialising the textures that are shared across all of the rooms.
	fabric_lightswirls_ = TextureInit("Converted_Textures/fabric_lightswirls.png");
	fabric_wallpaper_ = TextureInit("Converted_Textures/fabric_wallpaper.png");
	ladder_ = TextureInit("Converted_Textures/ladder.png");
	metal_scratched_ = TextureInit("Converted_Textures/metal_scratched.png");
	window_ = TextureInit("Converted_Textures/window.png");
	wood_ = TextureInit("Converted_Textures/wood.png");
}

void Room::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, int recursions, bool reflective, bool has_front_door, bool has_leftside_door, bool has_back_door, bool has_rightside_door, bool has_front_window, bool has_left_window, bool has_back_window, bool has_right_window, bool has_upstairs_access, bool has_downstairs_access)
{
	BindTexture(fabric_wallpaper_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
	DrawRoomCube(position, dimension, texture_coordinate, texture_dimension, 3, reflective, has_front_door, has_leftside_door, has_back_door, has_rightside_door, has_front_window, has_left_window, has_back_window, has_right_window, has_upstairs_access, has_downstairs_access);
}

void Room::CreateChair(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// Creating the chair.
	glPushMatrix();

		// Move the chair to the desired location.
		glTranslatef(position.getX(), position.getY(), position.getZ());

		// Scaling the chair to be a bit taller.
		glScalef(1.25f, 1.25f, 1.0f);

		// To the back of the chair.
		glPushMatrix();

			//TextureInit("Converted_Textures/fabric_crosshatch.png");
			//TextureInit("fabric_crosshatch.jpg");
			BindTexture(fabric_crosshatch_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Move the back of the chair so that it is raised above the rest of the chair.
			glTranslatef(0.0f, 1.0f, 0.0f);

			// Scale the back of the chair to make it look like an actual chair.
			glScalef(1.0f, 1.5f, 0.25f);

			// Draw the back of the chair.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the chair structure.
		glPopMatrix();

		// To the main seat of the chair.
		glPushMatrix();

			// Move the seat up to fit into the back of the chair.
			glTranslatef(0.0f, 0.75f, 0.0f);

			// To scale the seat appropriately.
			glScalef(1.0f, 0.25f, 1.0f);

			// Draw the seat of the chair.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
			
		// Back to the chair structure.
		glPopMatrix();

		// To the legs of the chair.
		glPushMatrix();

			//TextureInit("Converted_Textures/wood.png");
			//TextureInit("wood.jpg");
			BindTexture(wood_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Scaling the leg to make it look and fit in with the chair correctly.
			glScalef(0.25f, 0.75f, 0.25f);	
			
			// Draw the leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Move the next leg next to the previous leg.
			glTranslatef(3.0f, 0.0f, 0.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Move the next leg in front of the previous leg.
			glTranslatef(0.0f, 0.0f, -3.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Move the next leg next to the previous leg.
			glTranslatef(-3.0f, 0.0f, 0.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
			
		// Back to the chair structure.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateCouch(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// Creating the couch.
	glPushMatrix();
	
		// Setting the texture of the couch.
		//TextureInit("Converted_Textures/fabric_crosshatch.png");
		//TextureInit("fabric_crosshatch.jpg");
		BindTexture(fabric_crosshatch_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

		// Move the couch to the desired location.
		glTranslatef(position.getX(), position.getY(), position.getZ());

		// To the back of the couch.
		glPushMatrix();

			// Move the back of the couch so that it is raised above the rest of the couch.
			glTranslatef(0.0f, 1.0f, 0.0f);

			// Scale the back of the couch to make it look like an actual couch.
			glScalef(4.0f, 1.5f, 0.25f);

			// Draw the back of the couch.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the couch structure.
		glPopMatrix();

		// To the upper cushions.
		glPushMatrix();
					
			glTranslatef(0.25f, 1.0f, -0.25f);
			glScalef(1.75f, 1.5f, 0.75f);

			// Draw the first upper cushion.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			glTranslatef(1.0f, 0.0f, 0.0f);

			// Draw the second upper cushion.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
			
		// Back to the couch structure.
		glPopMatrix();

		// To the lower cushions.
		glPushMatrix();

			glTranslatef(0.25f, 1.0f, -1.0f);
			glScalef(1.75f, 0.25f, 1.0f);

			// Draw the first lower cushion.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			glTranslatef(1.0f, 0.0f, 0.0f);

			// Draw the second lower cushion.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the couch structure.
		glPopMatrix();

		// To the arms of the couch.
		glPushMatrix();

			//TextureInit("Converted_Textures/wood.png");
			BindTexture(wood_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glTranslatef(0.0f, 1.0f, -0.25f);
			glScalef(0.25f, 0.5f, 1.75f);

			// Draw the left arm.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			glTranslatef(15.0f, 0.0f, 0.0f);

			// Draw the right arm.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the couch structure.
		glPopMatrix();

		// To the main support of the couch.
		glPushMatrix();

			// To scale the support appropriately.
			glScalef(4.0f, 1.0f, 2.0f);

			// Draw the support of the couch.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
			
		// Back to the couch structure.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateTable(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// Creating the table.
	glPushMatrix();

		// Setting the texture of the table.
		//TextureInit("Converted_Textures/wood.png");
		//TextureInit("wood.jpg");
		BindTexture(wood_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

		// Move the table to the desired location.
		glTranslatef(position.getX(), position.getY(), position.getZ());

		// Scaling the table to be a bit taller.
		glScalef(2.0f, 3.0f, 3.0f);

		// To the table.
		glPushMatrix();

			// Move the table up above the floor of the room.
			glTranslatef(0.0f, 0.75f, 0.0f);

			// To scale the table appropriately.
			glScalef(2.0f, 0.125f, 2.5f);

			// Draw the table.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
			
		// Back to the table structure.
		glPopMatrix();

		// To the legs of the table.
		glPushMatrix();

			// Scaling the leg to make it look and fit in with the table correctly.
			glScalef(0.25f, 0.75f, 0.25f);	
			
			// Draw the leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Move the next leg next to the previous leg.
			glTranslatef(7.0f, 0.0f, 0.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Move the next leg in front of the previous leg.
			glTranslatef(0.0f, 0.0f, -9.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Move the next leg next to the previous leg.
			glTranslatef(-7.0f, 0.0f, 0.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
			
		// Back to the chair structure.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateBed(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, bool is_double)
{
	// Creating the bed.
	glPushMatrix();

		// Move the bed to the desired location.
		glTranslatef(position.getX(), position.getY(), position.getZ());

		// If the bed is a double bed instead of a normal single bed.
		if(is_double)
		{
			// Double the width of the whole bed.
			glScalef(2.0f, 1.0f, 1.0f);
		}

		// To the headboard.
		glPushMatrix();

			// Setting the texture of the bed (find a suitable bed texture).
			BindTexture(wooden_board_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Move the headboard so that it is raised above the rest of the bed.
			glTranslatef(0.0f, 1.0f, 0.0f);

			// Scale the headboard to make it look better.
			glScalef(4.0f, 1.5f, 0.25f);

			// Draw the headboard of the bed.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the bed structure.
		glPopMatrix();

		// To the support of the bed.
		glPushMatrix();

			// Setting the texture of the support (find a suitable bed texture).
			BindTexture(bed_sheets_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// To scale the support appropriately.
			glScalef(4.0f, 1.0f, 6.0f);

			// Draw the support of the bed.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
			
		// Back to the bed structure.
		glPopMatrix();

		// To the mattress.
		glPushMatrix();

			BindTexture(matress_cover_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Moves the mattress to the right position.
			glTranslatef(0.0f, 1.0f, -0.25f);
			glScalef(4.0f, 0.5f, 1.75f);
			
			// Draw the mattress.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the bed structure.
		glPopMatrix();

		// To the pillows
		glPushMatrix();

			// LOOK FOR A BETTER PILLOW TEXTURE.
			BindTexture(pillow_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// If it is not a double bed.
			if(!is_double)
			{
				glTranslatef(2.0f, 1.5f, -1.0f);
				glScalef(1.25f, 0.25f, 0.75f);

				// Draw just one pillow.
				DrawDome(20);
			}
			// If it is a double bed.
			else
			{
				glTranslatef(1.25f, 1.5f, -1.0f);
				glScalef(0.75f, 0.25f, 0.75f);

				// Draw first pillow.
				DrawDome(20);

				// Move the pillow along.
				glTranslatef(2.0f, 0.0f, 0.0f);

				// Draw the second pillow.
				DrawDome(20);
			}

		// Back to the bed structure.
		glPopMatrix();

		// To the covers.
		glPushMatrix();

			BindTexture(bed_covers_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glTranslatef(-0.03f, 1.0f, -2.0f);
			glScalef(4.05f, 0.55f, 4.0f);

			// Draw the covers.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
				
		// Back to the bed structure.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateBathTub(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// Just load in a bath tub model?

	// To the bath tub.
	glPushMatrix();

		// Moving the bath to the desired position.
		// Adding 2 because the dome is weird to place.
		// Means we don't have to translate up by 2 when placing in a room.
		// It will already be on level with the room floor.
		glTranslatef(position.getX(), (position.getY() + 2.0f), position.getZ());

		// To the bath tub.
		glPushMatrix();

			// Setting the texture of the bath tub (find a suitable bath tub texture).
			//TextureInit("marble_lessdetail.jpg");
			BindTexture(marble_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);	

			// Scaling the dome to look more like a tub.
			glScalef(2.0f, 1.75f, 4.5f);

			// Rotating the tub to have it facing upwards.
			glRotatef(180.0f, 1.0f, 0.0f, 0.0f);

			// Drawing the bath tub.
			DrawDome(20);

		// Back to the bath structure.
		glPopMatrix();

		// To the bath tub legs.
		glPushMatrix();

			// Weird transformation values to get the legs in the correct position.
			glTranslatef(0.5f, -1.7f, 3.0f);
			glScalef(0.5f, 0.7f, 0.25f);
			glRotatef(-30.0f, 1.0f, 0.0f, 0.0f);

			// Draw the leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Move the next leg so that it is next to the previous leg.
			glTranslatef(-3.0f, 0.0f, 0.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Rotate the legs back with no rotation so it is easier to move the final two legs around.
			glRotatef(30.0f, 1.0f, 0.0f, 0.0f);

			// Move the other two legs to the other side of the bath tub.
			glTranslatef(0.0f, -0.35f, -24.0f);

			// Rotate the legs to tilt them towards the bath tub.
			glRotatef(30.0f, 1.0f, 0.0f, 0.0f);

			// Draw the next leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			glTranslatef(3.0f, 0.0f, 0.0f);

			// Draw the final leg.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the bath structure.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateDrawers(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// To the set of drawers.
	glPushMatrix();

		// Move the set of drawers to a desired location.
		glTranslatef(position.getX(), position.getY(), position.getZ());

		// To the top of the drawers.
		glPushMatrix();
			
			// Setting the texture for the outside of the drawers.
			BindTexture(marble_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Making sure the top of the drawers is above everything else and centred.
			glTranslatef(0.0f, 1.5f, -1.0f);

			// Strech out the top to make it bigger than the drawers.
			glScalef(1.05f, 0.125f, 1.0f);

			// Rotating the top so that it is flat.
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// Draw the top of the drawers.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the drawers structure.
		glPopMatrix();

		// To the set of drawers.
		glPushMatrix();

			// Setting the textures for the wooden drawers.
			BindTexture(wood_light_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Scaling the drawer so that it looks thinner like a drawer should.
			glScalef(1.0f, 0.5f, 1.0f);

			// Draws the first drawer.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// To the handles.
			glPushMatrix();

				// Setting the textures for the handles of the drawers.
				BindTexture(wood_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

				glTranslatef(1.0f, 0.5f, -0.425f);
				glScalef(0.0625f, 0.0625f, 0.125f);

				// Draws the first drawer.
				DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

				glTranslatef(0.0f, 14.0f, 0.0f);

				// Draws the second handle.
				DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

				glTranslatef(0.0f, 16.0f, 0.0f);

				// Draws the final handle.
				DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
				
			// Back to the drawers structure.
			glPopMatrix();

			// Resetting the texture for the drawers.
			BindTexture(wood_light_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Moves the next drawer up.
			glTranslatef(0.0f, 1.0f, 0.0f);

			// Draws the next drawer.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			glTranslatef(0.0f, 1.0f, 0.0f);

			// Draws the last drawer.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the drawers structure.
		glPopMatrix();

		// To the sides of the drawers.
		glPushMatrix();

			BindTexture(marble_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glTranslatef(0.0f, 0.0f, 0.01f);
			glScalef(1.0f, 1.5f, 1.0f);

			// Draw the left side of the drawers
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			// Moves the next wooden panel further along so that it covers the other side.
			glTranslatef(0.0f, 0.0f, -1.02f);

			// Draws the right side of the drawers
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			// Transformations to put the back panel on the drawers.
			glTranslatef(-0.02f, 0.0f, 1.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

			// Draw the back of the drawers
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
			
		// Back to the drawers structure.
		glPopMatrix();
		
	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateWorkTop(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// Go to the work top.
	glPushMatrix();

		// Place in a set of drawers.
		CreateDrawers(position, dimension, texture_coordinate, texture_dimension);

		// To the next set of drawers.
		glPushMatrix();

			glTranslatef(0.0f, 0.0f, -1.0f);
			glScalef(1.0f, 1.0f, 1.25f);

			// Place in a set of drawers.
			CreateDrawers(position, dimension, texture_coordinate, texture_dimension);

		// Back to the work top structure.
		glPopMatrix();

		// To the next blank section of the work top.
		glPushMatrix();

			glTranslatef(0.0f, 0.0f, -2.25f);
			glScalef(1.0f, 1.625f, 1.5f);

			// Draw the next section.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			glTranslatef(0.0f, 0.0f, -1.0f);

			// Draw the next section.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			glTranslatef(1.0f, 0.0f, 0.0f);
			glScalef(1.5f, 1.0f, 1.0f);

			// Draw the next section.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the work top structure.
		glPopMatrix();

		// To the next set of drawers.
		glPushMatrix();

			glTranslatef(2.5f, 0.0f, -5.25f);
			glScalef(1.25f, 1.0f, 1.5f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);

			// Place in a set of drawers.
			CreateDrawers(position, dimension, texture_coordinate, texture_dimension);

		// Back to the original 3D scene.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateCupboard(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// To the cupboard.
	glPushMatrix();

		// Move the cupboard to a desired location.
		glTranslatef(position.getX(), position.getY() + 1.0f, position.getZ());

		// To the top and bottom of the cupboard.
		glPushMatrix();
			
			// Texture for the outside of the cupboard.
			BindTexture(marble_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Making sure the top of the cupboard is above everything else.
			glTranslatef(0.0f, 1.5f, -3.0f);

			// Strech out the top to make it bigger than the drawers.
			glScalef(1.0f, 0.125f, 3.0f);

			// Rotating the top so that it is flat.
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// Draw the top of the cupboard.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Making sure the bottom of the cupboard is below everything else.
			glTranslatef(0.0f, 0.0f, 13.0f);

			// Draw the bottom of the cupboard.
			DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

		// Back to the cupboard structure.
		glPopMatrix();

		// To the cupboard doors.
		glPushMatrix();

			// Texture for the doors.
			BindTexture(wood_light_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Scaling the door so that they look thinner.
			glTranslatef(1.0f, 0.0f, 0.0f);
			glScalef(1.0f, 1.5f, 1.5f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

			// Draws the first door.
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
			
			// To the cupboard door handles.
			glPushMatrix();
				
				BindTexture(wood_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

				glTranslatef(0.75f, 0.125f, 0.125f);
				glScalef(0.125f, 0.0625f, 0.125f);

				// Draw the first handle.
				DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

				glTranslatef(3.0f, 0.0f, 0.0f);

				// Draw the first handle.
				DrawCube(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);

			// Back to the cupboard doors.
			glPopMatrix();

			BindTexture(wood_light_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			// Moves the next drawer up.
			glTranslatef(1.0f, 0.0f, 0.0f);

			// Draws the second door.
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

		// Back to the drawers structure.
		glPopMatrix();

		// To the sides of the drawers.
		glPushMatrix();

			BindTexture(marble_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glTranslatef(0.0f, 0.0f, 0.01f);
			glScalef(1.0f, 1.5f, 1.5f);

			// Draw the left side of the drawers
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			// Moves the next wooden panel further along so that it covers the other side.
			glTranslatef(0.0f, 0.0f, -2.0f);

			// Draws the right side of the drawers
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			// Transformations to put the back panel on the drawers.
			glTranslatef(-0.02f, 0.0f, 2.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glScalef(2.0f, 1.0f, 1.0f);

			// Draw the back of the drawers.
			DrawQuad(origin_, Vec2(dimension.getX(), dimension.getY()), texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
			
		// Back to the drawers structure.
		glPopMatrix();
		
	// Back to the original 3D scene.
	glPopMatrix();
}

void Room::CreateLamp(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// To the lamp.
	glPushMatrix();
		
		// Moving the lamp to the desired position.
		glTranslatef(position.getX(), position.getY() + 4.0f, position.getZ());

		// To the base of the lamp.
		glPushMatrix();

			//TextureInit("Converted_Textures/metal_scratched.png");
			//TextureInit("metal_scratched.jpg");
			BindTexture(metal_scratched_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glTranslatef(0.0f, -3.75f, 0.0f);
			glScalef(1.0f, 0.25f, 1.0f);

			// Draw the base of the lamp.
			DrawDome(10);

		// Back to the lamp structure.
		glPopMatrix();

		// To the lamp stand.
		glPushMatrix();

			glScalef(0.125f, 0.75f, 0.125f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// Drawing the stand for the lamp.
			DrawCylinder(20);

		// Back to the lamp structure.
		glPopMatrix();

		// To the lamp shade.
		glPushMatrix();

			//TextureInit("Converted_Textures/fabric_lightswirls.png");
			//TextureInit("fabric_lightswirls.jpg");
			BindTexture(fabric_lightswirls_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glTranslatef(0.0f, 0.0f, 0.0f);
			glScalef(1.0f, 0.5f, 1.0f);
				
			// Draw the lamp shade.
			DrawDome(10);

		// Back to the lamp structure.
		glPopMatrix();

	// Back the original 3D scene.
	glPopMatrix();
}

void Room::CreateLightShade(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// To the light shade.
	glPushMatrix();

		// Moving the light shade to the desired position.
		// Add on whatever the dimensions.getY() from the building.
		glTranslatef(position.getX(), position.getY() + 24.9f, position.getZ());

		// To the roof attachment.
		glPushMatrix();

			BindTexture(fabric_light_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glScalef(1.0f, 0.25f, 1.0f);
			glRotatef(180.0f, 1.0f, 0.0f, 0.0f);

			// Drawing the roof attachement for the lightshade.
			DrawDome(10);

		// Back to the light shade structure.
		glPopMatrix();

		// To the wire attaching the light to the ceiling.
		glPushMatrix();
			
			glScalef(0.0625f, 0.75f, 0.0625f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			
			// Drawing the wire.
			DrawCylinder(10);

		// Back to the light shade structure.
		glPopMatrix();

		// To the light shade.
		glPushMatrix();

			BindTexture(fabric_lightswirls_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

			glTranslatef(0.0f, -1.0f, 0.0f);
			glScalef(0.75f, 0.75f, 0.75f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// Drawing the light shade.
			DrawCylinder(10);

		// Back to the light shade structure.
		glPopMatrix();

		// To the bulb.
		glPushMatrix();

			glTranslatef(0.0f, -1.5f, 0.0f);
			glScalef(0.25f, 0.375f, 0.25f);

			// Draws the light bulb.
			DrawSphere(10);

		// Back to the light shade structure.
		glPopMatrix();

	// Back the original 3D scene.
	glPopMatrix();
}

void Room::CreatePainting(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, const char* painting_name)
{
	glPushMatrix();

		if(painting_name == "Converted_Textures/painting_brightfields.jpg")
		{
			BindTexture(painting_brightfields_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/painting_darkfields.jpg")
		{
			BindTexture(painting_darkfields_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/painting_farm.jpg")
		{
			BindTexture(painting_farm_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/painting_house.jpg")
		{
			BindTexture(painting_house_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/painting_river.jpg")
		{
			BindTexture(painting_river_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/painting_trees.jpg")
		{
			BindTexture(painting_trees_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/poster_batman_v_superman.png")
		{
			BindTexture(poster_batman_v_superman_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/poster_breaking_bad.jpg")
		{
			BindTexture(poster_breaking_bad_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		else if(painting_name == "Converted_Textures/poster_the_walking_dead.jpg")
		{
			BindTexture(poster_the_walking_dead_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		}
		
		// The painting that will be displayed.
		//TextureInit(painting_name);
		//BindTexture(painting_name, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

		// Moving the painting to the desired place.
		glTranslatef(position.getX(), position.getY() + 1.0f, position.getZ() + 0.01f);

		// Use of vertex arrays to render a quad.
		render2();

	glPopMatrix();
}
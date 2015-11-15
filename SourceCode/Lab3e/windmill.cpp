#include "windmill.h"

Windmill::Windmill()
{
	fan_rotation_ = 0.0f;
	scrolling_text_x_ = 0.0f;
}

Windmill::~Windmill()
{
}

void Windmill::Init()
{
	// Load in textures here.
	windmill_base_ = TextureInit("Converted_Textures/wood.png");
	windmill_roof_ = TextureInit("Converted_Textures/red.png");
	text_ = TextureInit("Converted_Textures/text_banner.png");
}

void Windmill::Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// Draw the windmill here.
	glPushMatrix();
		
		// Move the windmill to where we want.
		glTranslatef(position.getX(), position.getY(), position.getZ());
		glScalef(1.0f, 1.0f, 0.75f);

		// To the main base of the windmill.
		glPushMatrix();

			BindTexture(windmill_base_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.001f, 0.0f);
			glScalef(1.0f, 1.5f, 1.0f);

			// Drawing the main base of the windmill.
			DrawCube(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
						
			// To the text.
			glPushMatrix();

				scrolling_text_.BindTexture(text_, GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_REPEAT, GL_REPEAT);
				
				// Switching to the texture matrix for texture transformations.
				glMatrixMode(GL_TEXTURE);
		
				// Scrolling the texture along.
				glTranslatef((scrolling_text_x_+=0.001f), 0.0f, 0.0f);

				// Back to the model view matrix for model transformations.
				glMatrixMode(GL_MODELVIEW);
				
				// Applying model transformations.
				glTranslatef(-1.0f, 3.0f, -0.25f);
				glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
				glScalef(0.5f, 0.125f, 0.5f);

				scrolling_text_.DrawQuad(position, dimension, Vec2(0.0f, 0.0f), Vec2(0.25f, 1.0f), Vec3(-1.0f, 0.0f, 0.0f));
				
				// Resetting the texture matrix.
				glMatrixMode(GL_TEXTURE);
				glLoadIdentity();

				// Switching to the model view matrix.
				glMatrixMode(GL_MODELVIEW);

			// Back to the windmill.
			glPopMatrix();

			// To the dome top.
			glPushMatrix();
						
				BindTexture(windmill_roof_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
				glTranslatef((dimension.getX() / 2.0f), dimension.getY(), (-dimension.getX() / 2.0f));
				glScalef((dimension.getX() / 2.0f), (dimension.getY() / 4.0f), (dimension.getX() / 2.0f));
				DrawDome(20);
			
			// Back to the windmill.
			glPopMatrix();

			// To the fan attachment.
			glPushMatrix();
			
				// Adding a fan attachment.
				BindTexture(windmill_base_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
				glTranslatef((-dimension.getX() / 4.0f), dimension.getY() - 2.0f, (-dimension.getX() / 2.0f));
				glScalef(0.25f, 0.0625f, 0.0625f);
				DrawCube(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
								
				// To the fan dome attachment.
				glPushMatrix();
						
					glTranslatef(0.0f, 7.0f, -8.0f);
					glScalef(3.0f, 9.0f, 15.0f);
					glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

					// Use of user interaction, allowing rotation of the windmill.
					glRotatef(fan_rotation_, 0.0f, 1.0f, 0.0f);
					DrawDome(20);

					// To the windmill fan blades.
					glPushMatrix();
						
						BindTexture(windmill_base_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			
						// To the first and second windmill fan blade.
						glPushMatrix();

							// Rotating the rotation matrix back to the origin.
							glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);

							glTranslatef(0.0f, 0.25f, 0.5f);
							glScalef(0.0625f, 0.75f, 0.0625f);
							DrawCube(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
						
							// Reverses the second fan blade.
							glScalef(1.0f, -1.0f, 1.0f);
							DrawCube(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
						
						// Back to the windmill fan blades.
						glPopMatrix();

						// To the third and fourth windmill fan blades.
						glPushMatrix();
							
							// Rotating the rotation matrix back to the origin.
							glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);

							glTranslatef(0.0f, -0.5f, 0.25f);
							glScalef(0.0625f, 0.0625f, 0.75f);
							DrawCube(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
						
							// Reverses the final fan blade.
							glScalef(1.0f, 1.0f, -1.0f);
							DrawCube(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), false);
						
						// Back to the windmill fan blades.
						glPopMatrix();

					// Back to the fan dome attachment.
					glPopMatrix();
			
				// Back to the windmill.
				glPopMatrix();

			// Back to the windmill.
			glPopMatrix();

		// Back to the windmill.
		glPopMatrix();
			
	// Back to the original 3D scene.
	glPopMatrix();
}
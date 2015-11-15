#include "skybox.h"

Skybox::Skybox()
{
	rotation_ = 0.0f;
}

Skybox::~Skybox()
{
}

void Skybox::Init(Vec3 position, Vec3 camera)
{
	// Setting up the skybox.
	glPushMatrix();

		glTranslatef(camera.getX(), camera.getY(), camera.getZ());
		glScalef(4.0f, 4.0f, 4.0f);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		// Constant shape/texture dimensions.
		Vec2 dimension (1.0f, 1.0f);
		Vec2 texture_dimension (0.25f, 0.25f);

		glPushMatrix();

			// FRONT FACE.
			DrawQuad(position, dimension, Vec2(0.25f, 0.25f), texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
		
			// BACK FACE.
			glPushMatrix();

				glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
				DrawQuad(position, dimension, Vec2(0.75f, 0.25f), texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			glPopMatrix();

			// Rotate to work with left and right.
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

			// RIGHT FACE.
			glPushMatrix();
			
				glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
				DrawQuad(position, dimension, Vec2(0.5f, 0.25f), texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			glPopMatrix();

			// LEFT FACE.
			DrawQuad(position, dimension, Vec2(0.0f, 0.25f), texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			// Rotate to work with top and bottom.
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// TOP FACE.
			glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
			DrawQuad(position, dimension, Vec2(0.25f, 0.0f), texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			// BOTTOM FACE.
			glPushMatrix();

				glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
				DrawQuad(position, dimension, Vec2(0.25f, 0.5f), texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

			// Back to front face.
			glPopMatrix();

		// Back to the skybox in general.
		glPopMatrix();

		// The skybox has been set up, therefore turn the properties back as they were.
		glDisable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
	
	// Back to the original 3D scene.
	glPopMatrix();
}
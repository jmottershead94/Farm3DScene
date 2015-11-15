#include "mesh.h"

Mesh::Mesh()
{
	// Setting the origin start points.
	origin_.setX(0.0f);
	origin_.setY(0.0f);
	origin_.setZ(0.0f);
}

Mesh::~Mesh()
{
}

GLuint Mesh::TextureInit(const char* texture_filename)
{
	// Loading in the texture.
	my_texture_ = SOIL_load_OGL_texture
	(
		texture_filename,									// Name of the file we want to load.
		SOIL_LOAD_AUTO,										// Makes sure the image stays in the same format.
		SOIL_CREATE_NEW_ID,									// Creates a new texture ID for the image.
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB |		// Generates mipmaps for the texture, clamps the RGB range.
		SOIL_FLAG_COMPRESS_TO_DXT							// Form of texture compression, to save resources.
	);

	// If there is no texture.
	if( 0 == my_texture_ )
	{
		// Display a message box.
		MessageBox(NULL, "Texture failed to load.", "Error", MB_OK);
	}

	return my_texture_;
}

void Mesh::BindTexture(GLuint& texture, GLenum pname_near, GLenum pname_far, GLint param_near, GLint param_far)
{
	// Creates the first texture.
	glBindTexture(GL_TEXTURE_2D, texture);

	// Sets the graphics filtering on the texture, bilinear, trilinear etc.
	glTexParameteri(GL_TEXTURE_2D, pname_near, param_near);
	glTexParameteri(GL_TEXTURE_2D, pname_far, param_far);
}

void Mesh::DrawTriangle(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension)
{
	// Move the mesh by the specified position.
	glTranslatef(position.getX(), position.getY(), position.getZ());

	// Maybe use this vector to create random terrain?
	// Get each point on the quad and randomize the values?
	//positions_.push_back(position);

	// Apply a texture.
	//BindTexture(GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_REPEAT, GL_REPEAT);

	// Draws a triangle.
	glBegin(GL_TRIANGLES);

		// Bottom left vertex.
		glTexCoord2f(texture_coordinate.getX(), (texture_coordinate.getY() + texture_dimension.getY()));
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(origin_.getX(), origin_.getY(), origin_.getZ());

		// Bottom right vertex.
		glTexCoord2f((texture_coordinate.getX() + texture_dimension.getX()), (texture_coordinate.getY() + texture_dimension.getY()));
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f((origin_.getX() + dimension.getX()), origin_.getY(), origin_.getZ());

		// Top vertex.
		glTexCoord2f(texture_coordinate.getX(), texture_coordinate.getY());
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(origin_.getX(), (origin_.getY() + dimension.getY()), origin_.getZ());
	
	glEnd();

	// Translate back to the origin.
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}

// NEED TO FIGURE OUT HOW TO TEXTURE IT PROPERLY.
void Mesh::DrawDisc(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, int segments)
{
	// Move the mesh by the specified position.
	glTranslatef(position.getX(), position.getY(), position.getZ());

	// Apply a texture.
	//BindTexture(GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_REPEAT, GL_REPEAT);

	glBegin (GL_TRIANGLES);					

		// Draws a circle.
		for(int segment_number = 0; segment_number <= segments; ++segment_number)
		{
			glTexCoord2f(texture_coordinate.getX(), (texture_coordinate.getY() + texture_dimension.getY()));
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(origin_.getX(), origin_.getY(), origin_.getZ());
			
			float theta = (2.0f * PI * (float)segment_number) / (float)segments;
			glTexCoord2f((((cosf(theta) / dimension.getX()) + 0.5f) + texture_dimension.getX()), (((sinf(theta) / dimension.getY()) + 0.5f) + texture_dimension.getY()));
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f((origin_.getX() + ((dimension.getX() / 2.0f) * sinf(theta))), (origin_.getY() + ((dimension.getY() / 2.0f) * cosf(theta))), origin_.getZ());
			
			theta = (2.0f * PI * (float)(segment_number + 1.0f)) / (float)segments;
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f((((cosf(theta) / dimension.getX()) + 0.5f) + texture_dimension.getX()), (((sinf(theta) / dimension.getY()) + 0.5f) + texture_dimension.getY()));
			glVertex3f((origin_.getX() + ((dimension.getX() / 2.0f) * sinf(theta))), (origin_.getY() + ((dimension.getY() / 2.0f) * cosf(theta))), origin_.getZ());
		}

		// Clamp the values back to the start point.
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(position.getX(), position.getY(), position.getZ());

	glEnd();

	// Translate back to the origin.
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}

void Mesh::DrawQuad(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals)
{
	// Move the mesh by the specified position.
	glTranslatef(position.getX(), position.getY(), position.getZ());

	// Maybe use this vector to create random terrain?
	// Get each point on the quad and randomize the values?
	//positions_.push_back(position);

	// Apply a texture.
	//BindTexture(GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_REPEAT, GL_REPEAT);

	glBegin(GL_TRIANGLES);
		
		// Bottom left vertex.
		glTexCoord2f(texture_coordinate.getX(), (texture_coordinate.getY() + texture_dimension.getY()));
		glNormal3f(normals.getX(), normals.getY(), normals.getZ());
		glVertex3f(origin_.getX(), origin_.getY(), origin_.getZ());

		// Bottom right vertex.
		glTexCoord2f((texture_coordinate.getX() + texture_dimension.getX()), (texture_coordinate.getY() + texture_dimension.getY()));
		glNormal3f(normals.getX(), normals.getY(), normals.getZ());
		glVertex3f((origin_.getX() + dimension.getX()), origin_.getY(), origin_.getZ());

		// Top left vertex.
		glTexCoord2f(texture_coordinate.getX(), texture_coordinate.getY());
		glNormal3f(normals.getX(), normals.getY(), normals.getZ());
		glVertex3f(origin_.getX(), origin_.getY() + dimension.getY(), origin_.getZ());

		// Bottom right vertex.
		glTexCoord2f((texture_coordinate.getX() + texture_dimension.getX()), (texture_coordinate.getY() + texture_dimension.getY()));
		glNormal3f(normals.getX(), normals.getY(), normals.getZ());
		glVertex3f((origin_.getX() + dimension.getX()), origin_.getY(), origin_.getZ());

		// Top right vertex.
		glTexCoord2f((texture_coordinate.getX() + texture_dimension.getX()), texture_coordinate.getY());
		glNormal3f(normals.getX(), normals.getY(), normals.getZ());
		glVertex3f((origin_.getX() + dimension.getX()), (origin_.getY() + dimension.getY()), origin_.getZ());

		// Top left vertex.
		glTexCoord2f(texture_coordinate.getX(), texture_coordinate.getY());
		glNormal3f(normals.getX(), normals.getY(), normals.getZ());
		glVertex3f(origin_.getX(), origin_.getY() + dimension.getY(), origin_.getZ());

	glEnd();

	// Translates back to the origin.
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}

void Mesh::DrawPlane(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, int recursive_number)
{
	// Move the mesh by the specified position.
	glTranslatef(position.getX(), position.getY(), position.getZ());
		
	float dimension_multiplier = 1.0f / (float)recursive_number;

	Vec2 recursive_dimension(dimension.getX() * dimension_multiplier, dimension.getY() * dimension_multiplier);

	for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
	{
		for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
		{
			DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, normals);

			glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
		}

		glTranslatef(0.0f, -dimension.getY(), 0.0f);

		glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
	}

	glTranslatef(-dimension.getX(), 0.0f, 0.0f);
		
	// Translates back to the origin.
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}
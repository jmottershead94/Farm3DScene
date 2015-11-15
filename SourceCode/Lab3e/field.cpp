#include "field.h"

Field::Field()
{
	point_light_position_.set(0.0f, 0.0f, 0.0f);
}

Field::~Field()
{
}

void Field::Init()
{
	// Initialising the local textures.
	grass_ = TextureInit("Converted_Textures/grass1.png");

	// Initialising the house.
	house_.Init();
	house_.Render (
					Vec3(0.0f, 0.0f, 0.0f),		// Position (x, y, z).
					Vec2(25.0f, 25.0f),			// Dimensions (width, height).
					Vec2(0.0f, 0.0f),			// Texture start coordinates (u, v).
					Vec2(1.0f, 1.0f),			// Texture dimensions (width, height).
					Vec2(2.0f, 2.0f)			// Number of rooms and floors of the building.
				  );

	// Initialising the windmill.
	windmill_.Init();
	windmill_.Render (
						Vec3(0.0f, 0.0f, 0.0f),	// Position (x, y, z).
						Vec2(15.0f, 15.0f),		// Dimensions (width, height).
						Vec2(0.0f, 0.0f),		// Texture start coordinates (u, v).
						Vec2(1.0f, 1.0f)		// Texture dimensions (width, height).
					 );
}

void Field::Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, int recursive_number, bool draw_shadow)
{
	// Draw the fields with shadows from the buildings.
	DrawShadowMatrixScene(position, dimension, texture_coordinate, texture_dimension, normals, recursive_number, draw_shadow);
}

// For rendering planar shadows.
void Field::DrawShadowMatrixScene(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, int recursive_number, bool draw_shadow)
{
	// Setting up light variables for use in shadows and lighting.
	// This will be used to pass in as a parameter for the shadows.
	GLfloat glfloat_light_position_[] = {35.0f, 50.0f, 20.0f, 0.0f};
	
	// This will be used to pass in to my light function as a Vec3 variable.
	Vec3 vec3_light_position_(glfloat_light_position_[0], glfloat_light_position_[1], glfloat_light_position_[2]);

	// Initialising the "Sun" for the scene.
	directional_light_.Init(Vec3(1.0f, 1.0f, 1.0f), vec3_light_position_, Vec3(1.0f, 1.0f, 1.0f));

	// To the animated point light.
	glPushMatrix();
		
		glDisable(GL_TEXTURE_2D);

		// Making a blue point light.
		glColor3f(0.1f, 0.1f, 1.0f);
		glTranslatef(point_light_position_.getX(), point_light_position_.getY(), point_light_position_.getZ());
		point_light_.Init(Vec3(0.0f, 0.0f, 1.0f), Vec3(15.0f, 10.0f, 7.0f), Vec3(1.0f, 1.0f, 1.0f));
		glColor3f(1.0f, 1.0f, 1.0f);

		glEnable(GL_TEXTURE_2D);

	// Back to the fields.
	glPopMatrix();

	// Plane that the shadow will be mapped onto. Leave this be.
    GLfloat v0[3], v1[3], v2[3];

    // To define a plane that matches the floor, we need to 3 vertices from it
    v0[0] = -1.0;
    v0[1] = -1.0;
    v0[2] = -1.0;

    v1[0] = -1.0;
    v1[1] = -1.0;
    v1[2] = 1.0;

    v2[0] = 1.0;
    v2[1] = -1.0;
    v2[2] = -1.0;
	
	GenerateShadowMatrix(mshadowMatrix, glfloat_light_position_, v0, v1, v2);

	// Draw none shadow affected objects here.
	// To the field plane.
	glPushMatrix();
	
		BindTexture(grass_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
		glTranslatef(0.0f, 0.0f, -10.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		DrawPlane(position, dimension, texture_coordinate, texture_dimension, normals, recursive_number);

		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

		glTranslatef(0.0f, 0.0f, (-dimension.getX() - (dimension.getX() / 5.0f)));
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		DrawPlane(position, dimension, texture_coordinate, texture_dimension, normals, recursive_number);

		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

		glTranslatef((dimension.getX() / 3.0f), -0.001f, dimension.getX());
		glScalef(1.0f, 0.25f, 1.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		DrawPlane(position, dimension, texture_coordinate, texture_dimension, normals, recursive_number);

		glTranslatef((-dimension.getX() * 1.25f), 0.0f, 0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		DrawPlane(position, dimension, texture_coordinate, texture_dimension, normals, recursive_number);

		glTranslatef(0.0f, -dimension.getX(), 0.0f);
		DrawPlane(position, dimension, texture_coordinate, texture_dimension, normals, recursive_number);

	// Back to the original 3D scene.
	glPopMatrix();

	// To the house.
	glPushMatrix();

		glCallList(house_.house_displaylist_);

	// Back to the original 3D scene.
	glPopMatrix();

	glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	if(draw_shadow)
	{
		glColor3f(0.1f, 0.1f, 0.1f); // Shadow's color

		// To the shadows of the field objects.
		glPushMatrix();

			glMultMatrixf((GLfloat *) mshadowMatrix);

			// Translate to floor and draw shadow, remember to match any transforms on the object.
			glTranslatef(40.0f, 0.0f, 20.0f);
			windmill_.Render(Vec3(0.0f, 0.0f, 0.0f), Vec2(15.0f, 15.0f), Vec2(0.0f, 0.0f),	Vec2(1.0f, 1.0f));

		// Back to the field.
		glPopMatrix();

		glColor3f(1.0f, 1.0f, 1.0f);
	}
	
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	// To the actual field objects.
	glPushMatrix();

		// Move the field objects up from the plane.
		glTranslatef(35.0f, 0.0f, 20.0f);
		windmill_.Render(Vec3(0.0f, 0.0f, 0.0f), Vec2(15.0f, 15.0f), Vec2(0.0f, 0.0f),	Vec2(1.0f, 1.0f));
	
	// Back to the field.
	glPopMatrix();
}

void Field::GenerateShadowMatrix(float matrix[16], float light_pos[4], GLfloat v0[3], GLfloat v1[3], GLfloat v2[3] ) 
{
	//Defining vertices of plane are PQR with edges PQ and PR
	Vec3 P(v0[0], v0[1], v0[2]);
	Vec3 Q(v1[0], v1[1], v1[2]);
	Vec3 R(v2[0], v2[1], v2[2]);

	Vec3 PQ = (Q - P).normalize();
	Vec3 PR = (R - P).normalize();
	Vec3 normal = PR.cross(PQ);

	//Equation of plane is ax + by + cz = d
	//a, b and c are the coefficients of the normal to the plane (i.e. normal = ai + bj + ck)
	//If (x0, y0, z0) is any point on the plane, d = a*x0 + b*y0 + c*z0
	//i.e. d is the dot product of any point on the plane (using P here) and the normal to the plane
	float a, b, c, d;
	a = normal.getX();
	b = normal.getY();
	c = normal.getZ();
	d = normal.dot(P);

	//Origin of projection is at x, y, z. Projection here originating from the light source's position
	float x, y, z;

	x = light_pos[0];
	y = light_pos[1];
	z = light_pos[2];

	//This is the general perspective transformation matrix from a point (x, y, z) onto the plane ax + by + cz = d
	matrix[0] = d - (b * y + c * z);
	matrix[1] = a * y;
	matrix[2] = a * z;
	matrix[3] = a;

	matrix[4] = b * x;
	matrix[5] = d - (a * x + c * z);
	matrix[6] = b * z;
	matrix[7] = b;

	matrix[8] = c * x;
	matrix[9] = c * y;
	matrix[10] = d - (a * x + b * y);
	matrix[11] = c;

	matrix[12] = -d * x;
	matrix[13] = -d * y;
	matrix[14] = -d * z;
	matrix[15] = -(a * x + b * y + c * z);
}
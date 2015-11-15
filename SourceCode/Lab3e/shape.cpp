#include "shape.h"

extern GLubyte indices[]=	{
								0,   1,   2,	//front
								0,   2,   3,
							};

extern float verts[] = {	
							-1.0, 1.0, 1.0,			// Vertex #0
							-1.0, -1.0, 1.0,		// Vertex #1
							1.0,  -1.0, 1.0,		// Vertex #2
							1.0,  1.0, 1.0,			// Vertex #3
					   };

extern float norms[] =  { 
							0.0, 0.0, 1.0,		//0
							0.0, 0.0, 1.0,		//1
 							0.0, 0.0, 1.0,		//2
							0.0, 0.0, 1.0,		//3
						};		


extern float texcoords[]=	{	
								0.0, 0.0, 		//0
								0.0, 1.0, 		//1
 								1.0, 1.0, 		//2
								1.0, 0.0, 		//3
							};

void Shape::render1()
{
	// Apply a texture.
	//BindTexture(GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
	
	// Tell OpenGL what data we have.
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	// Tell OpenGL how the data is arranged.
	glVertexPointer(3, GL_FLOAT, 0, verts);
	glNormalPointer (GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	// Dereferencing single array elements method.
	glBegin(GL_TRIANGLES);

		// Triangle One.
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(2);

		// Triangle Two.
		glArrayElement(0);
		glArrayElement(3);
		glArrayElement(2);

	glEnd();

	// Turn off.
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Shape::render2()
{
	// Apply a texture.
	//BindTexture(GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

	// Telling OpenGL the data that we have.
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	// Tell OpenGL how the data is arranged.
	glVertexPointer(3, GL_FLOAT, 0, verts);
	glNormalPointer (GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	// Drawing the array elements.
	glDrawArrays(GL_QUADS, 0, 4);

	// Turn off.
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Shape::render3()
{
	// Apply a texture.
	//BindTexture(GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

	// Telling OpenGL what data we have.
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_INDEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	// Tell OpenGL how the data is arranged.
	glVertexPointer(3, GL_FLOAT, 0, verts);
	glIndexPointer(GL_FLOAT, 0, indices);
	glNormalPointer (GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	// Draw the cube.
	for(int i = 0; i < 2; ++i)
	{
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
		glTranslatef(0.0f, 0.0f, -2.0f);
	}

	glTranslatef(0.0f, 0.0f, 4.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	for(int j = 0; j < 2; ++j)
	{
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
		glTranslatef(0.0f, 0.0f, -2.0f);
	}

	glTranslatef(0.0f, 2.0f, 4.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

	for(int k = 0; k < 2; ++k)
	{
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
		glTranslatef(0.0f, 0.0f, 2.0f);
	}

	// Turn off.
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_INDEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Shape::DrawSphere(int segments)
{
	// Apply a texture.
	//BindTexture(GL_TEXTURE_GEN_MODE, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP, GL_SPHERE_MAP);

	glBegin (GL_QUADS);					//Begin drawing state
		
		// Draws a sphere.
		for(int longitude = 0; longitude <= segments; ++longitude)
		{
			for(int latitude = 0; latitude <= segments; ++latitude)
			{
				float theta = (2.0f * PI * (float)latitude) / (float)segments;
				float delta = (PI * (float)longitude) / (float)segments;
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));
				
				theta = (2.0f * PI * (float)(latitude + 1.0f)) / (float)segments;
				delta = (PI * (float)longitude) / (float)segments;
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));

				theta = (2.0f * PI * (float)(latitude + 1.0f)) / (float)segments;
				delta = (PI * (float)(longitude + 1.0f)) / (float)segments;
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));

				theta = (2.0f * PI * (float)latitude) / (float)segments;
				delta = (PI * (float)(longitude + 1.0f)) / (float)segments;
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));
			}
		}

	glEnd();
}

void Shape::DrawDome(int segments)
{
	//BindTexture(GL_TEXTURE_GEN_MODE, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP, GL_SPHERE_MAP);

	glBegin (GL_QUADS);					//Begin drawing state
		
		// Draws a dome.
		for(int longitude = 0; longitude <= (segments / 2); ++longitude)
		{
			for(int latitude = 0; latitude <= segments; ++latitude)
			{
				//BindTexture(GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_SPHERE_MAP, GL_SPHERE_MAP);

				float theta = (2.0f * PI * (float)latitude) / (float)segments;
				float delta = (PI * (float)longitude) / (float)segments;
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));
				
				theta = (2.0f * PI * (float)(latitude + 1.0f)) / (float)segments;
				delta = (PI * (float)longitude) / (float)segments;
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));

				theta = (2.0f * PI * (float)(latitude + 1.0f)) / (float)segments;
				delta = (PI * (float)(longitude + 1.0f)) / (float)segments;
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));

				theta = (2.0f * PI * (float)latitude) / (float)segments;
				delta = (PI * (float)(longitude + 1.0f)) / (float)segments;
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(delta) / 2.0f) + 0.5f));
				glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));
			}
		}

	glEnd();
}

void Shape::DrawCylinder(int segments)
{
	//BindTexture(GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_REPEAT, GL_REPEAT);

	glBegin (GL_QUADS);					//Begin drawing state

		float const bottom = 0.0125f * 0.0f;
		float const top = 0.25f * (segments - 1.0f);

		// Draws a cylinder with no front or back faces.
		// Place discs at front and back end to shut off cylinder.
		for(int i = 0; i <= segments; ++i)
		{
			float theta = (2.0 * PI * (float)i) / (float)segments;
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(theta) / 2.0f) + 0.5f));
			glVertex3f(sinf(theta), cosf(theta), bottom);
				
			theta = (2.0f * PI * (float)(i + 1.0f)) / (float)segments;
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(theta) / 2.0f) + 0.5f));
			glVertex3f(sinf(theta), cosf(theta), bottom);

			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(theta) / 2.0f) + 0.5f));
			glVertex3f(sinf(theta), cosf(theta), top);

			theta = (2.0 * PI * (float)i) / (float)segments;
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(((cosf(theta) / 2.0f) + 0.5f), ((sinf(theta) / 2.0f) + 0.5f));
			glVertex3f(sinf(theta), cosf(theta), top);
		}

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();
}

void Shape::DrawCube(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec3 normals, bool reflective)
{
	// To the cube.
	glPushMatrix();

		// Translate by the specified position.
		glTranslatef(position.getX(), position.getY(), position.getZ());

		int number_of_recursions = 3;
		float dimension_multiplier = 1.0f / (float)number_of_recursions;

		Vec2 recursive_dimension(dimension.getX() * dimension_multiplier, dimension.getY() * dimension_multiplier);

		// Modifying the cube.
		glPushMatrix();

			// FRONT AND BACK FACE.
			glPushMatrix();
			
				// To the front face.
				glPushMatrix();
			
					// Allows for recursive placement in the x axis.
					for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
					{
						// Allows for recursive placement in the y axis.
						for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
						{
							// Draws the front face of the cube with the normal parameters.
							DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));

							// Move the next quad up.
							glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
						}

						// Revert back down to the bottom row.
						glTranslatef(0.0f, -dimension.getY(), 0.0f);

						// Move the quad over.
						glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
					}

				// Back to the back face.
				glPopMatrix();

				// Moves the exact same face along the axis so it creates the back face.
				glTranslatef(0.0f, 0.0f, -dimension.getX());

				// To the back face.
				glPushMatrix();
			
					// Allows for recursive placement in the x axis.
					for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
					{
						// Allows for recursive placement in the y axis.
						for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
						{
							DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, -1.0f));

							// Move the next quad up.
							glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
						}

						// Revert back down to the bottom row.
						glTranslatef(0.0f, -dimension.getY(), 0.0f);

						// Move the quad over.
						glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
					}

				// Back to the back face.
				glPopMatrix();

			// Back to the cube structure.
			glPopMatrix();

			// Rotating to work with left and right faces.
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

			// LEFT AND RIGHT FACE.
			glPushMatrix();
			
				// To the left face.
				glPushMatrix();
			
					// Allows for recursive placement in the x axis.
					for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
					{
						// Allows for recursive placement in the y axis.
						for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
						{
							DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));

							// Move the next quad up.
							glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
						}

						// Revert back down to the bottom row.
						glTranslatef(0.0f, -dimension.getY(), 0.0f);

						// Move the quad over.
						glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
					}

				// Back to the right face.
				glPopMatrix();

				glTranslatef(0.0f, 0.0f, dimension.getX());

				// To the right face.
				glPushMatrix();
			
					// Allows for recursive placement in the x axis.
					for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
					{
						// Allows for recursive placement in the y axis.
						for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
						{
							DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, -1.0f));

							// Move the next quad up.
							glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
						}

						// Revert back down to the bottom row.
						glTranslatef(0.0f, -dimension.getY(), 0.0f);

						// Move the quad over.
						glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
					}

				// Back to the faces.
				glPopMatrix();

			// Back to the cube structure.
			glPopMatrix();

			// Rotating to work with top and bottom faces.
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// BOTTOM AND TOP FACE.
			glPushMatrix();

				if(!reflective)
				{
					// To the bottom face.
					glPushMatrix();
			
						// Allows for recursive placement in the x axis.
						for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
						{
							// Allows for recursive placement in the y axis.
							for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
							{
								DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

								// Move the next quad up.
								glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
							}

							// Revert back down to the bottom row.
							glTranslatef(0.0f, -dimension.getY(), 0.0f);

							// Move the quad over.
							glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
						}

					// Back to the faces.
					glPopMatrix();
				}

				glTranslatef(0.0f, 0.0f, -dimension.getX());

				// To the top face.
				glPushMatrix();
			
					// Allows for recursive placement in the x axis.
					for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
					{
						// Allows for recursive placement in the y axis.
						for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
						{
							DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

							// Move the next quad up.
							glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
						}

						// Revert back down to the bottom row.
						glTranslatef(0.0f, -dimension.getY(), 0.0f);

						// Move the quad over.
						glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
					}

				// Back to the faces.
				glPopMatrix();

			// Back to the cube structure.
			glPopMatrix();

		// Back to the cube.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}

void Shape::DrawRoomCube(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, int recursions, bool reflective, bool has_front_door, bool has_leftside_door, bool has_back_door, bool has_rightside_door, bool has_front_window, bool has_left_window, bool has_back_window, bool has_right_window, bool has_upstairs_access, bool has_downstairs_access)
{
	// To the cube.
	glPushMatrix();

		// Translate by the specified position.
		glTranslatef(position.getX(), position.getY(), position.getZ());

		//int number_of_recursions = recursions;
		float dimension_multiplier = 1.0f / static_cast<float>(recursions);

		Vec2 recursive_dimension(dimension.getX() * dimension_multiplier, dimension.getY() * dimension_multiplier);

		// Modifying the cube.
		glPushMatrix();

			// FRONT AND BACK FACE.
			glPushMatrix();
			
				// To the front face.
				glPushMatrix();
					
					// If the room needs a front door.
					// Creates a gap in the correct place of the wall for a doorway.
					if(has_front_door)
					{
						// Allows for recursive placement in the x axis.
						for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
						{
							// Allows for recursive placement in the y axis.
							for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
							{
								// If the quad is in the desired location.
								if((x == dimension_multiplier) && (y == 0.0f))
								{
								}
								// Otherwise, it is not in the desired position so just draw the normal surface.
								else
								{
									// Draw the walls.
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
								}
							
								// Move the next quad up.
								glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
							}

							// Revert back down to the bottom row.
							glTranslatef(0.0f, -dimension.getY(), 0.0f);

							// Move the quad over.
							glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
						}
					}
					// Otherwise, there is no need for a doorway.
					else
					{
						// If there is a window on this face.
						if(has_front_window)
						{
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// If the quad is in the desired location.
									if((x == dimension_multiplier) && (y == dimension_multiplier))
									{
										//glEnable(GL_BLEND);
										//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
										
										// Using the window texture.
										BindTexture(window_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										// Drawing a window.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));

										// Reapplying the wallpaper texture.
										BindTexture(fabric_wallpaper_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										//glDisable(GL_BLEND);
									}
									// Otherwise, it is not in the desired position so just draw the normal surface.
									else
									{
										// Draw the walls.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
									}

									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
						// Otherwise, there is no window on this face.
						else
						{
							// Allows for recursive placement in the x axis.
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								// Allows for recursive placement in the y axis.
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// Draws the front face of the cube with the normal parameters.
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
							
									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
					}

				// Back to the back face.
				glPopMatrix();

				// Moves the exact same face along the axis so it creates the back face.
				glTranslatef(0.0f, 0.0f, -dimension.getX());

				// To the back face.
				glPushMatrix();
			
					// If the room needs a back door.
					// Creates a gap in the correct place of the wall for a doorway.
					if(has_back_door)
					{
						// Allows for recursive placement in the x axis.
						for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
						{
							// Allows for recursive placement in the y axis.
							for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
							{
								// If the quad is in the desired location.
								if((x == dimension_multiplier) && (y == 0.0f))
								{
								}
								// Otherwise, it is not in the desired location.
								else
								{
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
								}

								// Move the next quad up.
								glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
							}

							// Revert back down to the bottom row.
							glTranslatef(0.0f, -dimension.getY(), 0.0f);

							// Move the quad over.
							glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
						}
					}
					// Otherwise, there is no need for a doorway.
					else
					{
						// If there is a window on this face.
						if(has_back_window)
						{
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// If the quad is in the desired location.
									if((x == dimension_multiplier) && (y == dimension_multiplier))
									{
										//glEnable(GL_BLEND);

										// Using the window texture.
										BindTexture(window_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										// Drawing a window.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));

										// Reapplying the wallpaper texture.
										BindTexture(fabric_wallpaper_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										//glDisable(GL_BLEND);
									}
									// Otherwise, it is not in the desired position so just draw the normal surface.
									else
									{
										// Draw the walls.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
									}

									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
						// Otherwise, there is no window on this face.
						else
						{
							// Allows for recursive placement in the x axis.
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								// Allows for recursive placement in the y axis.
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// Draws the front face of the cube with the normal parameters.
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
							
									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
					}

				// Back to the back face.
				glPopMatrix();

			// Back to the cube structure.
			glPopMatrix();

			// Rotating to work with left and right faces.
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

			// LEFT AND RIGHT FACE.
			glPushMatrix();
			
				// To the left face.
				glPushMatrix();
			
					// If the room needs a left door.
					// Creates a gap in the correct place of the wall for a doorway.
					if(has_leftside_door)
					{
						// Allows for recursive placement in the x axis.
						for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
						{
							// Allows for recursive placement in the y axis.
							for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
							{
								// If the quad is in the desired location.
								if((x == dimension_multiplier) && (y == 0.0f))
								{
								}
								// Otherwise, it is not in the desired location.
								else
								{
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
								}

								// Move the next quad up.
								glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
							}

							// Revert back down to the bottom row.
							glTranslatef(0.0f, -dimension.getY(), 0.0f);

							// Move the quad over.
							glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
						}
					}
					// Otherwise, there is no need for a doorway.
					else
					{
						// If there is a window on this face.
						if(has_left_window)
						{
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// If the quad is in the desired location.
									if((x == dimension_multiplier) && (y == dimension_multiplier))
									{
										//glEnable(GL_BLEND);

										// Using the window texture.
										BindTexture(window_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										// Drawing a window.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));

										// Reapplying the wallpaper texture.
										BindTexture(fabric_wallpaper_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										//glDisable(GL_BLEND);
									}
									// Otherwise, it is not in the desired position so just draw the normal surface.
									else
									{
										// Draw the walls.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
									}

									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
						// Otherwise, there is no window on this face.
						else
						{
							// Allows for recursive placement in the x axis.
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								// Allows for recursive placement in the y axis.
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// Draws the front face of the cube with the normal parameters.
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
							
									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
					}

				// Back to the right face.
				glPopMatrix();

				glTranslatef(0.0f, 0.0f, dimension.getX());

				// To the right face.
				glPushMatrix();
			
					// If the room needs a right door.
					// Creates a gap in the correct place of the wall for a doorway.
					if(has_rightside_door)
					{
						// Allows for recursive placement in the x axis.
						for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
						{
							// Allows for recursive placement in the y axis.
							for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
							{
								// If the quad is in the desired location.
								if((x == dimension_multiplier) && (y == 0.0f))
								{
								}
								// Otherwise, it is not in the desired location.
								else
								{
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
								}

								// Move the next quad up.
								glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
							}

							// Revert back down to the bottom row.
							glTranslatef(0.0f, -dimension.getY(), 0.0f);

							// Move the quad over.
							glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
						}
					}
					// Otherwise, there is no need for a doorway.
					else
					{
						// If there is a window on this face.
						if(has_right_window)
						{
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// If the quad is in the desired location.
									if((x == dimension_multiplier) && (y == dimension_multiplier))
									{
										//glEnable(GL_BLEND);

										// Using the window texture.
										BindTexture(window_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										// Drawing a window.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));

										// Reapplying the wallpaper texture.
										BindTexture(fabric_wallpaper_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
									
										//glDisable(GL_BLEND);
									}
									// Otherwise, it is not in the desired position so just draw the normal surface.
									else
									{
										// Draw the walls.
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
									}

									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
						// Otherwise, there is no window on this face.
						else
						{
							// Allows for recursive placement in the x axis.
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								// Allows for recursive placement in the y axis.
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									// Draws the front face of the cube with the normal parameters.
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 0.0f, 1.0f));
							
									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
					}

				// Back to the faces.
				glPopMatrix();

			// Back to the cube structure.
			glPopMatrix();

			// Rotating to work with top and bottom faces.
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// BOTTOM AND TOP FACE.
			glPushMatrix();

				if(!reflective)
				{
					// To the bottom face.
					glPushMatrix();
						
						if(has_downstairs_access)
						{
							// Allows for recursive placement in the x axis.
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								// Allows for recursive placement in the y axis.
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									if((x == dimension_multiplier * 2.0f) && (y != 0.0f))
									{
										// Leave a space for the stairs.
									}
									else
									{
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
									}

									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}
						else
						{
							// Allows for recursive placement in the x axis.
							for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
							{
								// Allows for recursive placement in the y axis.
								for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
								{
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
									
									// Move the next quad up.
									glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
								}

								// Revert back down to the bottom row.
								glTranslatef(0.0f, -dimension.getY(), 0.0f);

								// Move the quad over.
								glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
							}
						}

					// Back to the faces.
					glPopMatrix();
				}

				glTranslatef(0.0f, 0.0f, -dimension.getX());

				// To the top face.
				glPushMatrix();
			
					if(has_upstairs_access)
					{
						// Allows for recursive placement in the x axis.
						for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
						{
							// Allows for recursive placement in the y axis.
							for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
							{
								if((x != 0.0f) && (y == (dimension_multiplier * 2.0f)))
								{
									if(x == dimension_multiplier)
									{
										BindTexture(ladder_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
										glTranslatef(0.0f, 0.0f, -0.01f);
										glScalef(1.0f, 1.0f, 3.0f);
										glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
										DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
										
										BindTexture(fabric_wallpaper_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
										glRotatef(-270.0f, 0.0f, 1.0f, 0.0f);
									}
								}
								else
								{
									DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));
								}

								// Move the next quad up.
								glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
							}

							// Revert back down to the bottom row.
							glTranslatef(0.0f, -dimension.getY(), 0.0f);

							// Move the quad over.
							glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
						}
					}
					else
					{
						// Allows for recursive placement in the x axis.
						for(float x = 0.0f; x < 1.0f; x += dimension_multiplier)
						{
							// Allows for recursive placement in the y axis.
							for(float y = 0.0f; y < 1.0f; y += dimension_multiplier)
							{
								DrawQuad(position, recursive_dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

								// Move the next quad up.
								glTranslatef(0.0f, recursive_dimension.getY(), 0.0f);
							}

							// Revert back down to the bottom row.
							glTranslatef(0.0f, -dimension.getY(), 0.0f);

							// Move the quad over.
							glTranslatef(recursive_dimension.getX(), 0.0f, 0.0f);
						}
					}

				// Back to the faces.
				glPopMatrix();

			// Back to the cube structure.
			glPopMatrix();

		// Back to the cube.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}


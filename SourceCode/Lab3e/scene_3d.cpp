#include "scene_3d.h"

bool Scene3D::CreatePixelFormat(HDC hdc) 
{ 
    PIXELFORMATDESCRIPTOR pfd = {0}; 
    int pixelformat; 
 
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);	// Set the size of the structure
    pfd.nVersion = 1;							// Always set this to 1
	// Pass in the appropriate OpenGL flags
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.dwLayerMask = PFD_MAIN_PLANE;			// standard mask (this is ignored anyway)
    pfd.iPixelType = PFD_TYPE_RGBA;				// RGB and Alpha pixel type
    pfd.cColorBits = COLOUR_DEPTH;				// Here we use our #define for the color bits
    pfd.cDepthBits = COLOUR_DEPTH;				// Ignored for RBA
    pfd.cAccumBits = 0;							// nothing for accumulation
    pfd.cStencilBits = COLOUR_DEPTH;			// nothing for stencil
 
	//Gets a best match on the pixel format as passed in from device
    if ( (pixelformat = ChoosePixelFormat(hdc, &pfd)) == false ) 
    { 
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
 
	//sets the pixel format if its ok. 
    if (SetPixelFormat(hdc, pixelformat, &pfd) == false) 
    { 
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
 
    return true;
}

void Scene3D::ResizeGLWindow(int width, int height)// Initialize The GL Window
{
	if (height==0)// Prevent A Divide By Zero error
	{
		height=1;// Make the Height Equal One
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//calculate aspect ratio
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 1 ,150.0f);
	
	glMatrixMode(GL_MODELVIEW);// Select The Modelview Matrix
	glLoadIdentity();// Reset The Modelview Matrix
}

void Scene3D::InitializeOpenGL(int width, int height) 
{  
    hdc_ = GetDC(*hwnd_);//  sets  global HDC

    if (!CreatePixelFormat(hdc_))//  sets  pixel format
        PostQuitMessage (0);

    hrc_ = wglCreateContext(hdc_);	//  creates  rendering context from  hdc
    wglMakeCurrent(hdc_, hrc_);		//	Use this HRC.

	ResizeGLWindow(width, height);	// Setup the Screen
}

void Scene3D::Init(HWND* wnd, Input* in, Camera* cam)
{
	// Setting up pointer variables.
	hwnd_ = wnd;
	input_ = in;
	camera_ = cam;
	current_camera_ = camera_;

	GetClientRect(*hwnd_, &screen_rect_);	//get rect into our handy global rect
	InitializeOpenGL(screen_rect_.right, screen_rect_.bottom); // initialise openGL

	//OpenGL settings
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Grey Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Setting how to clear the buffer.
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_COLOR_MATERIAL);						
	glEnable(GL_TEXTURE);								// Enabling texture features.
	glEnable(GL_TEXTURE_2D);							
	glEnable(GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// Initialising local variables.
	wireframe_ = false;
	speed_ = 15.0f;
	camera_speed_ = 25.0f;
	point_light_x_ = 0.0f;
	point_light_y_ = 0.0f;
	
	// Initialising all of the cameras in the scene.
	camera_->Init(Vec3(15.0f, 10.0f, 10.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_livingroom_.Init(Vec3(5.0f, 5.0f, -5.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_backroom_.Init(Vec3(5.0f, 5.0f, -14.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_hallway_.Init(Vec3(20.0f, 5.0f, -5.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_kitchen_.Init(Vec3(20.0f, 5.0f, -14.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_masterbedroom_.Init(Vec3(5.0f, 18.0f, -5.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_bedroom_.Init(Vec3(5.0f, 18.0f, -14.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_landing_.Init(Vec3(20.0f, 18.0f, -5.0f), Vec3(1.0f, 1.0f, 1.0f));
	camera_bathroom_.Init(Vec3(20.0f, 18.0f, -14.0f), Vec3(1.0f, 1.0f, 1.0f));

	// Setting up screen centre points.
	centre_screen_.setX(screen_rect_.right/2);
	centre_screen_.setY(screen_rect_.bottom/2);

	// Scene initialisations.
	sky_ = skybox_.TextureInit("Converted_Textures/Skybox.png");
	farm_.Init();
}

void Scene3D::CreateLighting()
{
	// Adding in ambient lighting for the scene objects.
	ambient_light_.Init(Vec3(0.4f, 0.4f, 0.4f), Vec3(0.0f, 0.0f, 0.0f), Vec3(1.0f, 1.0f, 1.0f));
}

void Scene3D::CreateSkybox()
{
	skybox_.BindTexture(sky_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
	skybox_.Init(Vec3(-0.5f, -0.5f, -0.5f), Vec3(camera_->GetCameraX(), camera_->GetCameraY(), camera_->GetCameraZ()));
}

void Scene3D::DrawScene(float dt) 
{
	// Updates input.
	HandleInput(dt);
	
	// Clear The Screen And The Depth Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glLoadIdentity();// load Identity Matrix

	// Set camera looking at points.
	// Where we are, What we look at, and which way is up
	gluLookAt(current_camera_->GetCameraX(), current_camera_->GetCameraY(), current_camera_->GetCameraZ(),
			  current_camera_->GetLookAtX(), current_camera_->GetLookAtY(), current_camera_->GetLookAtZ(), 
			  current_camera_->GetUpPointX(), current_camera_->GetUpPointY(), current_camera_->GetUpPointZ());

	// Lighting.
	CreateLighting();

	// Skybox.
	CreateSkybox();

	// Render the farm and everthing else.
	farm_.Render(Vec3(0.0f, 0.0f, 0.0f), Vec2(75.0f, 75.0f), Vec2(0.0f, 0.0f), Vec2(1.0f, 1.0f), Vec3(0.0f, 1.0f, 0.0f), 10, CheckCameraPosition(Vec3(-20.0f, 0.0f, -40.0f), Vec3(25.0f, 37.0f, 0.0f)));

	// Wireframe mode.
	if(wireframe_ == true)
	{
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);
	}

	SwapBuffers(hdc_);// Swap the frame buffers.
}	

void Scene3D::Resize()
{
	if(hwnd_ == NULL)
		return;

	GetClientRect(*hwnd_, &screen_rect_);	
	ResizeGLWindow(screen_rect_.right, screen_rect_.bottom);	
}

bool Scene3D::CheckCameraPosition(Vec3 lower_bound, Vec3 upper_bound)
{
	// 3D collision check.
	// If the user is NOT inside of the 3D space defined.
	if(((current_camera_->GetCameraX() > lower_bound.getX()) && (current_camera_->GetCameraX() < upper_bound.getX()))
		&& ((current_camera_->GetCameraY() > lower_bound.getY()) && (current_camera_->GetCameraY() < upper_bound.getY()))
		&& ((current_camera_->GetCameraZ() > lower_bound.getZ()) && (current_camera_->GetCameraZ() < upper_bound.getZ())))
	{
		// The user is not inside of the boundaries defined.
		return false;
	}

	// Otherwise, the user is inside of the boundaries.
	return true;
}

void Scene3D::CheckCameras()
{
	// Switching cameras.
	if(input_->IsKeyDown('1'))
	{
		// Switching cameras to the living room.
		current_camera_ = &camera_livingroom_;
	}
	else if(input_->IsKeyDown('2'))
	{
		// Switching the camera to the backroom.
		current_camera_ = &camera_backroom_;
	}
	else if(input_->IsKeyDown('3'))
	{
		// Switching the camera to the hallway.
		current_camera_ = &camera_hallway_;
	}
	else if(input_->IsKeyDown('4'))
	{
		// Switching the camera to the kitchen.
		current_camera_ = &camera_kitchen_;
	}
	else if(input_->IsKeyDown('5'))
	{
		// Switching the camera to the master bedroom.
		current_camera_ = &camera_masterbedroom_;
	}
	else if(input_->IsKeyDown('6'))
	{
		// Switching the camera to the bedroom.
		current_camera_ = &camera_bedroom_;
	}
	else if(input_->IsKeyDown('7'))
	{
		// Switching the camera to the landing.
		current_camera_ = &camera_landing_;
	}
	else if(input_->IsKeyDown('8'))
	{
		// Switching the camera to the bathroom.
		current_camera_ = &camera_bathroom_;
	}
	else if(input_->IsKeyDown('0'))
	{
		// Switching the camera back to the main camera.
		current_camera_ = camera_;
	}
}

void Scene3D::HandleInput(float dt)
{
	// Setting the windmill in motion.
	farm_.windmill_.fan_rotation_+=0.5f;

	// Checking to see if the user has switched cameras.
	CheckCameras();

	// Setting up mouse controls.
	// Calculates the drag distance of the mouse.
	delta_position_.setX(input_->GetMouseX() - centre_screen_.getX());
	delta_position_.setY(centre_screen_.getY() - input_->GetMouseY());

	// WINDMILL CONTROLS.
	// User interaction.
	if(input_->IsKeyDown(VK_RIGHT))
	{
		// Turns the fan to the right.
		farm_.windmill_.fan_rotation_--;

		if(input_->IsKeyDown(VK_SHIFT))
		{
			farm_.windmill_.fan_rotation_ -= 5.0f;
		}
	}
	else if(input_->IsKeyDown(VK_LEFT))
	{
		// Turns the fan to the left.
		farm_.windmill_.fan_rotation_++;

		if(input_->IsKeyDown(VK_SHIFT))
		{
			farm_.windmill_.fan_rotation_ += 5.0f;
		}
	}

	// POINT LIGHT CONTROLS.
	float x = farm_.point_light_position_.getX();
	float y = farm_.point_light_position_.getY();
	float z = farm_.point_light_position_.getZ();
	
	if(input_->IsKeyDown(VK_NUMPAD4))
	{
		//float x = farm_.point_light_position_.getX();
		farm_.point_light_position_.setX(x -= 0.1f);
	}
	else if(input_->IsKeyDown(VK_NUMPAD6))
	{
		//float x = farm_.point_light_position_.getX();
		farm_.point_light_position_.setX(x += 0.1f);
	}

	if(input_->IsKeyDown(VK_NUMPAD9))
	{
		//float y = farm_.point_light_position_.getY();
		farm_.point_light_position_.setY(y += 0.1f);
	}
	else if (input_->IsKeyDown(VK_NUMPAD7))
	{
		//float y = farm_.point_light_position_.getY();
		farm_.point_light_position_.setY(y -= 0.1f);
	}
	
	if(input_->IsKeyDown(VK_NUMPAD8))
	{
		//float z = farm_.point_light_position_.getZ();
		farm_.point_light_position_.setZ(z -= 0.1f);
	}
	else if(input_->IsKeyDown(VK_NUMPAD2))
	{
		//float z = farm_.point_light_position_.getZ();
		farm_.point_light_position_.setZ(z += 0.1f);
	}
	
	// WIREFRAME CONTROLS.
	// Turning wireframe mode on.
	if(input_->IsKeyDown('C'))
	{
		wireframe_ = true;
	}
	// Turning wireframe mode on.
	else if(input_->IsKeyDown('V'))
	{
		wireframe_ = false;
	}
	
	// CAMERA CONTROLS.
	// Moving the camera left and right.
	if(input_->IsKeyDown('D'))
	{
		if(current_camera_ == camera_)
		{
			current_camera_->MoveCameraX(dt * speed_);
		}
	}
	else if(input_->IsKeyDown('A'))
	{
		if(current_camera_ == camera_)
		{
			current_camera_->MoveCameraX(-dt * speed_);
		}
	}

	// Moving the camera up and down.
	if(input_->IsKeyDown('Q'))
	{
		if(current_camera_ == camera_)
		{
			current_camera_->MoveCameraY(dt * speed_);
		}
	}
	else if(input_->IsKeyDown('E'))
	{
		if(current_camera_ == camera_)
		{
			current_camera_->MoveCameraY(-dt * speed_);
		}
	}

	// Moving the camera forwards and backwards.
	if(input_->IsKeyDown('W'))
	{
		if(current_camera_ == camera_)
		{
			current_camera_->MoveCameraZ(dt * speed_);
		}
	}
	else if(input_->IsKeyDown('S'))
	{
		if(current_camera_ == camera_)
		{
			current_camera_->MoveCameraZ(-dt * speed_);
		}
	}

	// Editing Pitch.
	if(delta_position_.getY() != 0.0f)
	{
		current_camera_->MoveCameraPitch(delta_position_.getY() * dt * camera_speed_);
	}

	// Editing Yaw.
	if(delta_position_.getX() != 0.0f)
	{
		current_camera_->MoveCameraYaw(delta_position_.getX() * dt * camera_speed_);
	}

	// Editing Roll.
	if(input_->IsKeyDown('O'))
	{
		current_camera_->MoveCameraRoll(-dt * speed_);
	}
	else if(input_->IsKeyDown('U'))
	{
		current_camera_->MoveCameraRoll(dt * speed_);
	}

	// Resetting the cursors position to the centre of the screen.
	centre_.x = centre_screen_.getX();
	centre_.y = centre_screen_.getY();

	ClientToScreen(*hwnd_, &centre_);
	SetCursorPos(centre_.x, centre_.y);

	current_camera_->Update();
}

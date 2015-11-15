// Jason Mottershead, Student Number 1300455.

// Scene class header file.
// Here is where all of the objects will come together.

// Header guard.
#ifndef SCENE3D_H
#define SCENE3D_H

// Include files here.
#include "ambient_light.h"
#include "point_light.h"
#include "camera.h"
#include "input.h"
#include "skybox.h"
#include "model.h"
#include "field.h"

// Macro for defining the colour depth.
#define COLOUR_DEPTH 16

class Scene3D
{
	public:
		// Methods.
		void Init(HWND* wnd, Input* in, Camera* cam);
		void DrawScene(float dt);
		void Resize();

	private:
		// Attributes.
		bool wireframe_;
		float speed_, camera_speed_;
		float point_light_x_, point_light_y_;
		POINT centre_;
		HWND* hwnd_;
		RECT screen_rect_;
		HDC	hdc_;
		HGLRC hrc_;			//hardware RENDERING CONTEXT
		GLuint sky_;
		Vec2 delta_position_, centre_screen_;
		AmbientLight ambient_light_;
		PointLight point_light_;
		Input* input_;
		Camera* camera_;
		Camera* current_camera_;
		Camera camera_livingroom_, camera_backroom_, camera_hallway_, camera_kitchen_, camera_landing_, camera_bathroom_, camera_masterbedroom_, camera_bedroom_;
		Field farm_;
		Skybox skybox_;

		// Methods.
		void CreateLighting();
		void CreateSkybox();
		void CreateFog();
		bool CreatePixelFormat(HDC hdc);
		void ResizeGLWindow(int width, int height);
		void InitializeOpenGL(int width, int height);
		bool CheckCameraPosition(Vec3 lower_bound, Vec3 upper_bound);
		void CheckCameras();
		void HandleInput(float dt);
};

#endif
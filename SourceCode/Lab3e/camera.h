// Jason Mottershead, Student Number 1300455.

// Camera class header file.
// The camera class will provide user input functionality.
// The user will be able to control the camera via mouse and keyboard.

//////////////////////////////////////////////////////////////////
//			To do:												//
//				 - Add in mouse controls for the camera.		//
//////////////////////////////////////////////////////////////////

// Header guard.
#ifndef _CAMERA_H_
#define _CAMERA_H_

// Include files here.
#include <math.h>
#include "vec3.h"

class Camera
{
	public:
		// Methods.
		Camera();
		~Camera();
		void Init(Vec3 position, Vec3 rotation);
		void Update();

		// Setters.
		// Setting the x position of the camera.
		inline void SetCameraX(float& x) { camera_position_.setX(x); };

		// Setting the y position of the camera.
		inline void SetCameraY(float& y) { camera_position_.setY(y); };

		// Setting the z position of the camera.
		inline void SetCameraZ(float& z) { camera_position_.setZ(z); };

		// This will move the camera along the x axis at a specified speed.
		inline void MoveCameraX(float speed)			{ camera_position_ += (right_ *= speed); };

		// This will move the camera along the y axis at a specified speed.
		inline void MoveCameraY(float speed)			{ camera_position_ += (upwards_point_ *= speed); };

		// This will move the camera along the z axis at a specified speed.
		inline void MoveCameraZ(float speed)			{ camera_position_ += (forward_point_ *= speed); };

		// This will rotate the camera around the x axis at a specified angle.
		inline void MoveCameraPitch(float move_pitch)	{ camera_rotation_.setX(camera_rotation_.getX() + move_pitch); };

		// This will rotate the camera around the y axis at a specified angle.
		inline void MoveCameraYaw(float move_yaw)		{ camera_rotation_.setY(camera_rotation_.getY() + move_yaw); };

		// This will rotate the camera around the z axis at a specified angle.
		inline void MoveCameraRoll(float move_roll)		{ camera_rotation_.setZ(camera_rotation_.getZ() + move_roll); };

		// This will return the x position of the camera.
		inline float GetCameraX()	{ return camera_position_.getX(); };

		// This will return the y position of the camera.
		inline float GetCameraY()	{ return camera_position_.getY(); };

		// This will return the z position of the camera.
		inline float GetCameraZ()	{ return camera_position_.getZ(); };

		// This will return the look at point for the camera for the x axis.
		inline float GetLookAtX()	{ return camera_position_.getX() + forward_point_.getX(); };

		// This will return the look at point for the camera for the y axis.
		inline float GetLookAtY()	{ return camera_position_.getY() + forward_point_.getY(); };

		// This will return the look at point for the camera for the z axis.
		inline float GetLookAtZ()	{ return camera_position_.getZ() + forward_point_.getZ(); };

		// This will return the upwards point for the camera for the x axis.
		inline float GetUpPointX()	{ return upwards_point_.getX(); };

		// This will return the upwards point for the camera for the y axis.
		inline float GetUpPointY()	{ return upwards_point_.getY(); };

		// This will return the upwards point for the camera for the z axis.
		inline float GetUpPointZ()	{ return upwards_point_.getZ(); };

		inline float GetCameraPitch() { return camera_rotation_.getX(); };

		inline float GetCameraYaw() { return camera_rotation_.getY(); };

	private:
		// Attributes.
		Vec3 cos_;
		Vec3 sin_;
		Vec3 camera_position_;
		Vec3 camera_rotation_;
		Vec3 forward_point_;
		Vec3 upwards_point_;
		Vec3 right_;
};

#endif
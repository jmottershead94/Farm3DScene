#include "camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Init(Vec3 position, Vec3 rotation)
{
	// Setting the initial position on the camera.
	camera_position_.setX(position.getX());
	camera_position_.setY(position.getY());
	camera_position_.setZ(position.getZ());

	// Setting the initial rotation of the camera.
	camera_rotation_.setX(rotation.getX());
	camera_rotation_.setY(rotation.getY());
	camera_rotation_.setZ(rotation.getZ());
}

void Camera::Update()
{
	// Calculating rotations for the camera.
	cos_.setX(cosf(camera_rotation_.getX() * PI / 180.0f));
	cos_.setY(cosf(camera_rotation_.getY() * PI / 180.0f));
	cos_.setZ(cosf(camera_rotation_.getZ() * PI / 180.0f));

	// Calculating rotations for the camera.
	sin_.setX(sinf(camera_rotation_.getX() * PI / 180.0f));
	sin_.setY(sinf(camera_rotation_.getY() * PI / 180.0f));
	sin_.setZ(sinf(camera_rotation_.getZ() * PI / 180.0f));

	// Calculating the forward vector.
	forward_point_.setX(sin_.getY() * cos_.getX());
	forward_point_.setY(sin_.getX());
	forward_point_.setZ(cos_.getX() * -cos_.getY());

	// Calculating the upwards vector.
	upwards_point_.setX(-cos_.getY() * sin_.getZ() - sin_.getY() * sin_.getX() * cos_.getZ());
	upwards_point_.setY(cos_.getX() * cos_.getZ());
	upwards_point_.setZ(-sin_.getY() * sin_.getZ() - sin_.getX() * cos_.getZ() * -cos_.getY());

	// Calculating the right vector.
	right_ = forward_point_.cross(upwards_point_);
}
#include "input.h"

Input::Input()
{
	mouse_.x_ = 0;
	mouse_.y_ = 0;
	mouse_.left_ = false;
	mouse_.double_left_ = false;
	mouse_.right_ = false;
	mouse_.double_right_ = false;
	mouse_.middle_ = false;
	mouse_.double_middle_ = false;
	resp_ = 0;
}

Input::~Input()
{
}

void Input::SetKeyDown(int key)
{
	keys_[key] = true;
}

void Input::SetKeyUp(int key)
{
	keys_[key] = false;
}

void Input::SetMouseX(int pos)
{
	mouse_.x_ = pos;
}

void Input::SetMouseY(int pos)
{
	mouse_.y_ = pos;
}

void Input::LeftMousePressed()
{
	mouse_.left_ = true;
}

void Input::LeftMouseReleased()
{
	mouse_.left_ = false;
}

void Input::LeftDoubleMouse()
{
	mouse_.double_left_ = true;
}

void Input::LeftDoubleMouseRelease()
{
	mouse_.double_left_ = false;
}

void Input::RightMousePressed()
{
	mouse_.right_ = true;
}

void Input::RightMouseReleased()
{
	mouse_.right_ = false;
}

void Input::RightDoubleMouse()
{
	mouse_.double_right_ = true;
}

void Input::RightDoubleMouseRelease()
{
	mouse_.double_right_ = false;
}

void Input::MiddleMousePressed()
{
	mouse_.middle_ = true;
}

void Input::MiddleMouseReleased()
{
	mouse_.middle_ = false;
}

void Input::MiddleDoubleMouse()
{
	mouse_.double_middle_ = true;
}

void Input::MiddleDoubleMouseRelease()
{
	mouse_.double_middle_ = false;
}

bool Input::IsKeyDown(WPARAM key)
{
	return keys_[key];
}

int Input::GetMouseX()
{
	return mouse_.x_;
}

int Input::GetMouseY()
{
	return mouse_.y_;
}
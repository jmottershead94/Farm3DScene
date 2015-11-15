// Jason Mottershead, Student Number 1300455.

// Input class header file.
// This is where all of the user input is defined.
// Keyboard presses to mouse clicks.

#ifndef _INPUT_H_
#define _INPUT_H_

#include <windows.h>

class Input
{
	// Attributes.
	public:
		typedef struct Mouse
		{
			int x_, y_;
			bool left_, right_, middle_, double_left_, double_right_, double_middle_;
		};
		int resp_;
		Mouse mouse_;

	private:
		bool keys_[256];

	// Methods.
	public:
		Input();
		~Input();
		void SetKeyDown(int);
		void SetKeyUp(int);
		void SetMouseX(int);
		void SetMouseY(int);
		void LeftMousePressed();
		void LeftMouseReleased();
		void LeftDoubleMouse();
		void LeftDoubleMouseRelease();
		void RightMousePressed();
		void RightMouseReleased();
		void RightDoubleMouse();
		void RightDoubleMouseRelease();
		void MiddleMousePressed();
		void MiddleMouseReleased();
		void MiddleDoubleMouse();
		void MiddleDoubleMouseRelease();
		bool IsKeyDown(WPARAM);
		int GetMouseX();
		int GetMouseY();
};

#endif
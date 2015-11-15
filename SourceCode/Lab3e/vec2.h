// Jason Mottershead, Student Number 1300455.

// Vec2 class header file.
// Copied Pauls Vec3 class.
// This class will enable me to store texture coordinates, and general dimensions (width and height).

// Header guard.
#ifndef _VEC2_H_
#define _VEC2_H_

// Include files here.
#include <cmath>
#include <iostream>

class Vec2
{
	public:
		// Methods.
		Vec2(float x = 0, float y = 0);
		~Vec2();
		Vec2 copy();
 
		Vec2& set(float x, float y);
		Vec2& setX(float x);
		Vec2& setY(float y);

		float getX();
		float getY();
 
		Vec2 add(const Vec2& v1, float scale=1.0);
		Vec2 subtract(const Vec2& v1, float scale=1.0);
		Vec2 scale(float scale);
 
		float dot(const Vec2& v2);
		Vec2 cross(const Vec2& v2);
 
		Vec2& normalize();
		float length();
		float lengthSquared();
 
		bool equals(const Vec2& v2, float epsilon);
		float operator[](int pos) const;
 
		Vec2 operator+(const Vec2& v2);
		Vec2 operator-(const Vec2& v2);
 
		Vec2& operator+=(const Vec2& v2);
		Vec2& operator-=(const Vec2& v2);
		Vec2& operator*=(const float f);

	private:
		// Attributes.
		float elements_[2];
};

#endif
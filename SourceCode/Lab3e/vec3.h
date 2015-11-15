// Dr Paul Robertson

// Vec3 class header file.
// This class will enable me to store data for 3 dimensional values (e.g. x, y, z).
// Different functions for cross product, normalising etc.

// Header guard.
#ifndef _VEC3_H_
#define _VEC3_H_

// Include files here.
#include <cmath>
#include <iostream>

// Macro for defining PI.
#define PI 3.1415926535897932384626433832795

class Vec3
{
	public:
		// Methods.
		Vec3(float x = 0, float y = 0, float z = 0);
		~Vec3();
		Vec3 copy();
 
		Vec3& set(float x, float y, float z);
		Vec3& setX(float x);
		Vec3& setY(float y);
		Vec3& setZ(float z);

		float getX();
		float getY();
		float getZ();
 
		Vec3 add(const Vec3& v1, float scale=1.0);
		Vec3 subtract(const Vec3& v1, float scale=1.0);
		Vec3 scale(float scale);
 
		float dot(const Vec3& v2);
		Vec3 cross(const Vec3& v2);
 
		Vec3& normalize();
		float length();
		float lengthSquared();
 
		bool equals(const Vec3& v2, float epsilon);
		float operator[](int pos) const;
 
		Vec3 operator+(const Vec3& v2);
		Vec3 operator-(const Vec3& v2);
 
		Vec3& operator+=(const Vec3& v2);
		Vec3& operator-=(const Vec3& v2);

		// Added by me, I think.
		// It is used in the camera class.
		Vec3& operator*=(const float f);

	private:
		// Attributes.
		float elements_[3];
};

#endif
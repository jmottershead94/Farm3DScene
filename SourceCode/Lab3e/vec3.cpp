#include "vec3.h"
 
Vec3::Vec3(float x, float y, float z)
{
    this->elements_[0] = x;
    this->elements_[1] = y;
    this->elements_[2] = z;
}
 
Vec3::~Vec3()
{
}
 
Vec3 Vec3::copy()
{
    Vec3 copy
	(
        this->elements_[0],
        this->elements_[1],     
        this->elements_[2]
    );

    return copy;           
}
 
bool Vec3::equals(const Vec3& v2, float epsilon)
{
    return (
			(std::abs(this->elements_[0] - v2[0]) < epsilon) &&
            (std::abs(this->elements_[1] - v2[1]) < epsilon) &&
            (std::abs(this->elements_[2] - v2[2]) < epsilon)
		   );      
}
 
 
float Vec3::length()
{
    return std::sqrt(this->lengthSquared());
}
 
float Vec3::lengthSquared()
{
    return (
            this->elements_[0]*this->elements_[0] +
            this->elements_[1]*this->elements_[1] +
            this->elements_[2]*this->elements_[2]
           );
}
 
Vec3& Vec3::normalize()
{
    float mag = this->length();

    if(mag)
	{
        float multiplier = 1.0f/mag;
        this->elements_[0] *= multiplier;
        this->elements_[1] *= multiplier;
        this->elements_[2] *= multiplier;
    }

    return *this;
}
 
Vec3 Vec3::cross(const Vec3& v2)
{
    Vec3 cross
	(
        (this->elements_[1] * v2[2] - this->elements_[2] * v2[1]),
        (this->elements_[2] * v2[0] - this->elements_[0] * v2[2]),
        (this->elements_[0] * v2[1] - this->elements_[1] * v2[0])
    );

    return cross;
}
 
Vec3 Vec3::subtract(const Vec3& v1, float scale)
{
    Vec3 sub
	(
		(this->elements_[0] - v1[0]*scale),
		(this->elements_[1] - v1[1]*scale),
		(this->elements_[2] - v1[2]*scale)
    );

    return sub;
}
 
Vec3& Vec3::set(float x, float y, float z)
{
    this->elements_[0] = x;
    this->elements_[1] = y;
    this->elements_[2] = z;

    return *this;
}
 
Vec3& Vec3::setX(float x)
{
    this->elements_[0] = x;
    return *this;
}
 
Vec3& Vec3::setY(float y)
{
    this->elements_[1] = y;
    return *this;
}
 
Vec3& Vec3::setZ(float z)
{
    this->elements_[2] = z;
    return *this;
}

float Vec3::getX()
{
    return this->elements_[0];
}
 
float Vec3::getY()
{
    return this->elements_[1];
}
 
float Vec3::getZ()
{
    return this->elements_[2];
}
 
float Vec3::dot(const Vec3& v2)
{
    return (
			this->elements_[0]*v2[0] +
            this->elements_[1]*v2[1] +
            this->elements_[2]*v2[2]
           );
}
 
Vec3 Vec3::scale(float scale)
{
    Vec3 scaled
	(
        (this->elements_[0]*scale),
        (this->elements_[1]*scale),
        (this->elements_[2]*scale)
    );

    return scaled;
}
 
Vec3 Vec3::add(const Vec3& v1, float scale)
{
    Vec3 sum
	(
        (this->elements_[0] + v1[0]*scale),
        (this->elements_[1] + v1[1]*scale),
        (this->elements_[2] + v1[2]*scale)
    );

    return sum;
}

float Vec3::operator[](int pos) const
{
    return elements_[pos];
}
 
Vec3 Vec3::operator+(const Vec3& v2) 
{
    return this->add(v2);
}
 
Vec3 Vec3::operator-(const Vec3& v2) 
{
    return this->subtract(v2);
}
 
Vec3& Vec3::operator+=(const Vec3& v2) 
{
    this->elements_[0] += v2[0];
    this->elements_[1] += v2[1];
    this->elements_[2] += v2[2];

    return *this;
}
 
Vec3& Vec3::operator-=(const Vec3& v2)
{
    this->elements_[0] -= v2[0];
    this->elements_[1] -= v2[1];
    this->elements_[2] -= v2[2];
    
	return *this;
}

// Added by me, I think.
// Used for the camera class.
Vec3& Vec3::operator*=(const float f) 
{
	this->elements_[0] *= f;
	this->elements_[1] *= f;
	this->elements_[2] *= f;

	return *this;
}
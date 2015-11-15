#include "vec2.h"
 
Vec2::Vec2(float x, float y)
{
    this->elements_[0] = x;
    this->elements_[1] = y;
}
 
Vec2::~Vec2()
{
}
 
Vec2 Vec2::copy()
{
    Vec2 copy
	(
        this->elements_[0],
        this->elements_[1]
    );

    return copy;           
}
 
bool Vec2::equals(const Vec2& v2, float epsilon)
{
    return ((std::abs(this->elements_[0] - v2[0]) < epsilon) &&
            (std::abs(this->elements_[1] - v2[1]) < epsilon));    
}
 
 
float Vec2::length()
{
    return std::sqrt(this->lengthSquared());
}
 
float Vec2::lengthSquared()
{
    return (
            this->elements_[0]*this->elements_[0] +
            this->elements_[1]*this->elements_[1]
           );
}
 
Vec2& Vec2::normalize()
{
    float mag = this->length();

    if(mag)
	{
        float multiplier = 1.0f/mag;
        this->elements_[0] *= multiplier;
        this->elements_[1] *= multiplier;
    }

    return *this;
}
 
Vec2 Vec2::cross(const Vec2& v2)
{
        Vec2 cross
		(
            (this->elements_[0] * v2[1] - this->elements_[1] * v2[0])
        );

        return cross;
}
 
Vec2 Vec2::subtract(const Vec2& v1, float scale)
{
        Vec2 sub
		(
            (this->elements_[0] - v1[0]*scale),
            (this->elements_[1] - v1[1]*scale)
        );

        return sub;
}
 
Vec2& Vec2::set(float x, float y)
{
    this->elements_[0] = x;
    this->elements_[1] = y;

    return *this;
}
 
Vec2& Vec2::setX(float x)
{
    this->elements_[0] = x;
    return *this;
}

Vec2& Vec2::setY(float y)
{
    this->elements_[1] = y;
    return *this;
}

float Vec2::getX()
{
    return this->elements_[0];
}
 
float Vec2::getY()
{
    return this->elements_[1];
}
 
float Vec2::dot(const Vec2& v2)
{
    return (
			this->elements_[0]*v2[0] +
            this->elements_[1]*v2[1]
           );
}
 
Vec2 Vec2::scale(float scale)
{
    Vec2 scaled
	(
        (this->elements_[0]*scale),
        (this->elements_[1]*scale)
    );

    return scaled;
}
 
Vec2 Vec2::add(const Vec2& v1, float scale)
{
    Vec2 sum
	(
        (this->elements_[0] + v1[0]*scale),
        (this->elements_[1] + v1[1]*scale)
    );
    return sum;
}
 
 
float Vec2::operator[](int pos) const
{
    return elements_[pos];
}
 
Vec2 Vec2::operator+(const Vec2& v2) {
    return this->add(v2);
}
 
Vec2 Vec2::operator-(const Vec2& v2) 
{
    return this->subtract(v2);
}
 
Vec2& Vec2::operator+=(const Vec2& v2) 
{
    this->elements_[0] += v2[0];
    this->elements_[1] += v2[1];

    return *this;
}
 
Vec2& Vec2::operator-=(const Vec2& v2) 
{
    this->elements_[0] -= v2[0];
    this->elements_[1] -= v2[1];

    return *this;
}

Vec2& Vec2::operator*=(const float f) 
{
	this->elements_[0] *= f;
	this->elements_[1] *= f;

	return *this;
}
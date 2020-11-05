#include <math/vector3.hpp>

vector3::vector3() : x(0), y(0), z(0) {}

vector3::vector3(float x, float y, float z) : x(x), y(y), z(z) {}

vector3 vector3::operator+(const vector3 & v) const
{
	return vector3(this->x + v.x, this->y + v.y, this->z + v.z);
}

vector3 vector3::operator-(const vector3 & v) const
{
	return vector3(this->x - v.x, this->y - v.y, this->z - v.z);
}

vector3 vector3::operator*(const float value) const
{
	return vector3(this->x*value, this->y*value, this->z*value);
}

vector3 vector3::operator/(const float value) const
{
	return vector3(this->x/value, this->y/value, this->z/value);
}

vector3 vector3::operator-() const
{
	return vector3(-this->x, -this->y, -this->z);
}

void vector3::operator+=(const vector3 & v)
{
	*this = *this + v;
}

void vector3::operator-=(const vector3 & v)
{
	*this = *this - v;
}

void vector3::operator*=(const float value)
{
	*this = *this * value;
}

bool vector3::operator<(const vector3 & v)
{
	return (this->Magnitude() < v.Magnitude());
}

vector3 vector3::Cross(const vector3 & vector) const
{
	return vector3(this->y*vector.z - this->z*vector.y,
				   this->z*vector.x - this->x*vector.z,
				   this->x*vector.y - this->y*vector.x);
}

float vector3::Dot(const vector3 & vector) const
{
	return (this->x*vector.x + this->y*vector.y + this->z*vector.z);
}

float vector3::Magnitude() const
{
	return sqrtf(x*x + y*y + z*z);
}

float vector3::SquareMagnitude() const
{
	float temp = Magnitude();
	return temp*temp;
}

void vector3::Normalize()
{
	*this *= (1/this->Magnitude());
}

bool vector3::operator==(const vector3 & other) const
{
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}

void vector3::Clear()
{
	x = 0;
	y = 0;
	z = 0;
}

//void vector3::Print() const
//{
//	std::cout << std::endl;
//	for (int i = 0; i < 3; i++)
//	{
//		if (this->f[i] < 10) {
//			std::cout << " " << this->f[i] << " ";
//		}
//		else {
//			std::cout << this->f[i] << " ";
//		}
//	}
//	std::cout << std::endl;
//}

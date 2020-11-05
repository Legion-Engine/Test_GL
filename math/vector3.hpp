#pragma once

#include <cmath>

struct vector2
{
	union
	{
		float f[2];

		struct
		{
			float x;
			float y;
		};
	};

	vector2() : x(0.f), y(0.f) {};
	vector2(float x, float y) : x(x), y(y) {};

	//vector2 Perpendicular() const
	//{
	//	vector2 result(y, -x);
	//	return result;
	//}
};

struct vector4
{
	float x, y, z, width;
};

///
/// A 3d vector
///
struct vector3
{
	union
	{
		// Holds all the values 
		float f[3];

		struct
		{
			/// Holds the value along the x axis
			float x;

			/// Holds the value along the y axis
			float y;

			/// Holds the value along the z axis
			float z;
		};
	};

	/// The default constructor creates a zero vector.
	vector3();

	/// Creates a vector with the given components
	vector3(float x, float y, float z);

	vector3 Perpendicular() const
	{
		return vector3(y, -x, 0.f);
	}

	/// Returns the value of the given vector added to this
	vector3 operator+(const vector3& v) const;

	/// Returns the value of the given vector subtracted from this
	vector3 operator-(const vector3& v) const;

	/// Returns a copy of this vector scaled the given value
	vector3 operator*(const float value) const;

	/// Returns a copy of this vector scaled the inverse of the value
	vector3 operator/(const float value) const;

	/// Returns the negative this vector
	vector3 operator-() const;

	/// Calculates and returns the dot product of this
	/// with the given vector
	float operator *(const vector3& vector) const;

	/// Adds the given vector to this
	void operator+=(const vector3& v);

	/// Subtracts the given vector from this
	void operator-=(const vector3& v);

	/// Multiplies this vector by the given scalar
	void operator*=(const float value);

	bool operator<(const vector3& v);

	/// Calculates and returns the cross product of this vector
	/// with the given vector
	vector3 Cross(const vector3& vector) const;

	/// Calculates and returns the dot product of this vector
	/// with the given vector
	float Dot(const vector3& vector) const;

	///  Gets the magnitude of this vector
	float Magnitude() const;

	///  Gets the squared magnitude of this vector
	float SquareMagnitude() const;

	/// Turns a non-zero vector into a vector of unit length
	void Normalize();

	/// Checks if the two vectors have identical components
	bool operator==(const vector3& other) const;

	/// Checks if the two vectors have non-identical components
	bool operator!=(const vector3& other) const;

	/// Zero all the components of the vector
	void Clear();

	vector3 Slerp(float fact, const vector3& r) const;

	//void Print() const;
};

/// Multiplication with Rhs Vector
inline vector3 operator*(float val, const vector3& rhs)
{
	return rhs * val;
}


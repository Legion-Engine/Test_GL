#pragma once

#include <math/vector3.hpp>


struct matrix44
{
	union
	{
		float m[4][4];
		float f[16];
		struct
		{
			vector3 xAxis;
			float wx;
			vector3 yAxis;
			float wy;
			vector3 zAxis;
			float wz;
			vector3 translation;
			float one;
		};
	};

	/// Construct a new matrix from explicit values
	matrix44(float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33);

	/// Construct a new identity matrix
	matrix44();

	/// Transform the given vector by this matrix.
	///
	/// @param vec vector that is asssumed to be homogenuos with width=1
	/// @return Resulting vector is asssumed to be homogenuos with width=1
	vector3 operator*(const vector3& vec) const;

	/// Matrix addition
	///
	/// @param mat Right side operand
	matrix44 operator+(const matrix44& mat) const;

	void operator+=(const matrix44& mat);

	/// Matrix substraction
	///
	/// @param mat Right side operand
	matrix44 operator-(const matrix44& mat) const;

	void operator-=(const matrix44& mat);

	/// Matrix multiplication
	///
	/// @param mat Right side operand
	matrix44 operator*(const matrix44& mat) const;

	bool operator==(const matrix44& mat) const;

	/// Translation bit of the matrix
	vector3 GetTranslation() const;
	
	/// Set the transltion of the matrix
	void SetTranslation(const vector3& vec);

	/// Get the x orientation axis 
	vector3 GetXAxis() const;

	/// Get the y orientation axis 
	vector3 GetYAxis() const;

	/// Get the z orientation axis 
	vector3 GetZAxis() const;

	/// Get the determinant of this matrix
	float Determinant() const;

	/// Inverts this matrix
	bool Invert();

	/// Transposes this matrix
	void Transpose();


	/// Sets the orientation of the matrix to the orthogonal basis vector
	/// It perfoms no checks on the orthogonality!
	///
	/// @param x X orthogonal basis vector
	/// @param y Y orthogonal basis vector
	/// @param z Z orthogonal basis vector
	void SetOrientation(const vector3& x,
						const vector3& y,
						const vector3& z);

	/// Set orientation using Euler angles. Broken at current!
	void SetEulerAxis(float yaw, float pitch, float roll);

	/// Creates an identity matrix
	///
	/// @return Identity matrix
	static matrix44 CreateIdentity();

	/// Creates a transation matrix
	///
	/// @return Translation matrix
	static matrix44 CreateTranslation(float x, float y, float z);
	static matrix44 CreateTranslation(vector3 t);

	static matrix44 CreateScale(vector3 scale);

	/// Creates a rotation matrix around an arbitrary axis
	static matrix44 CreateRotate(float angle, const vector3& axis);

	/// Angle in radians
	static matrix44 CreateRotateX(float angle);

	/// Angle in radians
	static matrix44 CreateRotateY(float angle);

	/// Angle in radians
	static matrix44 CreateRotateZ(float angle);

	/// Creates an orthographic projection matrix
	static matrix44 CreateOrtho(float left, float right, float bottom, float top, float nearZ, float farZ);

	/// Creates a frustum projection matrix
	static matrix44 CreateFrustum(float left, float right, float bottom, float top, float nearZ, float farZ);

	/// Creates a perspective projection matrix from camera settings
	static matrix44 CreatePerspective(float fovy, float aspect, float nearZ, float farZ);

	/// Creates a look at matrix, usualy a view matrix  
	static matrix44 CreateLookAt(const vector3& eye, const vector3& center, const vector3& up);

	/// Transfrom just the direction
	vector3 TransformDirectionVector(const vector3& direction);

	//void Print() const;
};
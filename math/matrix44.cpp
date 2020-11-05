#include <math/matrix44.hpp>

matrix44::matrix44(float m00, float m01, float m02, float m03,
				   float m10, float m11, float m12, float m13,
				   float m20, float m21, float m22, float m23,
				   float m30, float m31, float m32, float m33)
{
	/*xAxis = vector3(m00,  m01, m02);
	wx = m03;
	yAxis = vector3(m10, m11, m12);
	wy = m13;
	zAxis = vector3(m20, m21, m22);
	wz = m23;
	translation = vector3(m30, m31, m32);
	one = m33;*/
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;
	m[0][3] = m03;
	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;
	m[1][3] = m13;
	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;
	m[2][3] = m23;
	m[3][0] = m30;
	m[3][1] = m31;
	m[3][2] = m32;
	m[3][3] = m33;
}

matrix44::matrix44() {
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j) {
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	} 
} 

vector3 matrix44::operator*(const vector3 & vec) const {
	vector3 temp(0, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j >= 3) {
				temp.f[i] += this->m[j][i];
			}
			else {
				temp.f[i] += vec.f[j] * this->m[j][i];
			}
		}
	}
	return temp;
}

matrix44 matrix44::operator+(const matrix44 & mat) const
{
	matrix44 result;
	for (int i = 0; i < 16; i++)
	{
		result.f[i] = this->f[i] + mat.f[i];
	}
	return result;
}

void matrix44::operator+=(const matrix44 & mat)
{
	*this = *this + mat;
}

matrix44 matrix44::operator-(const matrix44 & mat) const
{
	matrix44 result;
	for (int i = 0; i < 16; i++)
	{
		result.f[i] = this->f[i] - mat.f[i];
	}
	return result;
}

void matrix44::operator-=(const matrix44 & mat)
{
	*this = *this - mat;
}

matrix44 matrix44::operator*(const matrix44 & mat) const {
	/*matrix44 temp;
	float tempVal;
	for (int i = 0; i < 4; i++)	{
		for (int j = 0; j < 4; j++) {
			tempVal = 0;
			for (int k = 0; k < 4; k++) {
				tempVal += this->m[k][j] * mat.m[i][k];
			}
			temp.m[i][j] = tempVal;
		}
	}
	return temp;*/

	return matrix44(mat.m[0][0] * m[0][0] + mat.m[0][1] * m[1][0] + mat.m[0][2] * m[2][0] + mat.m[0][3] * m[3][0],
	mat.m[0][0] * m[0][1] + mat.m[0][1] * m[1][1] + mat.m[0][2] * m[2][1] + mat.m[0][3] * m[3][1],
	mat.m[0][0] * m[0][2] + mat.m[0][1] * m[1][2] + mat.m[0][2] * m[2][2] + mat.m[0][3] * m[3][2],
	mat.m[0][0] * m[0][3] + mat.m[0][1] * m[1][3] + mat.m[0][2] * m[2][3] + mat.m[0][3] * m[3][3],
																								 
	mat.m[1][0] * m[0][0] + mat.m[1][1] * m[1][0] + mat.m[1][2] * m[2][0] + mat.m[1][3] * m[3][0],
	mat.m[1][0] * m[0][1] + mat.m[1][1] * m[1][1] + mat.m[1][2] * m[2][1] + mat.m[1][3] * m[3][1],
	mat.m[1][0] * m[0][2] + mat.m[1][1] * m[1][2] + mat.m[1][2] * m[2][2] + mat.m[1][3] * m[3][2],
	mat.m[1][0] * m[0][3] + mat.m[1][1] * m[1][3] + mat.m[1][2] * m[2][3] + mat.m[1][3] * m[3][3],
																								 
	mat.m[2][0] * m[0][0] + mat.m[2][1] * m[1][0] + mat.m[2][2] * m[2][0] + mat.m[2][3] * m[3][0],
	mat.m[2][0] * m[0][1] + mat.m[2][1] * m[1][1] + mat.m[2][2] * m[2][1] + mat.m[2][3] * m[3][1],
	mat.m[2][0] * m[0][2] + mat.m[2][1] * m[1][2] + mat.m[2][2] * m[2][2] + mat.m[2][3] * m[3][2],
	mat.m[2][0] * m[0][3] + mat.m[2][1] * m[1][3] + mat.m[2][2] * m[2][3] + mat.m[2][3] * m[3][3],

	mat.m[3][0] * m[0][0] + mat.m[3][1] * m[1][0] + mat.m[3][2] * m[2][0] + mat.m[3][3] * m[3][0],
	mat.m[3][0] * m[0][1] + mat.m[3][1] * m[1][1] + mat.m[3][2] * m[2][1] + mat.m[3][3] * m[3][1],
	mat.m[3][0] * m[0][2] + mat.m[3][1] * m[1][2] + mat.m[3][2] * m[2][2] + mat.m[3][3] * m[3][2],
	mat.m[3][0] * m[0][3] + mat.m[3][1] * m[1][3] + mat.m[3][2] * m[2][3] + mat.m[3][3] * m[3][3]);
}

bool matrix44::operator==(const matrix44 & mat) const
{
	return (this->f == mat.f);
}

vector3 matrix44::GetTranslation() const {
	return this->translation;
}

void matrix44::SetTranslation(const vector3 & vec) {
	this->translation = vec;
}

vector3 matrix44::GetZAxis() const {
	return zAxis;
}

void matrix44::SetOrientation(const vector3 & x, const vector3 & y, const vector3 & z)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = z;
}

void matrix44::SetEulerAxis(float yaw, float pitch, float roll)
{
	matrix44 apply;
	
	if (roll != 0) {
		float c = cosf(roll);
		float s = sinf(roll);
		apply = apply * matrix44(1,  0, 0, 0,
								 0,  c, s, 0,
								 0, -s, c, 0,
								 0,  0, 0, 1);
	}
	
	if (pitch != 0) {
		float c = cosf(pitch);
		float s = sinf(pitch);
		apply = apply * matrix44(c, 0, -s, 0,
								 0, 1,  0, 0,
								 s, 0,  c, 0,
								 0, 0,  0, 1);
	}

	if (yaw != 0) {
		float c = cosf(yaw);
		float s = sinf(yaw);
		apply = apply * matrix44(c, s, 0, 0,
								-s, c, 0, 0,
								 0, 0, 1, 0,
								 0, 0, 0, 1);
	}

	*this = *this * apply;
}

matrix44 matrix44::CreateIdentity()
{
	return matrix44();
}

matrix44 matrix44::CreateTranslation(float x, float y, float z)
{
	return matrix44(1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					x, y, z, 1);
}

matrix44 matrix44::CreateTranslation(vector3 t)
{
	return CreateTranslation(t.x, t.y, t.z);
}

matrix44 matrix44::CreateScale(vector3 scale)
{
	return matrix44(scale.x,       0,	    0, 0,
					      0, scale.y,       0, 0,
						  0,	   0, scale.z, 0,
						  0,	   0,		0, 1);
}

matrix44 matrix44::CreatePerspective(float fovy, float aspect, float nearZ, float farZ)
{
	float frustumDepth = farZ - nearZ;
	float cotanFOV = 1/tanf(0.5f*fovy);
	float mZ = -(farZ / frustumDepth);
	float mDZ = -((farZ * nearZ) / frustumDepth);
	return matrix44(cotanFOV / aspect,        0,   0,  0,
									0, cotanFOV,   0,  0,
									0,		  0,  mZ, -1,
									0,		  0, mDZ,  0);
}

matrix44 matrix44::CreateLookAt(const vector3 & eye, const vector3 & center, const vector3 & up)
{
	vector3 xAxis, yAxis, zAxis;
	zAxis = -(center - eye);
	zAxis.Normalize();
	xAxis = up.Cross(zAxis);
	xAxis.Normalize();
	yAxis = zAxis.Cross(xAxis);

	return matrix44(xAxis.x,           yAxis.x,           zAxis.x, 0,
				    xAxis.y,           yAxis.y,           zAxis.y, 0,
				    xAxis.z,           yAxis.z,           zAxis.z, 0,
			-xAxis.Dot(eye),   -yAxis.Dot(eye),   -zAxis.Dot(eye), 1);
}

//void matrix44::Print() const
//{
//	for (int i = 0; i < 4; i++)
//	{
//		std::cout << std::endl;
//		for (int j = 0; j < 4; j++)
//		{
//			if (m[j][i] < 10) {
//				std::cout << " " << m[j][i] << " ";
//			}
//			else {
//				std::cout << m[j][i] << " ";
//			}
//		}
//	}
//	std::cout << std::endl;
//}
// 
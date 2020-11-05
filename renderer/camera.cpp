#include <renderer/camera.hpp>
#include <common/utils.hpp>

#define SPEED 4

void camera::Update(float dt, GLFWwindow* window, float width, float height)
{
	double mX, mY;
	glfwGetCursorPos(window, &mX, &mY);
	m_prevMousePos = m_mousePos;
	m_mousePos.y = height - mY;
	m_mousePos.x = width - mX;
	m_mousePos -= vector3(width*0.5f, height*0.5f, 0.0f);
	float dX = m_mousePos.x - m_prevMousePos.x;
	m_horizontalScalar += dX;

	float angleY = 90 * (m_mousePos.y / (height*0.5f));
	if (angleY > 90) angleY = 90;
	else if (angleY < -90) angleY = -90;
	float angleHor = 180 * (m_horizontalScalar / (width*0.5f));
	angleHor = DegToRad(angleHor);

	m_viewDir.y = sin(DegToRad(angleY)) * 3;

	m_viewDir.x = -sin(angleHor);
	m_viewDir.z = -cos(angleHor);

	m_viewDir.Normalize();

	vector3 fwd = m_viewDir;
	fwd.y = 0;
	fwd.Normalize();
	vector3 up(0.f, 1.f, 0.f);
	vector3 side = up.Cross(fwd);
	vector3 _force;
	float thrust = (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) - (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS);
	float strafe = (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) - (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS);
	float vert = (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) - (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS);

	if (thrust > 0.0f)
	{
		_force += fwd * thrust * SPEED;
	}
	else if (thrust < 0.0f) {
		_force += fwd * thrust * SPEED;
	}

	if (strafe > 0.0f)
	{
		_force += side * strafe * SPEED;
	}
	else if (strafe < 0.0f) {
		_force += side * strafe * SPEED;
	}

	if (vert > 0.0f)
	{
		_force += up * vert * SPEED;
	}
	else if (vert < 0.0f) {
		_force += up * vert * SPEED;
	}

	cameraPos += _force * dt;
	vector3 lookAtPos = m_viewDir + cameraPos;

	m_view = matrix44::CreateLookAt(cameraPos, lookAtPos, up);
}
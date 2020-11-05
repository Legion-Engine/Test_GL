#pragma once

#include <renderer/base_camera.hpp>
#include <math/vector3.hpp>
#include <common/gl.hpp>

struct camera : public base_camera
{
public:
	camera() {};
	void Update(float dt, GLFWwindow* window, float width, float height);

	vector3 cameraPos = vector3(-0.5, 2, -4);

private:
	vector3 m_viewDir = vector3(0, 0, 1);
	vector3 m_prevMousePos = vector3();
	vector3 m_mousePos = vector3();
	float m_horizontalScalar = 0.f;
};
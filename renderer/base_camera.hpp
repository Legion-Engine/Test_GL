#pragma once

#include <math/matrix44.hpp>

struct base_camera
{
public:
	base_camera() {}
	const matrix44& view() const { return m_view; }
	const matrix44& projection() const { return m_projection; }
	matrix44 viewProjection() const { return m_projection * m_view; }
	void setProjection(const matrix44& p) { m_projection = p; }
	void setView(const matrix44& v) { m_view = v; }

protected:
	matrix44	m_view;
	matrix44	m_projection;
};
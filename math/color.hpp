#pragma once

#include <algorithm>
#include <string>
#include <common/utils.hpp>
#include <cmath>

struct color
{
public:
	union
	{
		// Holds all the values
		char rgba[4];

		struct
		{
			// Red
			byte r;

			// Green
			byte g;

			// Blue
			byte b;

			// Alpha
			byte a;
		};

		// Holds all the values as a 32 bit unsigned int
		unsigned int integervalue;
	};

public:
	/// Ctor as black
	color() : r(0), g(0), b(0), a(255u) {}

	/// Full ctor 
	color(byte red, byte green, byte blue, byte alpha)
		: r(red), g(green), b(blue), a(alpha) {}

	/// Opaque ctor 
	color(byte red, byte green, byte blue)
		: r(red), g(green), b(blue), a(255u) {}

	/// Constructor from a string represting a hex vavlue. Used for copy/pasting values from
	/// Photoshop or similar.
	color(std::string hex);

	/// Returns the value of the given color added to this. Doesn't check range
	color operator+(const color& c) const
	{
		return color(static_cast<byte>(r + c.r), static_cast<byte>(g + c.g), static_cast<byte>(b + c.b), static_cast<byte>(a + c.a));
	}

	/// Returns the value of the given color added to this.
	color operator*(const color& c) const;


	/// Returns the value of the given color subtracted from this.
	color operator-(const color& c) const
	{
		return color(static_cast<byte>(r - c.r), static_cast<byte>(g - c.g), static_cast<byte>(b - c.b), static_cast<byte>(a - c.a));
	}

	/// Returns a copy of this color scaled the given value.
	color operator*(float value) const
	{
		return color(static_cast<byte>(r * value), static_cast<byte>(g * value), static_cast<byte>(b * value), static_cast<byte>(a * value));
	}

	/// Multiplies this vector by the given scalar.
	void operator*=(float value)
	{
		r = static_cast<byte>(std::clamp<float>(r * value, 0.f, 255.f));
		g = static_cast<byte>(std::clamp<float>(g * value, 0.f, 255.f));
		b = static_cast<byte>(std::clamp<float>(b * value, 0.f, 255.f));
		a = static_cast<byte>(std::clamp<float>(a * value, 0.f, 255.f));
	}

	/// Multiplies this vector by the given scalar.
	void operator+=(const color& c)
	{
		r += c.r;
		g += c.g;
		b += c.b;
		a += c.a;
	}

	/// Checks if two colors are the same
	bool operator==(const color& c) const
	{
		return r == c.r && g == c.g && b == c.b && a == c.a;
	}

	/// Checks if two colors are different
	bool operator!=(const color& c) const
	{
		return !(r == c.r && g == c.g && b == c.b && a == c.a);
	}

	// Define some quick colors
	static color Red;
	static color Green;
	static color Blue;
	static color White;
	static color Black;
	static color Yellow;
	static color Orange;
	static color Purple;
	static color Cyan;
	static color Magenta;
	static color Brown;
	static color Grey;
	static color CornFlower;

	static color WhiteTransparent;
	static color BlackTransparent;

	color Transparent(float opacity = 0.0f) const;
};

/// Returns a copy of the color scaled the given value.
inline color operator*(float value, color c)
{
	return c * value;
}



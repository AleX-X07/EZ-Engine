#pragma once

#include <maths/matrix/matrix.h>

namespace maths
{
	constexpr float PI = 3.14159265358979f;
	
	constexpr float RadToDegree(float rad)
	{
		return rad * 180.f / PI;
	}
	constexpr float DegreeToRad(float angle)
	{
		return angle * PI / 180.f;
	}
}
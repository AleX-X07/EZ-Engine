#pragma once

namespace maths
{
	// Constructor - Desctructor
	template<NumberT T>
	TVecteur3<T>::TVecteur3() : TVecteur<T, 3>(), x(this->m_vec[0]), y(this->m_vec[1]), z(this->m_vec[2]) {}

	template<NumberT T>
	TVecteur3<T>::TVecteur3(const T& _x, const T& _y, const T& _z) : TVecteur3<T>()
	{
		this->m_vec[0] = _x;
		this->m_vec[1] = _y;
		this->m_vec[2] = _z;
	}

	// Function
	template<NumberT T>
	TVecteur3<T> TVecteur3<T>::CrossProduct(const TVecteur3<T>& other)
	{
		TVecteur3<T> res;
		res.x = y * other.z - z * other.y;
		res.y = z * other.x - x * other.z;
		res.z = x * other.y - y * other.x;
		return res;
	}

	template<NumberT T>
	TVecteur3<T>& TVecteur3<T>::Rotate(float angle, const TVecteur3<T>& axe)
	{
		float rad = maths::DegreeToRad(angle);
		auto temp = axe.Normalize();

		float kx = static_cast<float>(temp[0]);
		float ky = static_cast<float>(temp[1]);
		float kz = static_cast<float>(temp[2]);

		float c = std::cos(rad);
		float s = std::sin(rad);
		float t = 1.0f - c;

		TMatrix<float, 3, 3> R =
		{
			{ c + t * kx * kx,       t * kx * ky - s * kz,   t * kx * kz + s * ky },
			{ t * kx * ky + s * kz,  c + t * ky * ky,        t * ky * kz - s * kx },
			{ t * kx * kz - s * ky,  t * ky * kz + s * kx,   c + t * kz * kz }
		};

		TMatrix<float, 3, 1> vec_to_math = { { x },{ y },{ z } };

		auto res = R * vec_to_math;

		x = T(res[0]);
		y = T(res[1]);
		z = T(res[2]);
		return *this;
	}
}
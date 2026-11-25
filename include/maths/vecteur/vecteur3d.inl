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

		TVecteur3<float> axe_norm = { temp[0], temp[1], temp[2] };

		TMatrix<float, 3, 3> P =
		{
			{ axe_norm.x * axe_norm.x, axe_norm.x * axe_norm.y, axe_norm.x * axe_norm.z },
			{ axe_norm.x * axe_norm.y, axe_norm.y * axe_norm.y, axe_norm.y * axe_norm.z },
			{ axe_norm.x * axe_norm.z, axe_norm.y * axe_norm.z, axe_norm.z * axe_norm.z}
		};
		TMatrix<float, 3, 3> I = maths::TMatrix<float, 3, 3>::Identity();
		TMatrix<float, 3, 3> Q =
		{
			{ 0, -axe_norm.z, axe_norm.y },
			{ axe_norm.z, 0, -axe_norm.x},
			{-axe_norm.y, axe_norm.x, 0}
		};

		TMatrix<float, 1, 3> vec_to_math = { { x, y, z } };

		TMatrix<float, 3, 3> val = P + (I - P) * std::cos(rad) + Q * std::sin(rad);

		auto res = vec_to_math * val;

		this->x = T(res[0]);
		this->y = T(res[1]);
		this->z = T(res[2]);
		return *this;
	}
}
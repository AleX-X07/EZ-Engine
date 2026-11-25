#pragma once

namespace maths
{
	// Constructor - Desctructor
	template<NumberT T>
	TVecteur2<T>::TVecteur2() : TVecteur<T, 2>(), x(this->m_vec[0]), y(this->m_vec[1]) {}

	template<NumberT T>
	TVecteur2<T>::TVecteur2(const T& _x, const T& _y) : TVecteur2<T>()
	{
		this->m_vec[0] = _x;
		this->m_vec[1] = _y;
	}

	// Function
	template<NumberT T>
	T TVecteur2<T>::CrossProduct(const TVecteur2<T>& other) 
	{
		T res = T();
		res = x * other.y - y * other.x;
		return res;
	}

	template<NumberT T>
	TVecteur2<T>& TVecteur2<T>::Rotate(int angle)
	{
		auto rad = maths::DegreeToRad(angle);

		maths::TMatrix<T, 1, 2> vec_to_mat = { { x,y } };
		maths::TMatrix<T, 2, 2> mat_rotate_2d =
		{
			{ T(std::cos(rad)), T(std::sin(rad)) },
			{ T(-std::sin(rad)), T(std::cos(rad)) }
		};
		auto res = vec_to_mat * mat_rotate_2d;
		x = res[0];
		y = res[1];
		return *this;
	}
}

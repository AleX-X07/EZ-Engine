#pragma once

namespace maths
{
	// Constructor - Desctructor
	template<typename T>
	TVecteur2<T>::TVecteur2() : TVecteur<T, 2>(), x(this->m_vec[0]), y(this->m_vec[1]) {}

	template<typename T>
	TVecteur2<T>::TVecteur2(const T& _x, const T& _y) : TVecteur2<T>()
	{
		this->m_vec[0] = _x;
		this->m_vec[1] = _y;
	}

	// Function
	template<typename T>
	T TVecteur2<T>::CrossProduct(const TVecteur2<T>& other) 
	{
		T res = T();
		res = x * other.y - y * other.x;
		return res;
	}
}

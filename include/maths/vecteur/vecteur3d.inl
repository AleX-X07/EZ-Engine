#pragma once

namespace maths
{
	// Constructor - Desctructor
	template<typename T>
	TVecteur3<T>::TVecteur3() : TVecteur<T, 3>(), x(this->m_vec[0]), y(this->m_vec[1]), z(this->m_vec[2]) {}

	template<typename T>
	TVecteur3<T>::TVecteur3(const T& _x, const T& _y, const T& _z) : TVecteur3<T>()
	{
		this->m_vec[0] = _x;
		this->m_vec[1] = _y;
		this->m_vec[2] = _z;
	}

	// Function
	template<typename T>
	TVecteur3<T> TVecteur3<T>::CrossProduct(const TVecteur3<T>& other)
	{
		TVecteur3<T> res;
		res.x = y * other.z - z * other.y;
		res.y = z * other.x - x * other.z;
		res.z = x * other.y - y * other.x;
		return res;
	}
}
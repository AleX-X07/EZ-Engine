#pragma once

#include <maths/vecteur.h>

namespace maths
{
	template<typename T>
	class TVecteur2 : public TVecteur<T, 2>
	{
	public:
		T& x;
		T& y;

	public:
		TVecteur2() : TVecteur<T, 2>(), x(this->m_vec[0]), y(this->m_vec[1]) {}
		TVecteur2(const T& x, const T& y) : TVecteur2() {}
	};
}
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
		TVecteur2();
		TVecteur2(const T& x, const T& y) : TVecteur2() {}
	};
}

#include <maths/vecteur2d.inl>
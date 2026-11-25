#pragma once

#include <maths/vecteur/vecteur.h>

namespace maths
{
	template<NumberT T>
	class TVecteur2 : public TVecteur<T, 2>
	{
	public:
		T& x;
		T& y;

	public:
		// Constructor - Destructeur
		TVecteur2();
		TVecteur2(const T& _x, const T& _y);

		// Function
		T CrossProduct(const TVecteur2<T>& other);
		TVecteur2<T>& Rotate(int angle);
	};
}

#include <maths/vecteur/vecteur2d.inl>
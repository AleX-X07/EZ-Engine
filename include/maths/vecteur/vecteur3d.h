#pragma once

#include <maths/vecteur/vecteur.h>

namespace maths
{
	template<typename T>
	class TVecteur3 : public TVecteur<T, 3>
	{
	public:
		T& x;
		T& y;
		T& z;

	public:
		// Constructor - Desctructor
		TVecteur3();
		TVecteur3(const T& _x, const T& _y, const T& _z);

		// Function
		TVecteur3<T> CrossProduct(const TVecteur3<T>& other);
	};
}

#include <maths/vecteur/vecteur3d.inl>
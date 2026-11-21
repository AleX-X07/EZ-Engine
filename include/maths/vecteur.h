#pragma once

#include <cmath>
#include <initializer_list>

namespace maths
{
	template<typename T, int n>
	class TVecteur
	{
	protected:
		T* m_vec = nullptr;

	public:
		// Constructor - Destructeur
		TVecteur();
		TVecteur(const TVecteur<T, n>& other);
		TVecteur(const std::initializer_list<T>& l);

		virtual ~TVecteur();

		// Operator
		TVecteur<T, n>& operator=(TVecteur<T, n>& other);
		T& operator[](size_t index);
		TVecteur<T, n> operator+(TVecteur<T, n>& other);
		TVecteur<T, n> operator-(TVecteur<T, n>& other);

		friend std::ostream& operator<<(std::ostream& os, const TVecteur<T,n>& vec)
		{
			os << "(";
			for (size_t i = 0; i < n; i++)
			{
				if (i == n - 1)
				{
					os << vec.m_vec[i];
					continue;
				}
				os << vec.m_vec[i] << ",";
			}
			os << ")";
			return os;
		}

		// Function
		T& Norm();
		TVecteur<T, n> Normalize();
		T& DotProduct(TVecteur<T, n>& other);
	};
}

#include <maths/vecteur.inl>
#pragma once

#include <iostream>
#include <cmath>
#include <type_traits>
#include <initializer_list>
#include <maths/globals.h>

namespace maths
{
	template<NumberT T, int n>
	class TVecteur
	{
	protected:
		T m_vec[n];


	protected:
		// Function
		TMatrix<T, n + 1, n + 1> VecToMatrix();

	public:
		// Constructor - Destructeur
		TVecteur() = default;
		TVecteur(const TVecteur<T, n>& other);
		TVecteur(const std::initializer_list<T>& l);

		virtual ~TVecteur();

		// Operator
		TVecteur<T, n>& operator=(const TVecteur<T, n>& other);
		T& operator[](size_t index);
		T operator[](size_t index) const;

		TVecteur<T, n> operator+(const TVecteur<T, n>& other);
		TVecteur<T, n>& operator+=(const TVecteur<T, n>& other);

		TVecteur<T, n> operator-(const TVecteur<T, n>& other);
		TVecteur<T, n>& operator-=(const TVecteur<T, n>& other);

		TVecteur<T, n> operator*(const T& other);
		TVecteur<T, n>& operator*=(const T& other);

		TVecteur<T, n> operator/(const T& other);
		TVecteur<T, n>& operator/=(const T& other);

		bool operator==(const TVecteur<T, n>& other);
		bool operator!=(const TVecteur<T, n>& other);

		// Function
		float Norm() const;
		TVecteur<T, n> Normalize() const;
		float DotProduct(TVecteur<T, n>& other);

		friend std::ostream& operator<<(std::ostream& os, const TVecteur<T, n>& vec)
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
	};
}

#include <maths/vecteur/vecteur.inl>
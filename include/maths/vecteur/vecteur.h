#pragma once

#include <cmath>
#include <type_traits>
#include <initializer_list>

namespace maths
{
	template<typename T>
	concept NumberT = std::is_integral_v<T> || std::is_floating_point_v<T>;

	template<NumberT T, int n>
	class TVecteur
	{
	protected:
		T m_vec[n];

	public:
		// Constructor - Destructeur
		TVecteur() = default;
		TVecteur(const TVecteur<T, n>& other);
		TVecteur(const std::initializer_list<T>& l);

		virtual ~TVecteur();

		// Operator
		TVecteur<T, n>& operator=(const TVecteur<T, n>& other);
		T& operator[](const size_t& index);

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
		float Norm();
		TVecteur<T, n> Normalize();
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
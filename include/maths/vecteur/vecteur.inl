#pragma once

namespace maths
{
	// Constructor - Destructor
	template<NumberT T, int n>
	TVecteur<T,n>::TVecteur(const TVecteur<T,n>& other) 
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
	}

	template<NumberT T, int n>
	TVecteur<T, n>::TVecteur(const std::initializer_list<T>& l)
	{
		int cptr = 0;
		for (auto& Elem : l)
		{
			m_vec[cptr] = Elem;
			cptr++;
		}
	}

	template<NumberT T, int n>
	TVecteur<T,n>::~TVecteur()
	{
	}

	// Operator
	template<NumberT T, int n>
	TVecteur<T, n>&  TVecteur<T,n>::operator=(const TVecteur<T, n>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
		return *this;
	}

	template<NumberT T, int n>
	T& TVecteur<T, n>::operator[](const size_t& index)
	{
		return m_vec[index];
	}

	template<NumberT T, int n>
	TVecteur<T, n> TVecteur<T, n>::operator+(const TVecteur<T, n>& other)
	{
		TVecteur<T, n> res;
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] + other[i];
		}
		return res;
	}

	template<NumberT T, int n>
	TVecteur<T, n> TVecteur<T, n>::operator-(const TVecteur<T, n>& other)
	{
		TVecteur<T, n> res;
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] - other[i];
		}
		return res;
	}

	template<NumberT T, int n>
	TVecteur<T, n>& TVecteur<T, n>::operator*(const T& other)
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] *= other;
		}
		return *this;
	}
	
	// Function
	template<NumberT T, int n>
	float TVecteur<T, n>::Norm()
	{
		T val = T();
		for (size_t i = 0; i < n; i++)
		{
			val += m_vec[i] * m_vec[i];
		}
		T res = std::sqrt(val);
		return res;
	}

	template<NumberT T, int n>
	TVecteur<T, n> TVecteur<T, n>::Normalize()
	{
		TVecteur<T, n> res;
		T norm = Norm();
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] / norm;
		}
		return res;
	}

	template<NumberT T, int n>
	float TVecteur<T, n>::DotProduct(TVecteur<T, n>& other)
	{
		T res = T();
		for (size_t i = 0; i < n; i++)
		{
			res += m_vec[i] * other[i];
		}
		return res;
	};
}
#pragma once

namespace maths
{
	// Constructor - Destructor
	template<typename T, int n>
	TVecteur<T,n>::TVecteur()
	{
		m_vec = new T[n];
	};

	template<typename T, int n>
	TVecteur<T,n>::TVecteur(const TVecteur<T,n>& other) : TVecteur()
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
	}

	template<typename T, int n>
	TVecteur<T, n>::TVecteur(const std::initializer_list<T>& l) : TVecteur<T, n>()
	{
		int cptr = 0;
		for (auto& Elem : l)
		{
			m_vec[cptr] = Elem;
			cptr++;
		}
	}

	template<typename T, int n>
	TVecteur<T,n>::~TVecteur()
	{
		delete[] m_vec;
		m_vec = nullptr;
	}

	// Operator
	template<typename T, int n>
	TVecteur<T, n>&  TVecteur<T,n>::operator=(TVecteur<T, n>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] m_vec;
		m_vec = new T[n];
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
		return *this;
	}

	template<typename T, int n>
	T& TVecteur<T, n>::operator[](size_t index)
	{
		return m_vec[index];
	}

	template<typename T, int n>
	TVecteur<T, n> TVecteur<T, n>::operator+(TVecteur<T, n>& other)
	{
		TVecteur<T, n> res;
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] + other[i];
		}
		return res;
	}

	template<typename T, int n>
	TVecteur<T, n> TVecteur<T, n>::operator-(TVecteur<T, n>& other)
	{
		TVecteur<T, n> res;
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] - other[i];
		}
		return res;
	}

	template<typename T, int n>
	TVecteur<T, n>& TVecteur<T, n>::operator*(T other)
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] *= other;
		}
		return *this;
	}
	
	// Function
	template<typename T, int n>
	T TVecteur<T, n>::Norm()
	{
		T val = T();
		for (size_t i = 0; i < n; i++)
		{
			val += m_vec[i] * m_vec[i];
		}
		T res = std::sqrt(val);
		return res;
	}

	template<typename T, int n>
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

	template<typename T, int n>
	T TVecteur<T, n>::DotProduct(TVecteur<T, n>& other)
	{
		T res = T();
		for (size_t i = 0; i < n; i++)
		{
			res += m_vec[i] * other[i];
		}
		return res;
	};
}
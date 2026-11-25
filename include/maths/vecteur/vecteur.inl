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
			res[i] = m_vec[i] + other.m_vec[i];
		}
		return res;
	}

	template<NumberT T, int n>
	TVecteur<T, n>& TVecteur<T, n>::operator+=(const TVecteur<T, n>& other)
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] += other.m_vec[i];
		}
		return *this;
	}

	template<NumberT T, int n>
	TVecteur<T, n> TVecteur<T, n>::operator-(const TVecteur<T, n>& other)
	{
		TVecteur<T, n> res;
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] - other.m_vec[i];
		}
		return res;
	}

	template<NumberT T, int n>
	TVecteur<T, n>& TVecteur<T, n>::operator-=(const TVecteur<T, n>& other)
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] -= other.m_vec[i];
		}
		return *this;
	}

	template<NumberT T, int n>
	TVecteur<T, n> TVecteur<T, n>::operator*(const T& other)
	{
		TVecteur<T, n> res;
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] * other;
		}
		return res;
	}

	template<NumberT T, int n>
	TVecteur<T, n>& TVecteur<T, n>::operator*=(const T& other)
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] *= other;
		}
		return *this;
	}

	template<NumberT T, int n>
	TVecteur<T, n> TVecteur<T, n>::operator/(const T& other)
	{
		TVecteur<T, n> res;
		for (size_t i = 0; i < n; i++)
		{
			res[i] = m_vec[i] / other;
		}
		return res;
	}

	template<NumberT T, int n>
	TVecteur<T, n>& TVecteur<T, n>::operator/=(const T& other)
	{
		for (size_t i = 0; i < n; i++)
		{
			m_vec[i] /= other;
		}
		return *this;
	}

	template<NumberT T, int n>
	bool TVecteur<T, n>::operator==(const TVecteur<T,n>& other)
	{
		bool res = true;
		for (size_t i = 0; i < n; i++)
		{
			if (m_vec[i] != other.m_vec[i])
			{
				res = false;
			}
		}
		return res;
	}

	template<NumberT T, int n>
	bool TVecteur<T, n>::operator!=(const TVecteur<T, n>& other)
	{
		bool res = false;
		for (size_t i = 0; i < n; i++)
		{
			if (m_vec[i] != other.m_vec[i])
			{
				res = true;
			}
		}
		return res;
	}
	
	// Function
	template<NumberT T, int n>
	TMatrix<T, n + 1, n + 1> TVecteur<T, n>::VecToMatrix()
	{
		TMatrix<T, n + 1, n + 1> res = TMatrix<T, n + 1, n + 1>::Identity();
		for (size_t i = 0; i < n; i++)
		{
			res[n + (n + 1) * i] = m_vec[i];
		}
		return res;
	}

	template<NumberT T, int n>
	float TVecteur<T, n>::Norm() const 
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
	TVecteur<T, n> TVecteur<T, n>::Normalize() const
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
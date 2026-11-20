#pragma once

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
		TVecteur() 
		{ 
			m_vec = new T[n]; 
		};
		TVecteur(const TVecteur<T, n>& other) : TVecteur()
		{ 
			for (size_t i = 0; i < n; i++)
			{
				m_vec[i] = other.m_vec[i];
			}
		}
		TVecteur(const std::initializer_list<T>& l) : TVecteur()
		{
			int cptr = 0;
			for (auto& Elem : l)
			{
				m_vec[cptr] = Elem;
				cptr++;
			}
		}

		virtual ~TVecteur()
		{
			delete[] m_vec;
			m_vec = nullptr;
		}

		// Operator
		TVecteur<T, n>& operator=(TVecteur<T, n>& other)
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

		T& operator[](size_t index)
		{
			return m_vec[index];
		}

		TVecteur<T, n> operator+(TVecteur<T, n>& other)
		{ 
			TVecteur<T, n> res;
			for (size_t i = 0; i < n; i++)
			{
				res[i] = m_vec[i] + other[i];
			}
			return res;
		}

		// Function
		//T& DotProduct();
	};
}
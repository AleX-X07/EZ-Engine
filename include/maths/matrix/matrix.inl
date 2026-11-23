#pragma once

namespace maths
{
	// Constructor - Destructor
	template<NumberT T, int line, int column>
	TMatrix<T, line, column>::TMatrix()
	{
		m_vec = new T[size];
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column>::TMatrix(const TMatrix<T, line, column>& other)
	{
		m_vec = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column>::TMatrix(const std::initializer_list<std::initializer_list<T>>& l) : TMatrix<T,line,column>()
	{
		size_t i = 0;
		for (auto& val : l)
		{
			for (auto& v : val)
			{
				m_vec[i] = v;
				i++;
			}
		}
	}

	// Operator
	template<NumberT T, int line, int column>
	TMatrix<T, line, column>& TMatrix<T, line, column>::operator=(const TMatrix<T,line,column>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] m_vec;
		m_vec = new T[size];

		for (size_t i = 0; i < size; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
		return *this;
	}

	template<NumberT T, int line, int column>
	T& TMatrix<T,line,column>::operator[](const size_t& index)
	{
		return m_vec[index];
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator+(const TMatrix<T, line, column>& other)
	{
		TMatrix<T, line, column> res = TMatrix<T, line, column>();
		for (size_t i = 0; i < size; i++)
		{
			res[i] = m_vec[i] + other.m_vec[i];
		}
		return res;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator-(const TMatrix<T, line, column>& other)
	{
		TMatrix<T, line, column> res = TMatrix<T, line, column>();
		for (size_t i = 0; i < size; i++)
		{
			res[i] = m_vec[i] - other.m_vec[i];
		}
		return res;
	}

	template<NumberT T, int line, int column>
	template<int LOther, int COther>
	TMatrix<T, line, COther> TMatrix<T, line, column>::operator*(const TMatrix<T, LOther, COther>& other)
	{
		TMatrix<T, line, COther> res = TMatrix<T, line, column>();
		if (column == COther)
		{
			for (size_t l = 0; l < line; l++)
			{
				for (size_t c = 0; c < COther; c++)
				{
					T val = T();
					for (size_t i = 0; i < column; i++)
					{
						val += m_vec[i + line * l] * other.m_vec[c + LOther * i];
					}
					res[c + COther * l] = val;
				}
			}
		}
		return res;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator*(const T& other)
	{
		for (size_t i = 0; i < size; i++)
		{
			m_vec[i] *= other;
		}
		return *this;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator/(const T& other)
	{
		for (size_t i = 0; i < size; i++)
		{
			m_vec[i] /= other;
		}
		return *this;
	}
}
#pragma once

namespace maths
{
	// Constructor - Destructor
	template<NumberT T, int line, int column>
	TMatrix<T, line, column>::TMatrix(const TMatrix<T, line, column>& other)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column>::TMatrix(const std::initializer_list<std::initializer_list<T>>& l)
	{
		int i = 0;
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

		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
		return *this;
	}

	template<NumberT T, int line, int column>
	T& TMatrix<T,line,column>::operator[](size_t index)
	{
		return m_vec[index];
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator+(const TMatrix<T, line, column>& other)
	{
		TMatrix<T, line, column> res = TMatrix<T, line, column>();
		for (size_t i = 0; i < m_size; i++)
		{
			res[i] = m_vec[i] + other.m_vec[i];
		}
		return res;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator-(const TMatrix<T, line, column>& other)
	{
		TMatrix<T, line, column> res = TMatrix<T, line, column>();
		for (size_t i = 0; i < m_size; i++)
		{
			res[i] = m_vec[i] - other.m_vec[i];
		}
		return res;
	}

	template<NumberT T, int line, int column>
	template<int LOther, int COther>
	TMatrix<T, line, COther> TMatrix<T, line, column>::operator*(const TMatrix<T, LOther, COther>& other)
	{
		static_assert(column == LOther);
		TMatrix<T, line, COther> res = TMatrix<T, line, COther>();
		for (size_t l = 0; l < line; l++)
		{
			for (size_t c = 0; c < COther; c++)
			{
				T val = T();
				for (size_t i = 0; i < column; i++)
				{
					val += m_vec[i + column * l] * other[c + COther * i];
				}
				res[c + COther * l] = val;
			}
		}
		return res;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator*(const T& other)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] *= other;
		}
		return *this;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator/(const T& other)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] /= other;
		}
		return *this;
	}

	// Function
	template<NumberT T, int line, int column>
	T TMatrix<T, line, column>::Det()
	{
		static_assert(line == column);
		T res = T();
		if (line == 2 && column == 2)
		{
			res += m_vec[0] * m_vec[3] - m_vec[1] * m_vec[2];
		}
		return res;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::Inverse()
	{
		static_assert(line == column);
		T det = this->Det();
		if (det != 0)
		{

		}
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::Identity()
	{
		TMatrix<T, line, column> res;
		for (size_t i = 0; i < column; i++)
		{
			for (size_t j = 0; j < line; j++)
			{
				res[j + column * j] = 1;
			}
		}
		return res;
	}
}
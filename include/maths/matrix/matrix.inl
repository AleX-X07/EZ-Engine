#pragma once

namespace maths
{
	// Constructor - Destructor
	template<NumberT T, int line, int column>
	TMatrix<T, line, column>::TMatrix()
	{
		m_vec = new[line * column];
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
		m_vec = new[size];

		for (size_t i = 0; i < size; i++)
		{
			m_vec[i] = other.m_vec[i];
		}
		return *this;
	}

	template<NumberT T, int line, int column>
	size_t TMatrix<T,line,column>::operator[](const size_t& index)
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
		if (column != COther)
		{
			return;
		}

		TMatrix<T, line, column> res = TMatrix<T, line, column>();
		for (size_t i = 0; i < size; i++)
		{
			res[i] = 
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
	TMatrix<T, line, column> TMatrix<T, line, column>::operator*(const T& other)
	{
		for (size_t i = 0; i < size; i++)
		{
			m_vec[i] /= other;
		}
		return *this;
	}
}
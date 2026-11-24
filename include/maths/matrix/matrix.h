#pragma once

#include <type_traits>
#include <initializer_list>

namespace maths
{
	template<NumberT T, int line, int column>
	class TMatrix
	{
	protected:
		T m_vec[line*column];
		T m_size = line * column;

	public:
		T m_line = line;
		T m_column = column;

	public:

		// Constructor - Destructor
		TMatrix();
		TMatrix(const TMatrix<T,line,column>& other);
		TMatrix(const std::initializer_list<std::initializer_list<T>>& l);
		virtual ~TMatrix() = default;

		// Operator
		TMatrix<T, line, column>& operator=(const TMatrix<T, line, column>& other);
		T& operator[](size_t index);
		TMatrix<T, line, column> operator+(const TMatrix<T, line, column>& other);
		TMatrix<T, line, column> operator-(const TMatrix<T, line, column>& other);

		template<int LOther, int COther>
		TMatrix<T, line, COther> operator*(const TMatrix<T, LOther, COther>& other);

		TMatrix<T, line, column> operator*(const T& other);
		TMatrix<T, line, column> operator/(const T& other);

		// Function
		T Det();
		TMatrix<T, line, column> Inverse();
		TMatrix<T, line, column> Identity();

		friend std::ostream& operator<<(std::ostream& os, const TMatrix<T, line, column>& vec)
		{
			for (size_t l = 0; l < line; l++)
			{
				os << "| ";
				for (size_t i = 0; i < column; i++)
				{
					if (i == column - 1)
					{
						os << vec.m_vec[i + column * l];
						continue;
					}
					os << vec.m_vec[i + column * l] << ", ";
				}
				os << " |" << std::endl;
			}
			return os;
		}
	};
}

#include "matrix.inl"

#pragma once

#include <type_traits>
#include <initializer_list>

namespace maths
{
	template<NumberT T, int line, int column>
	class TMatrix
	{
	private:
		T* m_vec = nullptr;
		T size = line * column;

	public:

		// Constructor - Destructor
		TMatrix();
		TMatrix(const TMatrix<T,line,column>& other);
		TMatrix(const std::initializer_list<std::initializer_list<T>>& l);
		virtual ~TMatrix() = default;

		// Operator
		TMatrix<T, line, column>& operator=(const TMatrix<T, line, column>& other);
		T& operator[](const size_t& index);
		TMatrix<T, line, column> operator+(const TMatrix<T, line, column>& other);
		TMatrix<T, line, column> operator-(const TMatrix<T, line, column>& other);

		friend std::ostream& operator<<(std::ostream& os, const TMatrix<T,line,column>& vec)
		{
			for (size_t l = 0; l < line; l++)
			{
				os << "| ";
				for (size_t i = 0; i < column; i++)
				{
					if (i == column - 1)
					{
						os << vec.m_vec[i + line * l];
						continue;
					}
					os << vec.m_vec[i + line * l] << ", ";
				}
				os << " |" << std::endl;
			}
			return os;
		}

		template<int LOther, int COther>
		TMatrix<T, line, COther> operator*(const TMatrix<T, LOther, COther>& other);

		TMatrix<T, line, column> operator*(const T& other);
		TMatrix<T, line, column> operator/(const T& other);

		// Function

	};
}

#include "matrix.inl"

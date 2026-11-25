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

	private:
		// Function
		void SwapLine(TMatrix<T, line, column>& mat1, size_t k, size_t k2);
		void MultiplyingLineByScalar(TMatrix<T, line, column>& mat1, size_t k, size_t lambda);
		void LinearCombination(TMatrix<T, line, column>& mat1, size_t k, size_t k2, size_t lambda);

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
		TMatrix<T, line, column>& operator+=(const TMatrix<T, line, column>& other);
		TMatrix<T, line, column> operator-(const TMatrix<T, line, column>& other);
		TMatrix<T, line, column>& operator-=(const TMatrix<T, line, column>& other);

		template<int LOther, int COther>
		TMatrix<T, line, COther> operator*(const TMatrix<T, LOther, COther>& other);
		TMatrix<T, line, column>& operator*=(const TMatrix<T, line, column>& other);

		TMatrix<T, line, column> operator*(const T& other);	
		TMatrix<T, line, column>& operator*=(const T& other);
		TMatrix<T, line, column> operator/(const T& other);
		TMatrix<T, line, column> operator/=(const T& other);

		bool operator==(const TMatrix<T, line, column>& other);
		bool operator!=(const TMatrix<T, line, column>& other);

		// Function
		T Det();
		TMatrix<T, line, column> Inverse() const;
		static TMatrix<T, line, column> Identity();
		TMatrix<T, column, line> Transpose() const;

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

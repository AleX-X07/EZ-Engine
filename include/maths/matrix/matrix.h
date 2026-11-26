#pragma once

#include <type_traits>
#include <initializer_list>
#include <cmath>
#include <cassert>

namespace maths
{

	template<typename T>
	concept NumberT = std::is_integral_v<T> || std::is_floating_point_v<T>;
	
	template<NumberT T, int n>
	class TVecteur;

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
		void SwapLine(size_t k, size_t k2);
		void MultiplyingLineByScalar(size_t k, T lambda);
		void LinearCombination(size_t k, size_t k2, T lambda);

		TVecteur<T, line> MatrixToVec();

	public:

		// Constructor - Destructor
		TMatrix();
		TMatrix(const TMatrix<T,line,column>& other);
		TMatrix(const std::initializer_list<std::initializer_list<T>>& l);
		virtual ~TMatrix() = default;

		// Operator
		TMatrix<T, line, column>& operator=(const TMatrix<T, line, column>& other);
		T& operator[](size_t index);
		const T& operator[](size_t index) const;

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
		TMatrix<T, line, column> Inverse();
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

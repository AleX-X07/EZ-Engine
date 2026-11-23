#pragma once

#include <type_traits>

namespace maths
{
	template<typename T>
	concept NumberT = std::is_integral_v<T> || std::is_floating_point_v<T>;

	template<NumberT T, int line, int column>
	class TMatrix
	{
	private:
		T* m_vec = nullptr;
		size_t size = line * column;

	public:

		// Constructor - Destructor
		TMatrix();
		TMatrix(const TMatrix<T,line,column>& other);
		virtual ~TMatrix() = default;

		// Operator
		TMatrix<T, line, column>& operator=(const TMatrix<T, line, column>& other);
		size_t operator[](const size_t& index);
		TMatrix<T, line, column> operator+(const TMatrix<T, line, column>& other);
		TMatrix<T, line, column> operator-(const TMatrix<T, line, column>& other);

		template<int LOther, int COther>
		TMatrix<T, line, COther> operator*(const TMatrix<T, LOther, COther>& other);

		TMatrix<T, line, column> operator*(const T& other);
		TMatrix<T, line, column> operator/(const T& other);

		// Function

	};
}

#include "matrix.inl"

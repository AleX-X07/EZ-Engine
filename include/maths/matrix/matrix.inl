#pragma once

namespace maths
{
	// Constructor - Destructor
	template<NumberT T, int line, int column>
	TMatrix<T, line, column>::TMatrix()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] = 0;
		}
	}

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
	TMatrix<T, line, column>& TMatrix<T, line, column>::operator+=(const TMatrix<T, line, column>& other)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] += other.m_vec[i];
		}
		return this;
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
	TMatrix<T, line, column>& TMatrix<T, line, column>::operator-=(const TMatrix<T, line, column>& other)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] -= other.m_vec[i];
		}
		return this;
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
	TMatrix<T, line, column>& TMatrix<T, line, column>::operator*=(const TMatrix<T, line, column>& other)
	{
		TMatrix<T, line, column> res = *this * other;
		*this = res;
		return *this;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator*(const T& other)
	{
		TMatrix<T, line, column> res;
		for (size_t i = 0; i < m_size; i++)
		{
			res[i] = m_vec[i] * other;
		}
		return res;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column>& TMatrix<T, line, column>::operator*=(const T& other)
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
		TMatrix<T, line, column> res;
		for (size_t i = 0; i < m_size; i++)
		{
			res[i] = m_vec[i] / other;
		}
		return res;
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::operator/=(const T& other)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_vec[i] /= other;
		}
		return *this;
	}

	template<NumberT T, int line, int column>
	bool TMatrix<T, line, column>::operator==(const TMatrix<T, line, column>& other)
	{
		bool res = true;
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_vec[i] != other.m_vec[i])
			{
				res = false;
			}
		}
		return res;
	}

	template<NumberT T, int line, int column>
	bool TMatrix<T, line, column>::operator!=(const TMatrix<T, line, column>& other)
	{
		bool res = false;
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_vec[i] != other.m_vec[i])
			{
				res = true;
			}
		}
		return res;
	}

	// Function
	template<NumberT T, int line, int column>
	void TMatrix<T, line, column>::SwapLine(TMatrix<T, line, column>& mat1, size_t k, size_t k2)
	{
		assert(k < line);
		assert(k2 < line);

		for (size_t i = 0; i < column; i++)
		{
			size_t index = i + column * k;
			size_t index2 = i + column * k2;
			T temp = mat1[index2];
			T temp2 = mat1[index];
			mat1[index] = temp;
			mat1[index2] = temp2;
		}	
	}

	template<NumberT T, int line, int column>
	void TMatrix<T, line, column>::MultiplyingLineByScalar(TMatrix<T, line, column>& mat1, size_t k, size_t lambda)
	{
		assert(k < line);
		if (lambda != 0)
		{
			for (size_t i = 0; i < column; i++)
			{
				size_t index = i + column * k;
				mat1[index] *= lambda;
			}
		}
	}

	template<NumberT T, int line, int column>
	void TMatrix<T, line, column>::LinearCombination(TMatrix<T, line, column>& mat1, size_t k, size_t k2, size_t lambda)
	{
		assert(k < line);
		assert(k2 < line);
		if (k != k2)
		{
			if (lambda != 0)
			{
				for (size_t i = 0; i < column; i++)
				{
					size_t index = i + column * k;
					size_t index2 = i + column * k2;
					mat1[index] += mat1[index2] * lambda;
				}
			}
		}

	}

	template<NumberT T, int line, int column>
	T TMatrix<T, line, column>::Det()
	{
		static_assert(line == column);
		T res = 0;
		if constexpr (line == 1 && column == 1)
		{
			return res += m_vec[0];
		}
		else if constexpr (line == 2 && column == 2)
		{
			return res += m_vec[0] * m_vec[3] - m_vec[1] * m_vec[2];
		}
		else
		{
			for (size_t i = 0; i < column; i++)
			{
				int val = 0;
				if (i % 2 == 0)
				{
					val = 1;
				}
				else
				{
					val = -1;
				}
				TMatrix<T, line - 1, column - 1> mat;
				int k = 0;
				for (size_t l = 1; l < line; l++)
				{
					for (size_t c = 0; c < column; c++)
					{
						if (c == i)
						{
							continue;
						}
						mat[k++] = m_vec[c + column * l];
					}
				}
				res += (val * m_vec[i] * mat.Det());
			}
			return res;
		}
	}

	template<NumberT T, int line, int column>
	TMatrix<T, line, column> TMatrix<T, line, column>::Inverse() const
	{
		static_assert(line == column);
		T det = this->Det();
		if (det != 0)
		{
			TMatrix<T, line, column> res = *this;
			TMatrix<T, line, column> identity = this->Identity();

			T pivot;

			for (size_t k = 0; k < column; k++)
			{
				for (size_t i = 0; i < line; i++)
				{
					if (i >= k)
					{
						if (i != k && i != 0)
						{
							SwapLine(res, k, i);
							SwapLine(identity, k, i);
						}
						pivot = res[i];
						break;
					}
				}
				res[k] /= pivot;
				identity[k] /= pivot;
			}
			return identity;
		}
		TMatrix<T, line, column> echec;
		return echec;
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

	template<NumberT T, int line, int column>
	TMatrix<T, column, line> TMatrix<T, line, column>::Transpose() const
	{
		TMatrix<T, column, line> res;
		for (size_t i = 0; i < line; i++)
		{
			for (size_t y = 0; y < column; y++)
			{
				res[i + line * y] = m_vec[y + column * i];
			}
		}
		return res;
	}
}
#pragma once

namespace maths
{
	// Constructor - Desctructor
	template<typename T>
	TVecteur2<T>::TVecteur2() : TVecteur<T, 2>(), x(this->m_vec[0]), y(this->m_vec[1]) 
	{}
}

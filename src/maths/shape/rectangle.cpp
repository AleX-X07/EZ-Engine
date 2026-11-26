#include "maths/shape/rectangle.h"

maths::Rectangle::Rectangle(TVecteur2<float> size)
{
}

void maths::Rectangle::SetPosition(TVecteur2<float>& pos)
{
	m_pos = pos;
}

void maths::Rectangle::SetSize(TVecteur2<float>& size)
{
	m_size = size;
}

maths::TVecteur2<float>& maths::Rectangle::GetPosition()
{
	return m_pos;
}

maths::TVecteur2<float>& maths::Rectangle::GetSize()
{
	return m_size;
}

#pragma once

#include <maths/vecteur/vecteur2d.h>

namespace maths
{
	class Rectangle
	{
	private:
		TVecteur2<float> m_pos;
		TVecteur2<float> m_size;

	public:
		Rectangle(TVecteur2<float> size = {});
		~Rectangle() = default;

		void SetPosition(TVecteur2<float>& pos);
		void SetSize(TVecteur2<float>& size);

		TVecteur2<float>& GetPosition();
		TVecteur2<float>& GetSize();
	};
}
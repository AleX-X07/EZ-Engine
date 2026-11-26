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

		void SetPosition(const TVecteur2<float>& pos);
		void SetSize(TVecteur2<float>& size);

		TVecteur2<float>& GetPos();
		TVecteur2<float>& GetSize();
	};
}
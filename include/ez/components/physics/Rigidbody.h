#pragma once
#include <ez/Component.h>

#include <maths/vecteur/vecteur2d.h>

namespace ez::components::physics
{
	class Rigidbody final : public Component
	{
	public:
		maths::TVecteur2<float> Velocity = { 0.0f,0.0f };
		maths::TVecteur2<float> AngularVelocity = { 0.0f,0.0f };
		float Mass = 1.0f;
		bool IsDynamic = true;

	public:
		Rigidbody(GameObject* owner);
		virtual ~Rigidbody() = default;

		virtual void Update(float dt, systeme::Systeme& m_systeme) override;
	};
}
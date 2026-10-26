#pragma once
#include <Component.h>

class Movement :
	public Component
{
private:
	float m_speed = 0.0f;

public:
	Movement(GameObject* owner, float y_speed);
	virtual ~Movement() = default;

	virtual void Update(float dt, Systeme* m_systeme) override;
};
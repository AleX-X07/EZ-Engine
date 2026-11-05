#include "BoxCollider.h"

BoxCollider::BoxCollider(GameObject* owner) : Component(owner)
{
	m_rect.setPosition(owner->GetTransform());
	m_rect.setOrigin(owner->GetSize() / 2.0f);
}

void BoxCollider::SetListObject(std::vector<GameObject*>& _listObj)
{
	listObj = &_listObj;
}

void BoxCollider::SetSize(sf::Vector2f _size)
{
	m_rect.setSize(_size);
	m_rect.setOrigin(_size/2.0f);
}

void BoxCollider::Debug()
{
	debug = true;
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Green);
	m_rect.setOutlineThickness(2.f);
}

void BoxCollider::Update(float dt, Systeme* m_systeme)
{
	m_rect.setPosition(owner->GetTransform());

	if (isStatic)
	{
		return;
	}

	if (listObj)
	{
		for (auto& obj : *listObj)
		{
			if (obj != owner)
			{
				auto comp = obj->GetComponent<BoxCollider>();
				if (comp)
				{
					if (CheckCollisionAABB(comp))
					{
						if (!isTrigger)
						{
							ResolveCollisionAABB(obj);
						}
					}
				}
			}
		}
	}
}

void BoxCollider::Render(sf::RenderWindow* m_window)
{
	if (debug)
	{
		m_window->draw(m_rect);
	}
}

bool BoxCollider::CheckCollisionAABB(BoxCollider* _target)
{
	auto _target_pos = _target->m_rect.getPosition();
	auto _target_size = _target->m_rect.getSize();

	auto m_pos = m_rect.getPosition();
	auto m_size = m_rect.getSize();

	auto m_target_x = _target_pos.x - _target_size.x / 2;
	auto m_target_y = _target_pos.y - _target_size.y / 2;

	auto m_pos_x = m_pos.x - m_size.x / 2;
	auto m_pos_y = m_pos.y - m_size.y / 2;

	return m_pos_x + m_size.x > m_target_x &&
		m_pos_x < m_target_x + _target_size.x &&
		m_pos_y + m_size.y > m_target_y &&
		m_pos_y < m_target_y + _target_size.y;
}

void BoxCollider::ResolveCollisionAABB(GameObject* _target)
{
	auto m_pos = m_rect.getPosition();
	auto m_size = m_rect.getSize();

	auto comp = _target->GetComponent<BoxCollider>();
	
	if (comp)
	{
		auto m_target_pos = comp->m_rect.getPosition();
		auto m_target_size = comp->m_rect.getSize();

		auto distX = m_pos.x - m_target_pos.x;
		auto distY = m_pos.y - m_target_pos.y;

		float overlapX = (m_size.x / 2.0f) + (m_target_size.x / 2.0f) - std::abs(distX);
		float overlapY = (m_size.y / 2.0f) + (m_target_size.y / 2.0f) - std::abs(distY);

		if (overlapX <= 0 || overlapY <= 0) return;

		if (overlapX < overlapY)
		{
			if (distX > 0)
			{
				owner->GetTransform().x = m_target_pos.x + (m_target_size.x / 2.0f) + (m_size.x / 2.0f);
			}
			else
			{
				owner->GetTransform().x = m_target_pos.x - (m_target_size.x / 2.0f) - (m_size.x / 2.0f);
			}
		}
		else
		{
			if (distY > 0)
			{
				owner->GetTransform().y = m_target_pos.y + (m_target_size.y / 2.0f) + (m_size.y / 2.0f);
			}
			else
			{
				owner->GetTransform().y = m_target_pos.y - (m_target_size.y / 2.0f) - (m_size.y / 2.0f);
			}
		}
	}
}

#include "ez/components/physics/BoxCollider.h"

ez::components::physics::BoxCollider::BoxCollider(GameObject& owner) : Component(owner)
{
	m_rect.setPosition(m_owner.GetTransform());
	m_rect.setOrigin(m_owner.GetSize() / 2.0f);
}

void ez::components::physics::BoxCollider::SetListObject(std::vector<GameObject*>& listobj)
{
	m_listobj = &listobj;
}

void ez::components::physics::BoxCollider::SetSize(const sf::Vector2f& size)
{
	m_rect.setSize(size);
	m_rect.setOrigin(size / 2.f);
}

void ez::components::physics::BoxCollider::Debug()
{
	debug = true;
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Green);
	m_rect.setOutlineThickness(2.f);
}

bool ez::components::physics::BoxCollider::OnTriggerEnter(GameObject& other)
{
	return false;
}

void ez::components::physics::BoxCollider::Update(float dt, systeme::Systeme& m_systeme)
{
	m_rect.setPosition(m_owner.GetTransform());

	if (isStatic)
	{
		return;
	}

	if (m_listobj)
	{
		for (auto& obj : *m_listobj)
		{
			if (obj != &m_owner)
			{
				auto comp = obj->GetComponent<BoxCollider>();
				if (comp)
				{
					if (CheckCollisionAABB(*obj))
					{
						if (!isTrigger)
						{
							ResolveCollisionAABB(*obj);
						}
					}
				}
			}
		}
	}
}

void ez::components::physics::BoxCollider::Render(sf::RenderWindow& m_window)
{
	if (debug)
	{
		m_window.draw(m_rect);
	}
}

bool ez::components::physics::BoxCollider::CheckCollisionAABB(GameObject& other)
{
	auto* target_box = other.GetComponent<BoxCollider>();

	if (target_box)
	{
		auto _target_pos = target_box->m_rect.getPosition();
		auto _target_size = target_box->m_rect.getSize();

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
	return false;
}

void ez::components::physics::BoxCollider::ResolveCollisionAABB(GameObject& other)
{
	auto m_pos = m_rect.getPosition();
	auto m_size = m_rect.getSize();

	auto* comp = other.GetComponent<BoxCollider>();

	if (comp)
	{
		auto m_target_pos = comp->m_rect.getPosition();
		auto m_target_size = comp->m_rect.getSize();

		auto distX = m_pos.x - m_target_pos.x;
		auto distY = m_pos.y - m_target_pos.y;

		float overlapX = (m_size.x / 2.f) + (m_target_size.x / 2.f) - std::abs(distX);
		float overlapY = (m_size.y / 2.f) + (m_target_size.y / 2.f) - std::abs(distY);

		if (overlapX <= 0 || overlapY <= 0) return;

		if (overlapX < overlapY)
		{
			if (distX > 0)
			{
				m_owner.GetTransform().x = m_target_pos.x + (m_target_size.x / 2.f) + (m_size.x / 2.f);
			}
			else
			{
				m_owner.GetTransform().x = m_target_pos.x - (m_target_size.x / 2.f) - (m_size.x / 2.f);
			}
		}
		else
		{
			if (distY > 0)
			{
				m_owner.GetTransform().y = m_target_pos.y + (m_target_size.y / 2.f) + (m_size.y / 2.f);
			}
			else
			{
				m_owner.GetTransform().y = m_target_pos.y - (m_target_size.y / 2.f) - (m_size.y / 2.f);
			}
		}
	}
}

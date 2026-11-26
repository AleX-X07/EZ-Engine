#pragma once
#include <cmath>

#include <ez/GameScene.h>

#include <ez/Component.h>

#include <maths/maths.h>

namespace ez::components::physics
{
	class BoxCollider final : public Component
	{
	private:
		maths::Rectangle m_rect;

		std::vector<GameObject*>* m_listobj = nullptr;

		bool debug = false;

	public:
		bool isTrigger = false;
		bool isStatic = false;

	public:
		BoxCollider(GameObject* owner);
		virtual ~BoxCollider() = default;

		void SetListObject(std::vector<GameObject*>& listobj);
		void SetSize(const sf::Vector2f& size);

		//void Debug();

		// Need func OnTrigger enter/leave/stay
		bool OnTriggerEnter(GameObject& other);
		bool OnTriggerStay(GameObject& other);
		bool OnTriggerLeave(GameObject& other);

		virtual void Update(float dt, systeme::Systeme& m_systeme) override;
		virtual void Render(sf::RenderWindow& m_window) override;

	private:
		bool CheckCollisionAABB(GameObject& other);
		void ResolveCollisionAABB(GameObject& other);
	};
}
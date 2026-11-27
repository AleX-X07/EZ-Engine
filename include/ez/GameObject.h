#pragma once
#include <SFML/Graphics.hpp>

#include <ez/Component.h>

#include <maths/maths.h>

namespace ez
{
	class GameScene;

	class GameObject
	{
	private:
		const std::string m_name;
		maths::TVecteur2<float> m_transform;
		maths::TVecteur2<float> m_size;

		std::vector<Component*> m_components;

		GameScene& m_current_scene;

		int m_order = 0;

	public:

		GameObject(GameScene& current_scene, const std::string& name);
		~GameObject();

		void SetOrder(int order);
		int GetOrder();

		void Update(float dt, systeme::Systeme& m_systeme);
		void Render(sf::RenderWindow& m_window);

		const std::string& GetName() const;
		maths::TVecteur2<float>& GetTransform();
		maths::TVecteur2<float>& GetSize();

		template<typename T, typename... ARGS> T* AddComponent(ARGS... args)
		{
			auto* comp = new T(this, args...);
			m_components.push_back(comp);
			return comp;
		}

		template<typename T> T* GetComponent()
		{
			for (auto& comp : m_components)
			{
				auto* _cast = dynamic_cast<T*>(comp);
				if (_cast)
				{
					return _cast;
				}
			}
			return nullptr;
		};

		template<typename T> bool HasComponent()
		{
			for (auto& comp : m_components)
			{
				auto* _cast = dynamic_cast<T*>(comp);
				if (_cast)
				{
					return true;
				}
			}
			return false;
		}

		template<typename T> void RemoveComponent()
		{
			for (auto it = m_components.begin(); it != m_components.end(); it++)
			{
				if (dynamic_cast<T*>(*it))
				{
					delete* it;
					m_components.erase(it);
					return;
				}
			}
		}
	};
}


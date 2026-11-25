#pragma once
#include <SFML/Graphics.hpp>

#include <ez/Component.h>

namespace ez
{
	class GameScene;

	class GameObject
	{
	private:
		const std::string m_name;
		sf::Vector2f m_transform;
		sf::Vector2f m_size;

		std::vector<Component*> m_components;

		GameScene& m_current_scene;

	public:

		GameObject(GameScene& current_scene, const std::string& name);
		~GameObject();

		void Update(float dt, systeme::Systeme& m_systeme);
		void Render(sf::RenderWindow& m_window);

		const std::string& GetName() const;
		sf::Vector2f& GetTransform();
		sf::Vector2f& GetSize();

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


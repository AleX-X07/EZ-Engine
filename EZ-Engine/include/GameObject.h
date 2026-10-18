#pragma once
#include <SFML/Graphics.hpp>
#include <Component.h>

class Systeme;

class GameObject
{
private:
	std::string name = "";
	sf::Vector2f Transform;
	sf::Vector2f Size;

	std::vector<Component*> myComponent;

public:

	GameObject(std::string _name);
	~GameObject();

	void Update(float dt, Systeme* m_systeme);
	void Render(sf::RenderWindow* m_window);

	std::string& GetName();
	sf::Vector2f& GetTransform();
	sf::Vector2f& GetSize();

	template<typename T, typename... ARGS> T* AddComponent(ARGS... args)
	{
		auto* comp = new T(this, args...);
		myComponent.push_back(comp);
		return comp;
	}

	template<typename T> T* GetComponent()
	{
		for (auto& comp : myComponent)
		{
			auto* _cast = dynamic_cast<T*>(comp);
			if (_cast)
			{
				return _cast;
			}
		}
	};

	template<typename T> bool HasComponent()
	{
		for (auto& comp : myComponent)
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
		for (auto it = myComponent.begin(); it != myComponent.end(); it++)
		{
			if (dynamic_cast<T*>(*it))
			{
				delete *it;
				myComponent.erase(it);
				return;
			}
		}
	}

};
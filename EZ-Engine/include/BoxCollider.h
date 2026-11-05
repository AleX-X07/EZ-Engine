#pragma once
#include <cmath>

#include <GameScene.h>

#include <Component.h>

class BoxCollider final : public Component
{
private:
	sf::RectangleShape m_rect;

	bool debug = false;

	std::vector<GameObject*>* listObj = nullptr;

public:
	bool isTrigger = false;
	bool isStatic = false;

public:
	BoxCollider(GameObject* _owner);
	~BoxCollider() = default;

	void SetListObject(std::vector<GameObject*>& _listObj);
	void SetSize(sf::Vector2f _size);

	void Debug();

	// Need func OnTrigger enter/leave/stay

	virtual void Update(float dt, Systeme* m_systeme) override;
	virtual void Render(sf::RenderWindow* m_window) override;

private:
	bool CheckCollisionAABB(BoxCollider* _target);
	void ResolveCollisionAABB(GameObject* _target);
};
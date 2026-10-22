#include "ExempleGame.h"

#include <RenderComp.h>
#include <movement.h>

ExempleGame::ExempleGame() : Game()
{
}

ExempleGame::~ExempleGame()
{
}

void ExempleGame::Init()
{
	// First Scene TestZone
	AddScene("Test");

	// Creating Object
	auto* m_scene = GetScene("Test");
	{
		m_scene->AddObject("Obj");
		auto* obj1 = m_scene->GetObject("Obj");
		obj1->GetTransform() = { 100,100 };
		obj1->GetSize() = { 100,100 };

		// Creating Components
		// Render
		auto render = obj1->AddComponent<RenderComp>();
		render->SetTexture("../EZ-Engine/assets-debug/red_block.png");
		// Movement
		float speed = 100.0f;
		auto movement = obj1->AddComponent<Movement>(speed);
	}
}


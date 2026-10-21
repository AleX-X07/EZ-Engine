#include "ExempleGame.h"

#include <RenderComp.h>

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
	auto* m_scene = GetScene("Test");
	{
		m_scene->AddObject("Obj");
		auto* obj1 = m_scene->GetObject("Obj");
		auto render = obj1->AddComponent<RenderComp>();
		render->SetTexture("C:/Users/alexs/Documents/GitHub/EZ-Engine/EZ-Engine/assets-debug/red_block.png");
		obj1->GetTransform() = { 100,100 };
		obj1->GetSize() = {100,100};
	}
}


#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

GameEngineRenderer::GameEngineRenderer()
{
}

GameEngineRenderer::~GameEngineRenderer()
{
}


void GameEngineRenderer::Start()
{
	GetActor()->GetLevel()->PushRenderer(this);
}

void GameEngineRenderer::Render(float _DeltaTime)
{
	//												0000			100,100,100							¹ÝÀ¸·Î = 50,50,50
	float4 LeftTop = GetActor()->GetTransform().GetPosition() - GetActor()->GetTransform().GetScale().Half();
	//												-50,-50,-50
	float4 RightBot = GetActor()->GetTransform().GetPosition() + GetActor()->GetTransform().GetScale().Half();
	//												50 50 

	POINT Vertex[4];

	Vertex[0].x = -50 * GetActor()->GetTransform().GetScale().ix() + GetActor()->GetTransform().GetPosition().ix();
	Vertex[0].y = -50 * GetActor()->GetTransform().GetScale().iy() + GetActor()->GetTransform().GetPosition().iy();

	Vertex[1].x = 50 * GetActor()->GetTransform().GetScale().ix() + GetActor()->GetTransform().GetPosition().ix();
	Vertex[1].y = -50 * GetActor()->GetTransform().GetScale().iy() + GetActor()->GetTransform().GetPosition().iy();

	Vertex[2].x = 50 * GetActor()->GetTransform().GetScale().ix() + GetActor()->GetTransform().GetPosition().ix();
	Vertex[2].y = 50 * GetActor()->GetTransform().GetScale().iy() + GetActor()->GetTransform().GetPosition().iy();

	Vertex[3].x = -50 * GetActor()->GetTransform().GetScale().ix() + GetActor()->GetTransform().GetPosition().ix();
	Vertex[3].y = 50 * GetActor()->GetTransform().GetScale().iy() + GetActor()->GetTransform().GetPosition().iy();

	Polygon(GameEngineWindow::GetHDC(),Vertex,4);
	//Rectangle(GameEngineWindow::GetHDC(), LeftTop.ix(), LeftTop.iy(), RightBot.ix(), RightBot.iy());
}


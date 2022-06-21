#include "GameEngineCamera.h"
#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"

GameEngineCamera::GameEngineCamera()
{
}

GameEngineCamera::~GameEngineCamera()
{
}

void GameEngineCamera::Render(float _DeltaTime)
{
	// 랜더하기 전에 

	View.View(
		GetActor()->GetTransform().GetLocalPosition(),
		GetActor()->GetTransform().GetForwardVector(),
		GetActor()->GetTransform().GetUpVector());

	// View.View(GetTransform().GetLocalPosition(), GetTransform().GetForwardVector(), GetTransform().GetUpVector());
	// Projection.

	for (const std::pair<int, std::list<GameEngineRenderer*>>& Group : AllRenderer_)
	{
		float ScaleTime = GameEngineTime::GetInst()->GetDeltaTime(Group.first);
		for (GameEngineRenderer* const Renderer : Group.second)
		{
			Renderer->GetTransform().SetView(View);
			Renderer->GetTransform().SetProjection(Projection);
			Renderer->GetTransform().CalculateWorldViewProjection();
			Renderer->Render(ScaleTime);
		}
	}
}

void GameEngineCamera::Start()
{
	GetActor()->GetLevel()->PushCamera(this);
}

void GameEngineCamera::PushRenderer(GameEngineRenderer* _Renderer)
{
	AllRenderer_[_Renderer->GetOrder()].push_back(_Renderer);
}
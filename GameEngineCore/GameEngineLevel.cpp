#include "GameEngineLevel.h"
#include "GameEngineActor.h"
#include "GameEngineRenderer.h"
#include "GameEngineCamera.h"

GameEngineLevel::GameEngineLevel()
	: MainCamera(nullptr)
	, UIMainCamera(nullptr)
{
}

GameEngineLevel::~GameEngineLevel()
{
	for (const std::pair<int, std::list<GameEngineActor*>>& Group : AllActors)
	{
		for (GameEngineActor* Actor : Group.second)
		{
			if (nullptr == Actor)
			{
				continue;
			}

			delete Actor;
		}
	}
}


void GameEngineLevel::ActorUpdate(float _DelataTime)
{
	for (const std::pair<int, std::list<GameEngineActor*>>& Group : AllActors)
	{
		float ScaleTime = GameEngineTime::GetInst()->GetDeltaTime(Group.first);
		for (GameEngineActor* const Actor : Group.second)
		{
			Actor->AddAccTime(_DelataTime);
			Actor->ComponentUpdate(ScaleTime, _DelataTime);
			Actor->Update(ScaleTime);
		}
	}

	for (const std::pair<int, std::list<GameEngineActor*>>& Group : AllActors)
	{
		float ScaleTime = GameEngineTime::GetInst()->GetDeltaTime(Group.first);
		for (GameEngineActor* const Actor : Group.second)
		{
			Actor->GetTransform().CalculateWorld();
			Actor->ComponentCalculateTransform();
		}
	}

}

void GameEngineLevel::PushRenderer(GameEngineRenderer* _Renderer)
{
	MainCamera->PushRenderer(_Renderer);
}

void GameEngineLevel::PushCamera(GameEngineCamera* _Camera)
{
	MainCamera = _Camera;
}

void GameEngineLevel::Render(float _DelataTime)
{
	MainCamera->Render(_DelataTime);
}

void GameEngineLevel::LevelUpdate(float _DeltaTime)
{
	AddAccTime(_DeltaTime);
	Update(_DeltaTime);
	ActorUpdate(_DeltaTime);
	Render(_DeltaTime);
}
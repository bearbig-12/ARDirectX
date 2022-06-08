#include "PlayLevel.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include "Player.h"
#include "Monster.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{
	{
		GameEngineCameraActor* actor = CreateActor<GameEngineCameraActor>();
		actor->GetTransform().SetLocalPosition({ 1280.0f * -0.5F, 720.0f * 0.5f, -100.0f });
	}

	{
		Player* actor = CreateActor<Player>();
	}

	{
		Monster* actor = CreateActor<Monster>();
		actor->GetTransform().SetLocalPosition({ 100.0f, 0.0f, 500.0f });
	}


}
void PlayLevel::Update(float _DeltaTime) {}
void PlayLevel::End() {}

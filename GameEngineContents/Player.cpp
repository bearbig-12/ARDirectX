#include "Player.h"
#include <GameEngineCore/GameEngineRenderer.h>
Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	{
		GameEngineRenderer* RendererTest = CreateComponent<GameEngineRenderer>();
		RendererTest->GetTransform().SetLocalScale({ 100, 100, 0 });
	}
}



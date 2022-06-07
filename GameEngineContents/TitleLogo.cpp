#include "TitleLogo.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
TitleLogo::TitleLogo()
{
}

TitleLogo::~TitleLogo()
{
}

GameEngineRenderer* RendererTest = nullptr;


void TitleLogo::Start()
{
	// GetTransform().SetLocalScale({ 100, 100, 100 });
	GetTransform().SetLocalPosition({ 300, 300, 100 });


	{
		RendererTest = CreateComponent<GameEngineRenderer>();
		RendererTest->GetTransform().SetLocalScale({ 100, 100, 100 });
		RendererTest->GetTransform().SetLocalPosition({ 100, 0, 0 });
	}

	{
		GameEngineCamera* Camera = CreateComponent<GameEngineCamera>();
	}

	TimeAngle = 0.0f;

	// 액터는 => 존재
	// 특화하지 않으면
	// 컴포넌트의 뜻 => 기능


}

void TitleLogo::Update(float _DeltaTime)
{
	TimeAngle += _DeltaTime * 20.0f;

	GetTransform().SetLocalRotation({ 0.0f , 0.0f, TimeAngle });
	RendererTest->GetTransform().SetLocalRotation({ TimeAngle , TimeAngle, TimeAngle });
}

void TitleLogo::End()
{
	int a = 0;
}
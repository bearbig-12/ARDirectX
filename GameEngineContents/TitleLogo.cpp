#include "TitleLogo.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineRenderer.h>

TitleLogo::TitleLogo()
{
}

TitleLogo::~TitleLogo()
{
}

void TitleLogo::Start()
{
	GetTransform().SetScale({ 100, 50, 100 });
	GetTransform().SetPosition({ 300, 300, 100 });
	{
		GameEngineRenderer* Renderer = CreateComponent<GameEngineRenderer>();
		// Renderer->ChangeOrder();
	}

	TimeAngle = 0.0f;

	// ���ʹ� => ����
	// Ưȭ���� ������
	// ������Ʈ�� �� => ���


}

void TitleLogo::Update(float _DeltaTime)
{
	TimeAngle += _DeltaTime * 20.0f;

	GetTransform().SetRotationZDegree(TimeAngle);

	//if (3.0f < GetAccTime())
	//{
	//	GEngine::ChangeLevel("Play");
	//	// GetLevel()->CreateActor();
	//}
}

void TitleLogo::End()
{
	int a = 0;
}
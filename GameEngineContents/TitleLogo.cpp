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
	GetTransform().SetScale({ 100,100,100 });
	GetTransform().SetPosition({ 300,300,100 });

	{
		GameEngineRenderer* Render = CreateComponent<GameEngineRenderer>();

	}

	// ���ʹ� -> ����
	
	// Ưȭ���� ������ = 
	// ������Ʈ�� �� -> ���

}
void TitleLogo::Update(float _DeltaTime)
{
	//if (3.0f < GetAccTime())
	//{
	//	GEngine::ChangeLevel("Play");
	//	//GetLevel()->CreateActor();
	//}
}

void TitleLogo::End()
{
	int a = 0;

}

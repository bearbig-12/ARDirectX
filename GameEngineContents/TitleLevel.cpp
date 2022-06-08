#include "TitleLevel.h"
#include "TitleLogo.h"
#include "Enums.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("LevelChange"))
	{
		GameEngineInput::GetInst()->CreateKey("LevelChange", 'P');
	}

	// ī�޶� ���� ���� ���踦 �� �غ� �ϰ�
	GameEngineCameraActor* CameraActor = CreateActor<GameEngineCameraActor>();
	CameraActor->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -100.0f });
	// [1][0][0][0]
	// [0][1][0][0]
	// [0][0][1][0] ���� ���� �ִ�.
	// [0][0][-100][0] �ڷ� ��������

	// ���� ���� ������Ʈ���� ����
	CreateActor<TitleLogo>(GameObjectGroup::UI);
	// [800][0][0][0]
	// [0][400][0][0]
	// [0][0][1][0] ���� ���� �ִ�.
	// [0][200][0][0] �ڷ� ��������

}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		GEngine::ChangeLevel("Play");
	}

	// ���� �ٲ� ���� �ʱ�ȭ
	// GetAccTime();

}

void TitleLevel::End()
{
	int a = 0;
}
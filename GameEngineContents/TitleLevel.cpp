#include "TitleLevel.h"
#include "TitleLogo.h"
#include "Enums.h"
#include "GameEngineCore/GEngine.h"
TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Start()
{
	//GEngine::createActor();
	CreateActor<TitleLogo>(GameObjectGroup::UI);

	//GameEngineTime::GetInst()->SetTimeScale(GameObjectGroup::Monster, 0.5); // ���͵鸸 ������
}
void TitleLevel::Update(float _DeltaTime)
{
	// ���� �ٲ� ���� �ʱ�ȭ
	//GetAccTime();
}
void TitleLevel::End()
{
	int a = 0;
}
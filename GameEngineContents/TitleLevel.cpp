#include "TitleLevel.h"
#include "TitleLogo.h"
#include "Enums.h"
TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::UserStart()
{
	CreateActor<TitleLogo>(GameObjectGroup::UI);

	//GameEngineTime::GetInst()->SetTimeScale(GameObjectGroup::Monster, 0.5); // ���͵鸸 ������
}
void TitleLevel::UserUpdate(float _DeltaTime)
{
	// ���� �ٲ� ���� �ʱ�ȭ
	//GetAccTime();
}
void TitleLevel::UserEnd()
{
	int a = 0;
}
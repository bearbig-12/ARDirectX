#include "ContentsCore.h"
#include "GameEngineContents/TitleLevel.h"
#include "GameEngineContents/PlayLevel.h"

#pragma comment(lib, "GameEngineBase.lib")


ContentsCore::ContentsCore() 
	: GameEngineCore()
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::UserStart() 
{
	// ���ҽ� �ε� �ϴµ�.
	
	// RTTI ��Ÿ�� Ÿ�� �������̼�
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");

	ChangeLevel("Title");


	//ChangeLevel("");
	// ���� ������ ����
	// �� ���ӿ��� Ÿ��Ʋ ȭ��
	//			�������� 1
	//			�������� 2

}
void ContentsCore::UserUpdate(float _DeltaTime)
{
	// ������ ����� ������ �����մϴ�.
	// ������ ��� �޼��� â�� ������ �Ѵ�.
	// ���� ���� ��Ȳ������ ���Ǳ� ������ ������ ���� ����.
}

void ContentsCore::UserEnd()
{
	int a = 0;
}

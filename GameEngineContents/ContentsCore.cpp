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
	// 리소스 로드 하는데.
	
	// RTTI 런타임 타입 인포메이션
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");

	ChangeLevel("Title");


	//ChangeLevel("");
	// 게임 컨텐츠 정의
	// 이 게임에는 타이틀 화면
	//			스테이지 1
	//			스테이지 2

}
void ContentsCore::UserUpdate(float _DeltaTime)
{
	// 서버가 종료됨 게임을 종료합니다.
	// 무조건 경고 메세지 창을 띄워줘야 한다.
	// 위와 같은 상황에서만 사용되기 때문에 쓸일이 거의 없다.
}

void ContentsCore::UserEnd()
{
	int a = 0;
}

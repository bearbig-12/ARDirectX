#include "ContentsCore.h"


#pragma comment(lib, "GameEngineBase.lib")


ContentsCore::ContentsCore() 
	: GameEngineCore()
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::UserGameStart()
{
	// 리소스 로드 하는데.

}
void ContentsCore::UserGameUpdate()
{
	// 서버가 종료됨 게임을 종료합니다.
	// 무조건 경고 메세지 창을 띄워줘야 한다.
	// 위와 같은 상황에서만 사용되기 때문에 쓸일이 거의 없다.
}

void ContentsCore::UserGameEnd()
{
	int a = 0;
}

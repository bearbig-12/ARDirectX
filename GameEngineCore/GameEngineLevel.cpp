#include "GameEngineLevel.h"
#include "GameEngineActor.h"
GameEngineLevel::GameEngineLevel() 
{
}

GameEngineLevel::~GameEngineLevel() 
{
	for (const std::pair<int, std::list<GameEngineActor*>>& Group : AllActors)
	{
		for (GameEngineActor* Actor : Group.second)
		{
			if (nullptr == Actor)
			{
				continue;
			}

			delete Actor;
		}
	}
}

void GameEngineLevel::ActorUpdate(float _DelataTime)
{
	for (const std::pair<int, std::list<GameEngineActor*>>& Group : AllActors)
	{
		float ScaleTime = GameEngineTime::GetInst()->GetDeltaTime(Group.first);
		for (GameEngineActor* const Data : Group.second)
		{
			Data->AddAccTime(_DelataTime); // acctime �� ������Ʈ�� ������ �󸶳� �������� �˷���
			
		}
	}
}

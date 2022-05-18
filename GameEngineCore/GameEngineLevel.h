#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <list>
#include <map>
// 설명 : 화면(타이틀 화면, 플레이 화면, 인벤토리 화면)
class GameEngineActor;
class GameEngineLevel : 
	public GameEngineNameObject
	, public GameEngineUpdateObject
{
	friend class GameEngineCore;
	//레벨이 현재까지 얼마나 켜져있었는지 시간을 잴 수 있어야 한다.
public:
	// constrcuter destructer
	GameEngineLevel();
	virtual ~GameEngineLevel() = 0;

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	/*template<typename ReturnType, typename ActorType, typename GroupIndexType>
	ReturnType* CreateActor(GroupIndexType _ObjectGroupIndex)
	{
		return CreateActor<ActorType>(static_cast<int>(_ObjectGroupIndex));


	}*/

	template<typename ActorType, typename GroupIndexType>
	GameEngineActor* CreateActor(GroupIndexType _ObjectGroupIndex)
	{
		return CreateActor<ActorType>(static_cast<int>(_ObjectGroupIndex));
	}

	template<typename ActorType>
	GameEngineActor* CreateActor(int _ObjectGroupIndex = 0)
	{
		GameEngineActor* NewActor = new ActorType();

		// AllActors[_ObjectGroupIndex]게 사용하면
		// 없으면 만들어버리고 있으면
		// 찾아서 리턴해준다.
		std::list<GameEngineActor*>& Group = AllActors[_ObjectGroupIndex];

		Group.push_back(NewActor);

		return NewActor;
	}



private:
	// 앞에 있는 int = 0번, 1번 2번 그룹 몬스터
	std::map<int, std::list<GameEngineActor*>> AllActors;

	void ActorUpdate(float _DelataTime);
};


#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <list>
#include <map>

// ���� : ȭ��(Ÿ��Ʋ ȭ��, �÷��� ȭ��, �κ��丮 ȭ��)
class GameEngineActor;
class GameEngineLevel :
	public GameEngineNameObject,
	public GameEngineUpdateObject
{
	friend class GameEngineCore;
	// ������ ������� �󸶳� �����־����� �ð��� ��� �ְ� �Ѵ�.

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
	//template<typename ReturnType, typename ActorType, typename GroupIndexType>
	//ReturnType* CreateActor(GroupIndexType _ObjectGroupIndex)
	//{
	//	return CreateActor<ActorType>(static_cast<int>(_ObjectGroupIndex));
	//}

	template<typename ActorType, typename GroupIndexType>
	GameEngineActor* CreateActor(GroupIndexType _ObjectGroupIndex)
	{
		return CreateActor<ActorType>(static_cast<int>(_ObjectGroupIndex));
	}

	template<typename ActorType>
	GameEngineActor* CreateActor(int _ObjectGroupIndex = 0)
	{
		GameEngineActor* NewActor = new ActorType();

		// AllActors[_ObjectGroupIndex]�� ����ϸ�
		// ������ ���������� ������
		// ã�Ƽ� �������ش�.
		std::list<GameEngineActor*>& Group = AllActors[_ObjectGroupIndex];

		Group.push_back(NewActor);

		return NewActor;
	}



private:
	// 0�� �׷� �÷��̾�
	// 1�� �׷� ����
	// 2�� �׷�
	std::map<int, std::list<GameEngineActor*>> AllActors;

	void ActorUpdate(float _DelataTime);

};


#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <list>
#include <map>

// ���� : ȭ��(Ÿ��Ʋ ȭ��, �÷��� ȭ��, �κ��丮 ȭ��)
class GameEngineCore;
class GameEngineActor;
class GameEngineCamera;
class GameEngineRenderer;
class GameEngineCameraActor;
class GameEngineLevel :
	public GameEngineNameObject,
	public GameEngineUpdateObject
{
	friend GameEngineCore;
	friend GameEngineCamera;
	friend GameEngineRenderer;
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
	ActorType* CreateActor(GroupIndexType _ObjectGroupIndex)
	{
		return CreateActor<ActorType>(static_cast<int>(_ObjectGroupIndex));
	}

	template<typename ActorType>
	ActorType* CreateActor(int _ObjectGroupIndex = 0)
	{
		GameEngineActor* NewActor = new ActorType();
		NewActor->ParentLevel = this;
		NewActor->Start();
		NewActor->SetLevel(this);

		// AllActors[_ObjectGroupIndex]�� ����ϸ�
		// ������ ���������� ������
		// ã�Ƽ� �������ش�.
		std::list<GameEngineActor*>& Group = AllActors[_ObjectGroupIndex];

		Group.push_back(NewActor);

		return dynamic_cast<ActorType*>(NewActor);
	}



private:
	// 0�� �׷� �÷��̾�
	// 1�� �׷� ����
	// 2�� �׷�
	std::map<int, std::list<GameEngineActor*>> AllActors;

	void ActorUpdate(float _DelataTime);

	void LevelUpdate(float DeltaTime);

private:
	// 0�� ��׶���
	// 1�� �÷��̾�
	// 2�� UI
	GameEngineCamera* MainCamera;

	GameEngineCamera* UIMainCamera;

	void PushCamera(GameEngineCamera* _Camera);

	void PushRenderer(GameEngineRenderer* _Renderer);

	void Render(float _DelataTime);
};


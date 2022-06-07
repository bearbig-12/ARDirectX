#pragma once
#include "GameEngineComponent.h"
#include <GameEngineBase/GameEngineTransform.h>

// ���� : ����ε� ������������ �������ϴ� ������Ʈ���� �̰� ��� �޴´�.
class GameEngineTransformComponent : public GameEngineComponent
{
public:
	// constrcuter destructer
	GameEngineTransformComponent();
	~GameEngineTransformComponent();

	// delete Function
	GameEngineTransformComponent(const GameEngineTransformComponent& _Other) = delete;
	GameEngineTransformComponent(GameEngineTransformComponent&& _Other) noexcept = delete;
	GameEngineTransformComponent& operator=(const GameEngineTransformComponent& _Other) = delete;
	GameEngineTransformComponent& operator=(GameEngineTransformComponent&& _Other) noexcept = delete;

	GameEngineTransform& GetTransform()
	{
		return Transform;
	}

protected:

private:
	GameEngineTransform Transform;
};


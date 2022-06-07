#pragma once
#include "GameEngineComponent.h"
#include <GameEngineBase/GameEngineTransform.h>

// 설명 : 기능인데 기하정보까지 가지야하는 컴포넌트들은 이걸 상속 받는다.
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


#pragma once
#include "GameEngineTransformComponent.h"
#include <GameEngineBase/GameEngineMath.h>

// 설명 :
class GameEngineLevel;
class GameEngineCamera;
class GameEngineCamera : public GameEngineTransformComponent
{
	friend GameEngineLevel;

public:
	// constrcuter destructer
	GameEngineCamera();
	~GameEngineCamera();

	// delete Function
	GameEngineCamera(const GameEngineCamera& _Other) = delete;
	GameEngineCamera(GameEngineCamera&& _Other) noexcept = delete;
	GameEngineCamera& operator=(const GameEngineCamera& _Other) = delete;
	GameEngineCamera& operator=(GameEngineCamera&& _Other) noexcept = delete;

protected:
	void Start();

private:
	float4x4 View; // 바라보는것
	float4x4 Projection;

	std::map<int, std::list<class GameEngineRenderer*>> AllRenderer_;

	void Render(float _DeltaTime);

	void PushRenderer(GameEngineRenderer* _Renderer);
};


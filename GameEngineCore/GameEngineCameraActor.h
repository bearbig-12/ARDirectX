#pragma once
#include "GameEngineActor.h"
#include "GameEngineCamera.h"

// ���� :
class GameEngineLevel;
class GameEngineCameraActor : public GameEngineActor
{

public:
	// constrcuter destructer
	GameEngineCameraActor();
	~GameEngineCameraActor();

	// delete Function
	GameEngineCameraActor(const GameEngineCameraActor& _Other) = delete;
	GameEngineCameraActor(GameEngineCameraActor&& _Other) noexcept = delete;
	GameEngineCameraActor& operator=(const GameEngineCameraActor& _Other) = delete;
	GameEngineCameraActor& operator=(GameEngineCameraActor&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	GameEngineCamera* CameraComponent;

};


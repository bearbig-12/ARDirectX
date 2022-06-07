#pragma once
#include "GameEngineMath.h"
#include <list>

// ���� :
class GameEngineTransform
{
public:
	// constrcuter destructer
	GameEngineTransform();
	~GameEngineTransform();

	// delete Function
	GameEngineTransform(const GameEngineTransform& _Other) = delete;
	GameEngineTransform(GameEngineTransform&& _Other) noexcept = delete;
	GameEngineTransform& operator=(const GameEngineTransform& _Other) = delete;
	GameEngineTransform& operator=(GameEngineTransform&& _Other) noexcept = delete;


public:
	inline void SetLocalScale(const float4& _Value)
	{
		LocalScale = _Value;
		LocalScaleMat.Scale(LocalScale);
	}

	// �ƹ��� ���Ǽ� �Լ��� ��������
	void SetLocalRotation(const float4& _Value)
	{
		LocalRotation = _Value;
		LocalRotateMat.RotationRadian(LocalRotation * GameEngineMath::DegreeToRadian);
	}

	inline void SetLocalPosition(const float4& _Value)
	{
		LocalPosition = _Value;
		LocalPositionMat.Postion(LocalPosition);
	}

	inline void SetLocalMove(const float4& _Value)
	{
		SetLocalPosition(LocalPosition + _Value);
	}

	inline float4 GetLocalScale() const
	{
		return LocalScale;
	}
	inline float4 GetLocalRotation() const
	{
		return LocalRotation;
	}
	inline float4 GetLocalPosition() const
	{
		return LocalPosition;
	}

	inline float4x4 GetLocalWorld() const
	{
		return LocalWorldMat;
	}

	inline float4x4 GetWorldWorld() const
	{
		return WorldWorldMat;
	}

	void CalculateWorld();

	void PushChild(GameEngineTransform* _Child);

protected:

private:
	GameEngineTransform* Parent;
	std::list<GameEngineTransform*> Childs;

	// ���ð� ������ ���̰� ���� ������ Ȯ���� ��ƾ��մϴ�..
	float4 LocalScale;
	float4 LocalRotation;
	float4 LocalPosition;

	float4x4 LocalScaleMat;
	float4x4 LocalPositionMat;
	float4x4 LocalRotateMat;
	float4x4 LocalWorldMat;

	float4x4 WorldWorldMat;
};

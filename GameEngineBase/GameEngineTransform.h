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

	inline float4x4 GetWorldViewProjection() const
	{
		return WorldViewProjectMat;
	}

	inline float4 GetForwardVector() const
	{
		// �������Ͷ�� �ϴµ�.
		// �������ʹ� ����� ���� �̷�� 3���� ���͸� �������Ͷ�� �մϴ�.
		// 0[1][0][0][0] �� ������
		// 1[0][1][0][0] �� ��
		// 2[0][0][1][0] �� ��
		// 3[0][0][0][1]
		// ���� 1¥�� ���⺤�͸� �����Ѵ�.
		return WorldWorldMat.ArrV[2].NormalizeReturn();
	}

	inline float4 GetUpVector() const
	{
		return WorldWorldMat.ArrV[1].NormalizeReturn();
	}

	inline float4 GetRightVector() const
	{
		return WorldWorldMat.ArrV[0].NormalizeReturn();
	}


	void CalculateWorld();

	void CalculateWorldViewProjection();

	void PushChild(GameEngineTransform* _Child);

	void SetView(const float4x4& _Mat)
	{
		View = _Mat;
	}

	void SetProjection(const float4x4& _Mat)
	{
		Projection = _Mat;
	}

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

	float4x4 View;
	float4x4 Projection;

	float4x4 WorldWorldMat;
	float4x4 WorldViewMat;
	float4x4 WorldViewProjectMat;
};

#pragma once
#include "GameEngineMath.h"
#include <list>

// 설명 :
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


	// 아무리 편의성 함수가 많아져도
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
		// 기저벡터라고 하는데.
		// 기저벡터는 행렬의 축을 이루는 3개의 벡터를 기저백터라고 합니다.
		// 0[1][0][0][0] 내 오른쪽
		// 1[0][1][0][0] 내 위
		// 2[0][0][1][0] 내 앞
		// 3[0][0][0][1]
		// 길이 1짜리 방향벡터를 리턴한다.
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

	// 로컬과 월드의 차이가 뭐냐 개념을 확실히 잡아야합니다..
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

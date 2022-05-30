#pragma once
#include "GameEngineMath.h"

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

protected:

private:
	// 로컬과 월드의 차이가 뭐냐 개념을 확실히 잡아야합니다..

	// 1의 크기를 가졌다.

	// 부피 크기
	float4 Scale;
	// 회전 360분법
	float4 Rotation; // Euler;
	// 위치
	float4 Position;

public:
	inline void SetScale(const float4& _Value)
	{
		Scale = _Value;
	}

	void SetRotationXDegree(const float _Value)
	{
		SetRotationXRadian(_Value * GameEngineMath::DegreeToRadian);
	}

	void SetRotationXRadian(const float _Value)
	{
		Rotation.x = _Value;
	}

	void SetRotationYDegree(const float _Value)
	{
		SetRotationYRadian(_Value * GameEngineMath::DegreeToRadian);
	}

	void SetRotationYRadian(const float _Value)
	{
		Rotation.y = _Value;
	}

	void SetRotationZDegree(const float _Value)
	{
		SetRotationZRadian(_Value * GameEngineMath::DegreeToRadian);
	}

	void SetRotationZRadian(const float _Value)
	{
		Rotation.z = _Value;
	}

	void SetRotationDegree(const float4& _Value)
	{
		SetRotationRadian(_Value * GameEngineMath::DegreeToRadian);
	}

	void SetRotationRadian(const float4& _Value)
	{
		Rotation = _Value;
	}

	inline void SetPosition(const float4& _Value)
	{
		Position = _Value;
	}

	inline void SetMove(const float4& _Value)
	{
		Position += _Value;
	}



	inline float4 GetScale() const
	{
		return Scale;
	}
	inline float4 GetRotation() const
	{
		return Rotation;
	}
	inline float4 GetPosition() const
	{
		return Position;
	}


};


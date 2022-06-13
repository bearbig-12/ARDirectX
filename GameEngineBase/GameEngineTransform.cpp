#include "GameEngineTransform.h"

GameEngineTransform::GameEngineTransform()
	: LocalScale(float4::ONE)
	, LocalPosition(float4::ZERO)
	, LocalRotation(float4::ZERO)
	, Parent(nullptr)
{
}

GameEngineTransform::~GameEngineTransform()
{
}


void GameEngineTransform::CalculateWorld()
{
	LocalWorldMat = LocalScaleMat * LocalRotateMat * LocalPositionMat;

	if (nullptr != Parent)
	{
		// Parent 컴포넌트일 경우에는 액터의 트랜스폼을 부모로 가지게 된다.
		WorldWorldMat = LocalWorldMat * Parent->GetWorldWorld();
	}
	else
	{
		WorldWorldMat = LocalWorldMat;
	}
}

void GameEngineTransform::CalculateWorldViewProjection()
{
	WorldViewMat = WorldWorldMat * View;
	WorldViewProjectMat = WorldViewMat * Projection;
}

void GameEngineTransform::PushChild(GameEngineTransform* _Child)
{
	_Child->Parent = this;
	Childs.push_back(_Child);
}
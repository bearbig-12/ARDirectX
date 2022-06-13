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
		// Parent ������Ʈ�� ��쿡�� ������ Ʈ�������� �θ�� ������ �ȴ�.
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
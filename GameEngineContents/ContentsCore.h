#pragma once

#include <GameEngineCore/GameEngineCore.h>
// ���� :
class ContentsCore : public GameEngineCore
{
public:
	// constrcuter destructer
	ContentsCore();
	~ContentsCore();

	// delete Function
	ContentsCore(const ContentsCore& _Other) = delete;
	ContentsCore(ContentsCore&& _Other) noexcept = delete;
	ContentsCore& operator=(const ContentsCore& _Other) = delete;
	ContentsCore& operator=(ContentsCore&& _Other) noexcept = delete;

	std::string GetWindowTitle() override
	{
		return "MyGame";
	};

protected:

	void Start() override; // ������ �����Ҷ� �ϴ� �� ex ���ҽ� ������Ʈ
	// �� ���α׷��� ��� ��Ȳ������ ��� Update�ϸ鼭 üũ���� �ִٸ� ���⼭ �Ѵ�.
	// ������ ���� ������ �׷����� ����. ������ ���� �����̰� ���� ����Ű�� ������ �����Ѵ�.
	void Update(float _DeltaTime) override;
	void End() override;

private:

};


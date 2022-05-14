#pragma once
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineDebug.h>
// ���� :
class GameEngineCore
{
public:
	template<typename CoreType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();
		//���⿡�� ������� ���ھ �˾ƾ��Ѵ�
		CoreType Core;
		WindowCreate(Core.GetWindowTitle(), &Core);

		
		//core.UserGameStart();
	}
protected:
	virtual std::string GetWindowTitle() { return "MainWindow"; }

	virtual void UserGameStart() = 0;
	virtual void UserGameUpdate() = 0;
	virtual void UserGameEnd() = 0;


	// constrcuter destructer
	GameEngineCore();
	~GameEngineCore();

	template<typename LevelType>
	void LevelCreate(const std::string _Name)
	{
		std::string UpperName = GameEngineString::ToUpperReturn(_Name);
	}
	
private:
	static void WindowCreate(const std::string& _Name, GameEngineCore* _UserCore);
	static void CoreStart(GameEngineCore* _UserCore);	// ���α׷� ����
	static void CoreUpdate(GameEngineCore* _UserCore);	// ���α׷� ������Ʈ
	static void CoreEnd(GameEngineCore* _UserCore); // ���α׷� ������Ʈ


	// delete Function
	GameEngineCore(const GameEngineCore& _Other) = delete;
	GameEngineCore(GameEngineCore&& _Other) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;
};


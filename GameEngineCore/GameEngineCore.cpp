#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>
#include "GameEngineLevel.h"

#pragma comment(lib, "GameEngineBase.lib")

GameEngineLevel* GameEngineCore::CurrentLevel = nullptr;
GameEngineLevel* GameEngineCore::NextLevel = nullptr;

std::map<std::string, class GameEngineLevel*> GameEngineCore::AllLevels;

GameEngineCore::GameEngineCore() 
{
}

GameEngineCore::~GameEngineCore() 
{

}

class GameEngineLevel* GameEngineCore::FindLevel(const std::string& _Name)
{
	std::string UpperName = GameEngineString::ToUpperReturn(_Name);

	std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevels.find(UpperName);
	if (FindIter == AllLevels.end())
	{
		return nullptr;
	}
	return FindIter->second;
}

bool GameEngineCore::ChangeLevel(const std::string& _Name)
{
	
	NextLevel = FindLevel(_Name);

	if (nullptr == NextLevel)
	{
		MsgBoxAssert("�������� �ʴ� ������ �ٲٷ��� �߽��ϴ�.");
		return false;
	}

	return true;
}
void GameEngineCore::CoreStart(GameEngineCore* _UserCore)	// ���α׷� ����
{
	// ������ ������ �Ѵ�.
	// �غ� �����ϰ�
	_UserCore->UserStart();

}

void GameEngineCore::CoreUpdate(GameEngineCore* _UserCore)
{
	if (nullptr != NextLevel)
	{
		if (nullptr != CurrentLevel)
		{
			CurrentLevel->OffEvent();
		}

		CurrentLevel = NextLevel;
		NextLevel = nullptr;
		CurrentLevel->OnEvent();
		GameEngineTime::GetInst()->Reset();
	}


	if (nullptr == CurrentLevel)
	{
		MsgBoxAssert("������ ���������� ������ ������ �����Ҽ��� �����ϴ�.");
	}

	GameEngineTime::GetInst()->Update();


	// �������ؿ��� ������ �ϰ� ������.
	_UserCore->UserUpdate();

	// �������ؿ��� ������ �ϰ� ������.
	CurrentLevel->AddAccTime(GameEngineTime::GetDeltaTime()); // ���� Ȱ������ ���ʰ� �������� ����
	CurrentLevel->UserUpdate();

}
void GameEngineCore::CoreEnd(GameEngineCore* _UserCore)
{
	_UserCore->UserEnd();
	
	for (auto& Level : AllLevels)
	{
		if (nullptr == Level.second)
		{
			continue;
		}
		delete Level.second;
		Level.second = nullptr;
	}

	// �̱��� ���� �Ҵ� �α׸� �����
	GameEngineWindow::Destroy();
	GameEngineTime::Destroy();
	GameEngineInput::Destroy();
	
}

void GameEngineCore::WindowCreate(const std::string& _Name, GameEngineCore* _UserCore)
{
	GameEngineWindow::GetInst()->CreateGameWindow(nullptr, _Name.c_str());
	GameEngineWindow::GetInst()->SetWindowScaleAndPosition({ 0,0 }, { 1280,720 });
	GameEngineWindow::GetInst()->ShowGameWindow();
	GameEngineWindow::GetInst()->MessageLoop(
	std::bind(&GameEngineCore::CoreStart, _UserCore),
	std::bind(&GameEngineCore::CoreUpdate, _UserCore),
	std::bind(&GameEngineCore::CoreEnd, _UserCore)
	);
}
void GameEngineCore::InitializeLevel(GameEngineLevel* _Level, const std::string _Name)
{
	_Level->UserStart();
	_Level->SetName(_Name);

	// AllLevels.insert(std::map<std::string, GameEngineLevel*>::value_type(_Name, NewLevel));
	AllLevels.insert(std::make_pair(_Name, _Level));
}
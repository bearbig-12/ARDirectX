#include <Windows.h>

#pragma comment(lib, "GameEngineBase.lib")
#pragma comment(lib, "GameEngineCore.lib")
#pragma comment(lib, "GameEngineContents.lib")


//#include <GameEngineBase/GameEngineDebug.h>
//#include <GameEngineBase/GameEngineFile.h>
//#include <GameEngineBase/GameEngineDirectory.h>
//#include <GameEngineBase/GameEngineSound.h>
//#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/ContentsCore.h>


int APIENTRY WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//GameEngineDirectory Dir;

	//if (false == Dir.MoveParentToExitsChildDirectory("Resources"))
	//{
	//	MsgBoxAssert("경로를 찾지 못했습니다.");
	//	return 0;
	//}
	//Dir.Move("Resources");
	//Dir.Move("Sound");

	//std::vector<GameEngineFile> Files = Dir.GetAllFile();

	////Ranged For
	////Files 특정한 오퍼레이터가 되어 있으면
	//for (auto& File : Files)
	//{
	//	GameEngineSound::LoadResources(File);

	//	//File
	//	//GameEngineSound::LoadResources("BGM.mp3");
	//}

	//RockManCore Core;

	//GameEngineSound::SoundPlayControl("BGM.mp3");

	//GameEngineWindow::GetInst().CreateGameWindow(hInstance, "WindowTitle");
	//GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0,0 }, { 1280,720 });
	//GameEngineWindow::GetInst().ShowGameWindow();
	//GameEngineWindow::GetInst().MessageLoop(
	//	std::bind(&RockManCore::Init, &Core), 
	//	std::bind(&RockManCore::Loop, &Core)
	//);

	GameEngineCore::Start<ContentsCore>();
	return 0;
}
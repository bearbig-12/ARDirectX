#include <Windows.h>

#pragma comment(lib, "GameEngineBase.lib")

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineSound.h>


int main() 
{
	GameEngineDirectory Dir;

	if (false == Dir.MoveParentToExitsChildDirectory("Resources"))
	{
		MsgBoxAssert("��θ� ã�� ���߽��ϴ�.");
		return 0;
	}
	Dir.Move("Resources");
	Dir.Move("Sound");

	std::vector<GameEngineFile> Files = Dir.GetAllFile();

	//Ranged For
	//Files Ư���� ���۷����Ͱ� �Ǿ� ������
	for (auto& File : Files)
	{
		GameEngineSound::LoadResources(File);

		//File
		//GameEngineSound::LoadResources("BGM.mp3");
	}
	GameEngineSound::SoundPlayControl("BGM.mp3");

	while (true)
	{

	}

	return 0;
}
#include "GameEngineTime.h"
#include <chrono>

GameEngineTime* GameEngineTime::Inst_ = new GameEngineTime();



GameEngineTime::GameEngineTime() 
{
}

GameEngineTime::~GameEngineTime() 
{
}

void GameEngineTime::Reset() 
{
	Prev = std::chrono::steady_clock::now();
	Update();
}

void GameEngineTime::Update() 
{
	
	std::chrono::steady_clock::time_point Current = std::chrono::steady_clock::now();

	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(Current - Prev);


	DeltaTimed = time_span.count();

	Prev = Current;

	DeltaTimef = static_cast<float>(DeltaTimed);
	
}
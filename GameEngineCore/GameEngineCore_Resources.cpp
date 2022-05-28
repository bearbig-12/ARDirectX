#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include "GameEngineLevel.h"

// Resources Header
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

void GameEngineCore::EngineResourcesInitialize()
{
	// 사각형 박스 에러용 텍스처 등등
	// 엔진수준에서 기본적으로 지원줘야 한다고 생각하는
	// 리소스들을 이니셜라이즈하는 단계


	{
		// 0       1

		//    원점

		// 3       2

		std::vector<float4> Vertex;
		Vertex.push_back(float4(-0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, -0.5f));

		GameEngineVertexBuffer::Create("Rect", Vertex);
	}

	{
		// 0       1

		//    원점

		// 3       2

		std::vector<int> Index;

		// 첫번째 삼각형
		// 디폴트 생성자로 인자를 뒤에 추가해주는 요소 추가 함수.
		Index.resize(6);

		// 첫번째
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// 두번째
		Index[3] = 0;
		Index[4] = 2;
		Index[5] = 3;

		GameEngineIndexBuffer::Create("Rect", Index);
	}

	//정 육각형 버텍스 버퍼
	{
		// 0       1

		//    원점

		// 3       2

		std::vector<float4> Vertex;
		Vertex.resize(24);

		//앞면
		Vertex[0] = (float4(-0.5f, 0.5f, 0.5f));
		Vertex[1] = (float4(0.5f, 0.5f, 0.5f));
		Vertex[2] = (float4(0.5f, -0.5f, 0.5f));
		Vertex[3] = (float4(-0.5f, -0.5f, 0.5f));

		//뒷면
		Vertex[4] = float4::VectorRotationToDegreeXAxis(Vertex[0], 180.0f);
		Vertex[5] = float4::VectorRotationToDegreeXAxis(Vertex[1], 180.0f);
		Vertex[6] = float4::VectorRotationToDegreeXAxis(Vertex[2], 180.0f);
		Vertex[7] = float4::VectorRotationToDegreeXAxis(Vertex[3], 180.0f);

		//왼쪽
		Vertex[8] = float4::VectorRotationToDegreeYAxis(Vertex[0], -90.0f);
		Vertex[9] = float4::VectorRotationToDegreeYAxis(Vertex[1], -90.0f);
		Vertex[10] = float4::VectorRotationToDegreeYAxis(Vertex[2], -90.0f);
		Vertex[11] = float4::VectorRotationToDegreeYAxis(Vertex[3], -90.0f);

		//오른쪽
		Vertex[12] = float4::VectorRotationToDegreeYAxis(Vertex[0], 90.0f);
		Vertex[13] = float4::VectorRotationToDegreeYAxis(Vertex[1], 90.0f);
		Vertex[14] = float4::VectorRotationToDegreeYAxis(Vertex[2], 90.0f);
		Vertex[15] = float4::VectorRotationToDegreeYAxis(Vertex[3], 90.0f);

		//위
		Vertex[16] = float4::VectorRotationToDegreeXAxis(Vertex[0], -90.0f);
		Vertex[17] = float4::VectorRotationToDegreeXAxis(Vertex[1], -90.0f);
		Vertex[18] = float4::VectorRotationToDegreeXAxis(Vertex[2], -90.0f);
		Vertex[19] = float4::VectorRotationToDegreeXAxis(Vertex[3], -90.0f);

		//아래
		Vertex[20] = float4::VectorRotationToDegreeXAxis(Vertex[0], 90.0f);
		Vertex[21] = float4::VectorRotationToDegreeXAxis(Vertex[1], 90.0f);
		Vertex[22] = float4::VectorRotationToDegreeXAxis(Vertex[2], 90.0f);
		Vertex[23] = float4::VectorRotationToDegreeXAxis(Vertex[3], 90.0f);

		GameEngineVertexBuffer::Create("BOX", Vertex);
	}

	//정 육각형 인덱스 버퍼
	{
		std::vector<int> Index;

		// 첫번째 삼각형
		// 디폴트 생성자로 인자를 뒤에 추가해주는 요소 추가 함수.
		Index.resize(36);

		for (size_t i = 0; i < 6; ++i)
		{
			Index[0 + i * 6] = 0 + 4 * i;
			Index[1 + i * 6] = 1 + 4 * i;
			Index[2 + i * 6] = 2 + 4 * i;
			Index[3 + i * 6] = 0 + 4 * i;
			Index[4 + i * 6] = 2 + 4 * i;
			Index[5 + i * 6] = 3 + 4 * i;

		}

		GameEngineIndexBuffer::Create("BOX", Index);
	}

	// HomeWork HexaGram
	{
		// Vertex Buffer

		//		0
		//	5		1
		//		C
		//	4		2
		//		3


		std::vector<float4> Vertex;
		Vertex.push_back(float4(0.0f, 0.75f));
		Vertex.push_back(float4(0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, -0.5f));

		Vertex.push_back(float4(0.0f, -0.75f));
		Vertex.push_back(float4(-0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, 0.5f));



		GameEngineVertexBuffer::Create("HexaGram", Vertex);



	}
	{
		// IndexBuffer
		// Need to draw two triangles 0 2 4 ,  1 3 5

		//		0
		//	5		1
		//		C
		//	4		2
		//		3

		std::vector<int> Index;

		Index.resize(6);

		// 첫번째
		Index[0] = 0;
		Index[1] = 2;
		Index[2] = 4;

		// 두번째
		Index[3] = 1;
		Index[4] = 3;
		Index[5] = 5;

		GameEngineIndexBuffer::Create("HexaGram", Index);
	}

	

}


void GameEngineCore::EngineResourcesDestroy()
{
	GameEngineVertexBuffer::ResourcesDestroy();
	GameEngineIndexBuffer::ResourcesDestroy();
}
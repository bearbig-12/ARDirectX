#include "GameEngineMath.h"


const float GameEngineMath::PI = 3.141592653589793238462643383279502884197169399375105820974944f;
const float GameEngineMath::PI2 = PI * 2.0f;
const float GameEngineMath::DEG = 180.0f;

// 180�� 3.14�� �ٲٴ°� 

//                                           3.14 / 180.0f
const float GameEngineMath::DegreeToRadian = PI / DEG;
//                                    3.14 * 180 / 3.14 
const float GameEngineMath::RadianToDegree = DEG / PI;

GameEngineMath::GameEngineMath()
{
}

GameEngineMath::~GameEngineMath()
{
}

const float4 float4::LEFT = { -1.0f, 0.0f, 0.0f, 1.0f };
const float4 float4::RIGHT = { 1.0f, 0.0f, 0.0f, 1.0f };
const float4 float4::UP = { 0.0f, -1.0f, 0.0f, 1.0f };
const float4 float4::DOWN = { 0.0f, 1.0f, 0.0f, 1.0f };
const float4 float4::ZERO = { 0.0f, 0.0f, 0.0f, 0.0f };
const float4 float4::ONE = { 1.0f, 1.0f, 1.0f, 1.0f };

float4 operator*(const float4& _Vector, const float4x4& _Value)
{
	float4 Result;

	Result.x = (_Value.Arr2D[0][0] * _Vector.Arr1D[0]) + (_Value.Arr2D[1][0] * _Vector.Arr1D[1]) + (_Value.Arr2D[2][0] * _Vector.Arr1D[2]) + (_Value.Arr2D[3][0] * _Vector.Arr1D[3]);
	Result.y = (_Value.Arr2D[0][1] * _Vector.Arr1D[0]) + (_Value.Arr2D[1][1] * _Vector.Arr1D[1]) + (_Value.Arr2D[2][1] * _Vector.Arr1D[2]) + (_Value.Arr2D[3][1] * _Vector.Arr1D[3]);
	Result.z = (_Value.Arr2D[0][2] * _Vector.Arr1D[0]) + (_Value.Arr2D[1][2] * _Vector.Arr1D[1]) + (_Value.Arr2D[2][2] * _Vector.Arr1D[2]) + (_Value.Arr2D[3][2] * _Vector.Arr1D[3]);
	Result.w = (_Value.Arr2D[0][3] * _Vector.Arr1D[0]) + (_Value.Arr2D[1][3] * _Vector.Arr1D[1]) + (_Value.Arr2D[2][3] * _Vector.Arr1D[2]) + (_Value.Arr2D[3][3] * _Vector.Arr1D[3]);

	return Result;
}

float4& operator*=(float4& _Vector, const float4x4& _Value)
{
	return _Vector;
}
#pragma once
#include <math.h>
#include <Windows.h>
#include <d3d11_4.h>
#include <d3dcompiler.h>
#include <DirectXPackedVector.h>

#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler")
#pragma comment(lib, "dxguid")


// 설명 :
class GameEngineMath
{
public:
	static const float PIE;
	static const float PIE2;
	static const float DEG;
	static const float DegreeToRadian;
	static const float RadianToDegree;

	static float Lerp(float p1, float p2, float Time)
	{
		return (1.0f - Time) * p1 + Time * p2;
	}

	// 보통 누적된 시간을 Time
	static float LerpLimit(float p1, float p2, float Time)
	{
		if (1.0f <= Time)
		{
			Time = 1.0f;
		}

		return Lerp(p1, p2, Time);
	}

private:
	// constrcuter destructer
	GameEngineMath();
	~GameEngineMath();

	// delete Function
	GameEngineMath(const GameEngineMath& _Other) = delete;
	GameEngineMath(GameEngineMath&& _Other) noexcept = delete;
	GameEngineMath& operator=(const GameEngineMath& _Other) = delete;
	GameEngineMath& operator=(GameEngineMath&& _Other) noexcept = delete;


};

class float4
{
public:
	static float VectorXYtoDegree(const float4& _Postion, const float4& _Target)
	{
		return VectorXYtoRadian(_Postion, _Target) * GameEngineMath::RadianToDegree;
	}

	static float VectorXYtoRadian(const float4& _Postion, const float4& _Target)
	{
		float4 Dir = _Target - _Postion;
		Dir.Normal2D();
		// cos(90) => 1.5
		// acos(1.5) => 90
		float Angle = acosf(Dir.x);

		if (_Postion.y > _Target.y)
		{
			Angle = GameEngineMath::PIE2 - Angle;
		}

		return Angle;
	}


	static float4 DegreeToDirection2D(float _Degree)
	{
		return RadianToDirection2D(_Degree * GameEngineMath::DegreeToRadian);
	}

	static float4 RadianToDirection2D(float _Radian)
	{
		return { cosf(_Radian) , sinf(_Radian) };
	}

	static float4 VectorRotationToDegreeZAxis(const float4& _Value, float _Degree)
	{
		return VectorRotationToRadianZAxis(_Value, _Degree * GameEngineMath::DegreeToRadian);
	}

	static float4 VectorRotationToRadianZAxis(const float4& _Value, float _Radian)
	{
		float4 Rot;
		Rot.x = _Value.x * cosf(_Radian) - _Value.y * sinf(_Radian);
		Rot.y = _Value.x * sinf(_Radian) + _Value.y * cosf(_Radian);
		Rot.z = _Value.z;
		return Rot;
	}

	static float4 VectorRotationToDegreeYAxis(const float4& _Value, float _Degree)
	{
		return VectorRotationToRadianYAxis(_Value, _Degree * GameEngineMath::DegreeToRadian);
	}

	static float4 VectorRotationToRadianYAxis(const float4& _Value, float _Radian)
	{
		float4 Rot;
		Rot.x = _Value.x * cosf(_Radian) - _Value.z * sinf(_Radian);
		Rot.z = _Value.x * sinf(_Radian) + _Value.z * cosf(_Radian);
		Rot.y = _Value.y;
		return Rot;
	}


	static float4 VectorRotationToDegreeXAxis(const float4& _Value, float _Degree)
	{
		return VectorRotationToRadianXAxis(_Value, _Degree * GameEngineMath::DegreeToRadian);
	}

	static float4 VectorRotationToRadianXAxis(const float4& _Value, float _Radian)
	{
		float4 Rot;
		Rot.z = _Value.z * cosf(_Radian) - _Value.y * sinf(_Radian);
		Rot.y = _Value.z * sinf(_Radian) + _Value.y * cosf(_Radian);
		Rot.x = _Value.x;
		return Rot;
	}



	static float4 Lerp(float4 p1, float4 p2, float Time)
	{
		return p1 * (1.0f - Time) + p2 * Time;
	}

	// 보통 누적된 시간을 Time
	static float4 LerpLimit(float4 p1, float4 p2, float Time)
	{
		if (1.0f <= Time)
		{
			Time = 1.0f;
		}

		return Lerp(p1, p2, Time);
	}


	//X = P1X * cosf(40) - P1Y * sinf(40)
	//Y = P1X * sinf(40) + P1Y * cosf(40)



public:
	static const float4 LEFT;
	static const float4 RIGHT;
	static const float4 UP;
	static const float4 DOWN;
	static const float4 ZERO;
	static const float4 ONE;



public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};

		float Arr1D[4];
	};

public:
	bool IsZero2D() const
	{
		return x == 0.0f && y == 0.0f;
	}

public:
	int ix() const
	{
		return static_cast<int>(x);
	}

	int iy() const
	{
		return static_cast<int>(y);
	}

	int iz() const
	{
		return static_cast<int>(z);
	}

	int iw() const
	{
		return static_cast<int>(w);
	}

	POINT GetConvertWindowPOINT()
	{
		return POINT(ix(), iy());
	}

	int hix() const
	{
		return static_cast<int>(x * 0.5f);
	}

	int hiy() const
	{
		return static_cast<int>(y * 0.5f);
	}

	int hiz() const
	{
		return static_cast<int>(z * 0.5f);
	}

	float4 Half() const
	{
		return { x * 0.5f, y * 0.5f , z * 0.5f, 1.0f };
	}

	float Len2D() const
	{
		// sqrtf 제곱근 구해줍니다.
		return sqrtf((x * x) + (y * y));
	}

	float Len3D() const
	{
		// sqrtf 제곱근 구해줍니다.
		return sqrtf((x * x) + (y * y) + (z * z));
	}

	void Normal2D()
	{
		float Len = Len2D();
		if (0 == Len)
		{
			return;
		}

		x /= Len;
		y /= Len;

		// sqrtf 제곱근 구해줍니다.
		return;
	}

	void Range2D(float _Max)
	{
		Normal2D();

		x *= _Max;
		y *= _Max;
		return;
	}


	float& operator[](int _Index)
	{
		return Arr1D[_Index];
	}


	float4 operator-(const float4& _Other) const
	{
		return { x - _Other.x, y - _Other.y, z - _Other.z, 1.0f };
	}

	float4 operator-() const
	{
		return { -x, -y, -z, 1.0f };
	}

	float4 operator+(const float4& _Other) const
	{
		return { x + _Other.x, y + _Other.y, z + _Other.z, 1.0f };
	}

	float4 operator*(const float _Value) const
	{
		return { x * _Value, y * _Value, z * _Value, 1.0f };
	}

	float4& operator+=(const float4& _Other)
	{
		x += _Other.x;
		y += _Other.y;
		z += _Other.z;

		return *this;
	}

	float4& operator-=(const float4& _Other)
	{
		x -= _Other.x;
		y -= _Other.y;
		z -= _Other.z;

		return *this;
	}

	float4& operator*=(const float _Other)
	{
		x *= _Other;
		y *= _Other;
		z *= _Other;

		return *this;
	}


	float4& operator*=(const float4& _Other)
	{
		x *= _Other.x;
		y *= _Other.y;
		z *= _Other.z;

		return *this;
	}

	bool CompareInt2D(const float4& _Value) const
	{
		return ix() == _Value.ix() && iy() == _Value.iy();
	}

	bool CompareInt3D(const float4& _Value) const
	{
		return ix() == _Value.ix() &&
			iy() == _Value.iy() &&
			iz() == _Value.iz();
	}

	float4 RotationToDegreeZ(float _Degree)
	{
		return RotationToRadianZAXis(_Degree * GameEngineMath::DegreeToRadian);
	}

	float4 RotationToRadianZAXis(float _Radian)
	{
		*this = VectorRotationToRadianZAxis(*this, _Radian);
		return *this;
	}

	POINT ToWinAPIPOINT() const
	{
		POINT NewPoint;
		NewPoint.x = ix();
		NewPoint.y = iy();
		return NewPoint;
	}

public:
	float4()
		: x(0.0f), y(0.0f), z(0.0f), w(1.0f)
	{

	}
	float4(float _x, float _y)
		: x(_x), y(_y), z(1.0f), w(1.0f)
	{

	}
	float4(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z), w(1.0f)
	{

	}
	float4(float _x, float _y, float _z, float _w)
		: x(_x), y(_y), z(_z), w(_w)
	{

	}


};

struct GameEngineRect
{
public:
	float4 Pos;
	float4 Scale;

public:
	float4 CenterLeftTopPoint() const
	{
		return { static_cast<float>(CenterLeft()), static_cast<float>(CenterTop()) };
	}

	float4 CenterLeftBotPoint() const
	{
		return { static_cast<float>(CenterLeft()), static_cast<float>(CenterBot()) };
	}

	float4 CenterRightTopPoint() const
	{
		return { static_cast<float>(CenterRight()), static_cast<float>(CenterTop()) };
	}

	float4 CenterRightBotPoint() const
	{
		return { static_cast<float>(CenterRight()), static_cast<float>(CenterBot()) };
	}

	int CenterLeft() const
	{
		return Pos.ix() - Scale.hix();
	}

	int CenterRight() const
	{
		return Pos.ix() + Scale.hix();
	}

	int CenterTop() const
	{
		return Pos.iy() - Scale.hiy();
	}

	int CenterBot() const
	{
		return Pos.iy() + Scale.hiy();
	}

	bool OverLap(const GameEngineRect& _Other)
	{
		if (CenterBot() < _Other.CenterTop())
		{
			return false;
		}

		if (CenterTop() > _Other.CenterBot())
		{
			return false;
		}

		if (CenterRight() < _Other.CenterLeft())
		{
			return false;
		}

		if (CenterLeft() > _Other.CenterRight())
		{
			return false;
		}

		return true;
	}

public:
	GameEngineRect(float4 _Pos, float4 _Scale)
		: Pos(_Pos)
		, Scale(_Scale)
	{

	}
};

class float4x4
{
public:
	union
	{
		float Arr1D[16];
		float Arr2D[4][4];
	};

public:
	float4x4() {
		Indentity();
	}

public:
	void Indentity()
	{
		memset(Arr1D, 0, sizeof(float) * 16);
		Arr2D[0][0] = 1.0f;
		Arr2D[1][1] = 1.0f;
		Arr2D[2][2] = 1.0f;
		Arr2D[3][3] = 1.0f;
	}

	void Scale(const float4& _Value)
	{
		Indentity();
		Arr2D[0][0] = _Value.x;
		Arr2D[1][1] = _Value.y;
		Arr2D[2][2] = _Value.z;
		Arr2D[3][3] = 1.0f;
	}

	void Postion(const float4& _Value)
	{
		Indentity();
		Arr2D[3][0] = _Value.x;
		Arr2D[3][1] = _Value.y;
		Arr2D[3][2] = _Value.z;
		Arr2D[3][3] = 1.0f;
	}


public: // 연산자
	float4x4 operator*(const float4x4& _Value)
	{
		float4x4 Result;

		float x = Arr2D[0][0];
		float y = Arr2D[0][1];
		float z = Arr2D[0][2];
		float w = Arr2D[0][3];
		// Perform the operation on the first row
		Result.Arr2D[0][0] = (_Value.Arr2D[0][0] * x) + (_Value.Arr2D[1][0] * y) + (_Value.Arr2D[2][0] * z) + (_Value.Arr2D[3][0] * w);
		Result.Arr2D[0][1] = (_Value.Arr2D[0][1] * x) + (_Value.Arr2D[1][1] * y) + (_Value.Arr2D[2][1] * z) + (_Value.Arr2D[3][1] * w);
		Result.Arr2D[0][2] = (_Value.Arr2D[0][2] * x) + (_Value.Arr2D[1][2] * y) + (_Value.Arr2D[2][2] * z) + (_Value.Arr2D[3][2] * w);
		Result.Arr2D[0][3] = (_Value.Arr2D[0][3] * x) + (_Value.Arr2D[1][3] * y) + (_Value.Arr2D[2][3] * z) + (_Value.Arr2D[3][3] * w);
		// Repeat for all the other rows
		x = Arr2D[1][0];
		y = Arr2D[1][1];
		z = Arr2D[1][2];
		w = Arr2D[1][3];
		Result.Arr2D[1][0] = (_Value.Arr2D[0][0] * x) + (_Value.Arr2D[1][0] * y) + (_Value.Arr2D[2][0] * z) + (_Value.Arr2D[3][0] * w);
		Result.Arr2D[1][1] = (_Value.Arr2D[0][1] * x) + (_Value.Arr2D[1][1] * y) + (_Value.Arr2D[2][1] * z) + (_Value.Arr2D[3][1] * w);
		Result.Arr2D[1][2] = (_Value.Arr2D[0][2] * x) + (_Value.Arr2D[1][2] * y) + (_Value.Arr2D[2][2] * z) + (_Value.Arr2D[3][2] * w);
		Result.Arr2D[1][3] = (_Value.Arr2D[0][3] * x) + (_Value.Arr2D[1][3] * y) + (_Value.Arr2D[2][3] * z) + (_Value.Arr2D[3][3] * w);
		x = Arr2D[2][0];
		y = Arr2D[2][1];
		z = Arr2D[2][2];
		w = Arr2D[2][3];
		Result.Arr2D[2][0] = (_Value.Arr2D[0][0] * x) + (_Value.Arr2D[1][0] * y) + (_Value.Arr2D[2][0] * z) + (_Value.Arr2D[3][0] * w);
		Result.Arr2D[2][1] = (_Value.Arr2D[0][1] * x) + (_Value.Arr2D[1][1] * y) + (_Value.Arr2D[2][1] * z) + (_Value.Arr2D[3][1] * w);
		Result.Arr2D[2][2] = (_Value.Arr2D[0][2] * x) + (_Value.Arr2D[1][2] * y) + (_Value.Arr2D[2][2] * z) + (_Value.Arr2D[3][2] * w);
		Result.Arr2D[2][3] = (_Value.Arr2D[0][3] * x) + (_Value.Arr2D[1][3] * y) + (_Value.Arr2D[2][3] * z) + (_Value.Arr2D[3][3] * w);
		x = Arr2D[3][0];
		y = Arr2D[3][1];
		z = Arr2D[3][2];
		w = Arr2D[3][3];
		Result.Arr2D[3][0] = (_Value.Arr2D[0][0] * x) + (_Value.Arr2D[1][0] * y) + (_Value.Arr2D[2][0] * z) + (_Value.Arr2D[3][0] * w);
		Result.Arr2D[3][1] = (_Value.Arr2D[0][1] * x) + (_Value.Arr2D[1][1] * y) + (_Value.Arr2D[2][1] * z) + (_Value.Arr2D[3][1] * w);
		Result.Arr2D[3][2] = (_Value.Arr2D[0][2] * x) + (_Value.Arr2D[1][2] * y) + (_Value.Arr2D[2][2] * z) + (_Value.Arr2D[3][2] * w);
		Result.Arr2D[3][3] = (_Value.Arr2D[0][3] * x) + (_Value.Arr2D[1][3] * y) + (_Value.Arr2D[2][3] * z) + (_Value.Arr2D[3][3] * w);
		return Result;

	}
};

float4 operator*(const float4& _Vector, const float4x4& _Value);
float4& operator*=(float4& _Vector, const float4x4& _Value);


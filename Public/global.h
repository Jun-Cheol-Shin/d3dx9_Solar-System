#ifndef GLOBAL_H
#define GLOBAL_H
#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 )
#include <strsafe.h>
#pragma warning( default : 4996 )

struct CVERTEX_NTEX {
	D3DXVECTOR3 pos;
	D3DXVECTOR3 normal;
	float tu, tv;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };
};


enum planetType 
{
	p_Sun = 1,				// 태양
	p_Earth,					// 지구
	p_Moon,					// 달
	p_Mercury,				// 수성
	p_Venus,					// 금성
	p_Mars,					// 화성
	p_Jupiter,				// 목성
	p_Saturn,					// 토성
	p_Uranus,					// 천왕성,
	p_Neptune,					// 해왕성
};

#endif // !GLOBAL_H
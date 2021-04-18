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
	p_Sun = 1,				// �¾�
	p_Earth,					// ����
	p_Moon,					// ��
	p_Mercury,				// ����
	p_Venus,					// �ݼ�
	p_Mars,					// ȭ��
	p_Jupiter,				// ��
	p_Saturn,					// �伺
	p_Uranus,					// õ�ռ�,
	p_Neptune,					// �ؿռ�
};

#endif // !GLOBAL_H
#ifndef CAMERA_H
#define CAMERA_H

#include "global.h"

class Camera 
{
	D3DXVECTOR3 vEyePt;
	D3DXVECTOR3 vLookatPt;
	D3DXVECTOR3 vUpVec;
	D3DXMATRIXA16 viewMat;
	D3DXMATRIXA16 projMat;

public:
	Camera();
	~Camera();

	D3DXMATRIXA16 getViewmat();
	D3DXMATRIXA16 getProjmat();
};

#endif // !CAMERA_H

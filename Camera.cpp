#include "Camera.h"


Camera::Camera()
{
	vEyePt.x = 0;
	vEyePt.y = 15.0f;
	vEyePt.z = -35.0f;

	vLookatPt.x = 0;
	vLookatPt.y = 0;
	vLookatPt.z = 0;

	vUpVec.x = 0;
	vUpVec.y = 1.0f;
	vUpVec.z = 0;

	D3DXMatrixIdentity(&viewMat);
	D3DXMatrixIdentity(&projMat);
}

Camera::~Camera()
{

}


D3DXMATRIXA16 Camera::getProjmat()
{
	D3DXMatrixPerspectiveFovLH(&this->projMat, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	return this->projMat;
}


D3DXMATRIXA16 Camera::getViewmat()
{

	D3DXMatrixLookAtLH(&this->viewMat, &this->vEyePt, &this->vLookatPt, &this->vUpVec);
	return this->viewMat;
}
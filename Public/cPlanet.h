#ifndef CPLANET_H
#define CPLANET_H
#include "global.h"


class cPlanet
{
public:
	planetType				type;

	D3DXVECTOR3				pPos, pScale, pRot;		// 위치, 크기, 회전축

	D3DXMATRIX				matrix;
	D3DXMATRIX				pRotmat, pTransmat, pScalemat, pOrbitmat;

	LPDIRECT3DDEVICE9		p_dev;
	LPDIRECT3DTEXTURE9      p_Texture;

	LPD3DXMESH				mesh;
	LPD3DXMESH				temp_mesh;


	float					p_radius;

	float					degree;
	float					r_degree;

	int mDetail;
	int mNumVert;
	int mNumInd;

	cPlanet(planetType _type, LPDIRECT3DDEVICE9 _device, D3DXVECTOR3 p, float _radius, int _mDetail);
	~cPlanet();

	HRESULT		initTexture();
	void		setTexture();
	void		drawTexture();

	D3DXMATRIX getTransMat();
	D3DXMATRIX getRotMat();
	D3DXMATRIX getScaleMat();
	D3DXMATRIX getOribtMat();
	

	void setMatrix(float speed, D3DXMATRIX _parentMat);
	void OnFrameRender();

	void Clean();

};

#endif // !CPLANET_H

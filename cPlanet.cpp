#include "cPlanet.h"

cPlanet::cPlanet(planetType _type, LPDIRECT3DDEVICE9 _device, D3DXVECTOR3 p, float _radius, int _mDetail)
{
	this->p_dev = _device;
	this->pPos = p;
	this->p_radius = _radius;
	this->type = _type;
	this->p_Texture = NULL;

	this->degree = 0;
	this->r_degree = 0;

	this->mDetail = _mDetail;

	this->pScale.x = this->p_radius;
	this->pScale.y = this->p_radius;
	this->pScale.z = this->p_radius;


	if (initTexture() == S_OK)
	{
		setTexture();
	}
}


cPlanet::~cPlanet()
{

}


void cPlanet::setTexture()
{

	if (SUCCEEDED(D3DXCreateSphere(p_dev, p_radius, mDetail, mDetail, &mesh, NULL)))
	{
		if (SUCCEEDED(mesh->CloneMeshFVF(D3DXMESH_SYSTEMMEM, CVERTEX_NTEX::FVF, p_dev, &temp_mesh)))
		{
			mesh->Release();
		}
	}

	CVERTEX_NTEX* pVerts;

	if (SUCCEEDED(temp_mesh->LockVertexBuffer(0, (void**)&pVerts)))
	{
		int numVerts = temp_mesh->GetNumVertices();

		for (int i = 0; i < numVerts; i++)
		{
			pVerts->tu = asinf(pVerts->normal.x) / D3DX_PI + 0.5f;
			pVerts->tv = asinf(pVerts->normal.y) / D3DX_PI + 0.5f;
			pVerts++;
		}

		temp_mesh->UnlockVertexBuffer();
	}
}


void cPlanet::OnFrameRender()
{
	p_dev->SetTransform(D3DTS_WORLD, &matrix);

	drawTexture();
	temp_mesh->DrawSubset(0);
}




HRESULT cPlanet::initTexture()
{

	if (this->p_Texture == NULL)
	{
		
		switch (this->type)
		{
		case planetType::p_Sun:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"sun.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\sun.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Sun.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Earth:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"earth.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\earth.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Earth.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Moon:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"moon.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\moon.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Moon.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Mercury:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"mercury.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\mercury.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Mercury.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Venus:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"venus.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\venus.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Venus.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Mars:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"mars.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\mars.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Mars.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Jupiter:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"jupiter.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\jupiter.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find jupiter.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Saturn:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"saturn.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\saturn.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Saturn.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Uranus:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"uranus.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\uranus.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Uranus.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		case planetType::p_Neptune:
			if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"neptune.bmp", &this->p_Texture)))
			{
				// If texture is not in current folder, try parent folder
				if (FAILED(D3DXCreateTextureFromFile(this->p_dev, L"..\\neptune.bmp", &this->p_Texture)))
				{
					MessageBox(NULL, L"Could not find Neptune.bmp", L"Textures.exe", MB_OK);
					return E_FAIL;
				}
			}
			break;
		}
	}

	return S_OK;
}

void cPlanet::drawTexture()
{
	this->p_dev->SetTexture(0, this->p_Texture);
	this->p_dev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	this->p_dev->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	this->p_dev->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	this->p_dev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
}


void cPlanet::setMatrix(float speed, D3DXMATRIX _parentMat)
{
	// TRS 행렬 법칙에 따라
	// Scale 행렬 x Rotation 행렬 x Translate 행렬

	switch (this->type) 
	{
		// 태양
	case planetType::p_Sun:
		D3DXMatrixIdentity(&matrix);
		D3DXMatrixScaling(&this->pScalemat, pScale.x, pScale.y, pScale.z);
		D3DXMatrixRotationY(&this->pRotmat, degree++ / (80.0f / speed));
		D3DXMatrixTranslation(&this->pTransmat, this->pPos.x, this->pPos.y, this->pPos.z);
		// SRT 행렬
		matrix = this->pScalemat * this->pRotmat * this->pTransmat;
		break;

		// 달
	case planetType::p_Moon:
		D3DXMatrixIdentity(&matrix);
		D3DXMatrixScaling(&this->pScalemat, pScale.x, pScale.y, pScale.z);
		D3DXMatrixRotationY(&this->pRotmat, degree++ / (80.0f / speed * 2.0f));
		D3DXMatrixTranslation(&this->pTransmat, pPos.x, pPos.y, pPos.z);
		D3DXMatrixRotationY(&this->pOrbitmat, r_degree++ / (80.0f / speed));

		// SRT 행렬  *  공전행렬  *  부모행렬
		matrix = this->pScalemat * this->pRotmat * this->pTransmat * this->pOrbitmat * _parentMat;
		break;

		// 나머지 행성들
	default:
		D3DXMatrixIdentity(&matrix);
		D3DXMatrixScaling(&this->pScalemat, pScale.x, pScale.y, pScale.z);
		D3DXMatrixRotationY(&this->pRotmat, degree++ / (80.0f / speed * 2.0f));
		D3DXMatrixTranslation(&this->pTransmat, pPos.x, pPos.y, pPos.z);
		D3DXMatrixRotationY(&this->pOrbitmat, r_degree++ / (80.0f / speed));

		// SRT 행렬 * 공전행렬
		matrix = this->pScalemat * this->pRotmat * this->pTransmat * this->pOrbitmat;
		break;
	}

	OnFrameRender();
}


void cPlanet::Clean()
{
	p_Texture->Release();
	//pVertexBuffer->Release();
	//mIdx->Release();
	temp_mesh->Release();
}



D3DXMATRIX cPlanet::getTransMat()
{
	return this->pTransmat;
}

D3DXMATRIX cPlanet::getScaleMat()
{
	return this->pScalemat;
}

D3DXMATRIX cPlanet::getRotMat()
{
	return this->pRotmat;
}

D3DXMATRIX cPlanet::getOribtMat()
{
	return this->pOrbitmat;
}
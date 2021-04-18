# d3dx9_Solar-System
![ezgif com-gif-maker](https://user-images.githubusercontent.com/77636255/115138454-41be5380-a067-11eb-84e8-d6c12f2dd150.gif)

![Untitled-8a6b2297-10f8-4803-b5c0-72e743b3c748](https://user-images.githubusercontent.com/77636255/115138477-60244f00-a067-11eb-8ecb-97a075f5bd5d.png)
```c++
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
```

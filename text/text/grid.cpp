#include "grid.h"
#include "direct3d.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "cube.h"
#define FVF_GRID (D3DFVF_XYZ|D3DFVF_DIFFUSE)//FVF定数定義
#define GridVertexCount (44)


static LPDIRECT3DDEVICE9 pDevice = NULL;

typedef struct GridVertex_tag
{
	D3DXVECTOR3 position;
	D3DCOLOR color;
}GridVertex;

GridVertex g_grid_vertex[GridVertexCount];
D3DXMATRIX mtxWorld;

void Grid_Init(void)
{
	pDevice = GetDevice();

	for (int i = 0; i < GridVertexCount / 2; i = i + 2)
	{
		g_grid_vertex[i].position = D3DXVECTOR3(-5.0f, 0.0f, 5.0f - i / 2 );
		g_grid_vertex[i].color = D3DCOLOR_RGBA(0, 255, 0, 255);
		g_grid_vertex[i + 1].position = D3DXVECTOR3(5.0f, 0.0f, 5.0f - i / 2);
		g_grid_vertex[i + 1].color = D3DCOLOR_RGBA(0, 255, 0, 255);

		//縦
		g_grid_vertex[i + GridVertexCount / 2].position = D3DXVECTOR3(-5.0f + i / 2, 0.0f, 5.0f);
		g_grid_vertex[i + GridVertexCount / 2].color = D3DCOLOR_RGBA(255, 255, 0, 255);
		g_grid_vertex[i + GridVertexCount / 2 + 1].position = D3DXVECTOR3(-5.0f + i / 2, 0.0f, -5.0f);
		g_grid_vertex[i + GridVertexCount / 2 + 1].color = D3DCOLOR_RGBA(255, 255, 0, 255);
	}

	D3DXMatrixIdentity(&mtxWorld);//単位行列
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);//ワールド変換行列をデバイスに送る
}

void Grid_Uninit(void)
{

}

void Grid_Draw(void)
{
	//描画
	pDevice->SetFVF(FVF_GRID);
	pDevice->SetTexture(0, NULL);
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);//ライティングしたい
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);

	pDevice->DrawPrimitiveUP(D3DPT_LINELIST, 44, g_grid_vertex, sizeof(GridVertex));
}
#include "light.h"

#include "direct3d.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
//#define FVF_CUBE (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_NORMAL)//FVF定数定義


static LPDIRECT3DDEVICE9 pDevice = NULL;

void Light_Init(void)
{
	pDevice = GetDevice();
	D3DLIGHT9 light = {};
	light.Type = D3DLIGHT_DIRECTIONAL;
	D3DXVECTOR3 vecDirLight(-1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vecDirLight, &vecDirLight);
	light.Direction = vecDirLight;
	D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, &vecDirLight);
	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Diffuse.a = 1.0f;
	pDevice->SetLight(0, &light);//0→ライトのスロット番号、&light→ライトの設定情報*この関数で使用したらいらない
	pDevice->LightEnable(0, TRUE);//ライトのon/off
	pDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);//マテリアルは頂点カラーで
	pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);//拡大と縮小を見えるの為に
	//アンビエント
	pDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_RGBA(192, 96, 128,255));
	pDevice->SetRenderState(D3DRS_AMBIENTMATERIALSOURCE, D3DMCS_COLOR1);
	//色＝アンビエントマテリアル*アンビエントライト+ディレクションナルライト*ディフューズマテリアル
}
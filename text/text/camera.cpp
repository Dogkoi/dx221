#include "camera.h"
#include "direct3d.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"

static LPDIRECT3DDEVICE9 pDevice = NULL;

void Camera_Init(void)
{
	pDevice = GetDevice();

	//ビュー変換行列の設定
	D3DXMATRIX mtxView;                //ビュー変換行列-
	D3DXVECTOR3 eye(0.0f, 5.0f,-10.0f);//カメラ座標
	D3DXVECTOR3 at(0.0f, 0.0f, 0.0f);    //見る場所（注視点）プレイヤーカメラ座標
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);    //上方向ベクトル
	D3DXMatrixLookAtLH(&mtxView, &eye, &at, &up);//左系座標系を作る
	pDevice->SetTransform(D3DTS_VIEW, &mtxView);//ビュー変換行列をデバイスに送る

	//プロジェクション（パースペクティブ座標）変換行列
	D3DXMATRIX mtxProjection;                                               //プロジェクション変換行列
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(60), (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);
	//引数、画角（半分をラジアン角で指定）、アスペクト比（スクリーンの幅と高さの比例、near:near >0、far
	pDevice->SetTransform(D3DTS_PROJECTION, &mtxProjection);//プロジェクション変換行列をデバイスに送る
}

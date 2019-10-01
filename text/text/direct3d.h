#pragma once
#ifndef _DIRECT3D_H_
#define _DIRECT3D_H_
#include <d3d9.h>

bool Direct3d_Init(HWND hWnd);
void Direct3d_Uninit(void);
void Direct3d_Update(void);//一応要らない
void Direct3d_Draw(void);//一応要らない

LPDIRECT3DDEVICE9 GetDevice(void);

#endif // DIRECT3D_H_


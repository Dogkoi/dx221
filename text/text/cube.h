#pragma once
#ifndef _CUBE_H_
#define _CUBE_H_
#include "direct3d.h"
#include <d3d9.h>
#include <d3dx9.h>

void Cube_Init(void);                      //初期化
void Cube_Uninit(void);                    //終了処理
void Cube_Draw(void);                     //描画
void Cube_Update(void);                   //更新



#endif // !_CUBE_H_


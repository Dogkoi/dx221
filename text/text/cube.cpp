#include "cube.h"
#include "common.h"
#define FVF_CUBE (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_NORMAL|D3DFVF_TEX1)//FVF�萔��`
#include "texture.h"
#include "sprite.h"

//���_�\���̐錾
typedef struct CubeVertex_tag
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 normal;//�@��
	D3DCOLOR color;
	D3DXVECTOR2 UV;
}CubeVertex;

//���_�f�[�^�̗p��
//�O���[�o���ϐ�
static const CubeVertex g_cube_vertices[] = {
	//�O�@��
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.0f)},
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f)},
	{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f)},
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f)},
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f)},
	{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f)},

	//���@��
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f)},
	{D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f)},
	{D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f)},
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f)},
	{D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f)},
	{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f)},

	//�� ��
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f)},
	{D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f)},
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.25f)},
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.25f)},
	{D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f)},
	{D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f)},

	//���@���F
	{D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(1.0f,0.25f)},
	{D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f)},
	{D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(1.0f,0.0f)},
	{D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(1.0f,0.25f)},
	{D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.72f,0.25f)},
	{D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f)},

	//�E ��
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.5f)},
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f)},
	{D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f)},
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.5f)},
	{D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f)},
	{D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.5f)},

	//�� �I�����W
	{D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.5f)},
	{D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f)},
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f)},
	{D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.5f)},
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f)},
	{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.5f)},
};


static LPDIRECT3DDEVICE9 pDevice = NULL;
static float angle = 0.0f;//r
static float speedx = 0.0f;
static float speedz = 0.0f;

static float scaling = 0.0f;
static float s = 0.0f;

static int flag = 3;
static int scaleflag = 1;
static int num = 1;
static float speed_k[5];
static float Maxs[5];

int tex;

void Cube_Init(void)
{
	pDevice = GetDevice();

	for (int i = 0; i < 5; i++)
	{
		speed_k[i] = 0.0f;
		Maxs[i] = i - 10.0f;
	}

	tex = Texture_SetLoadFile("Accet\\Texture\\spice_and_wolf.png", 1024, 1024);
	Texture_Load();
}

void Cube_Uninit(void)
{
	
}

void Cube_Draw(void)
{
	//���[���h�ϊ��s��̐ݒ�
	//����
	D3DXMATRIX mtxWorld, mtxRotation, mtxTranslation;
	D3DXMatrixTranslation(&mtxTranslation, 4.5f + speedx, 0.5f, -4.5f + speedz); //�s��͍����ł���
	mtxWorld = mtxTranslation;
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);


	//�`��
	pDevice->SetFVF(FVF_CUBE);
	pDevice->SetTexture(0, Texture_GetTexture(tex));
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);//���C�e�B���O������
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, g_cube_vertices, sizeof(CubeVertex));

	//���]
	D3DXMatrixTranslation(&mtxTranslation, -4.5f, 0.5f, -4.5f); //�s��͍����ł���
	D3DXMatrixRotationY(&mtxRotation, angle);
	//mtxWorld = mtxTranslation * mtxRotation;
	mtxWorld = mtxRotation * mtxTranslation;
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, g_cube_vertices, sizeof(CubeVertex));

	//�g��Ək��
	D3DXMATRIX mtxScaling;
	D3DXMatrixTranslation(&mtxTranslation, 4.5f + s, 0.5f - s, 4.5f + s);
	D3DXMatrixScaling(&mtxScaling, 1.0f + scaling, 1.0f+scaling, 1.0f + scaling);
	mtxWorld = mtxScaling * mtxTranslation;
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, g_cube_vertices, sizeof(CubeVertex));

	
	for (int i = 0; i < num; i++)
	{
		D3DXMatrixTranslation(&mtxTranslation, -4.5f, 10.5f + speed_k[i], 4.5f);//���s�ړ��s��̑��
		mtxWorld = mtxTranslation;//DX�̍s�񍇐��͐����ɂ���΂悢
		pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);//���[���h�ϊ��s����f�o�C�X�ɓo�^����
		pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, g_cube_vertices, sizeof(CubeVertex));
	}

}

void Cube_Update(void)
{
	angle += 0.05f;

	if (flag == 1)
	{
		speedx -= 0.1f;
	}
	if (flag == 2)
	{
		speedz += 0.1f;
	}
	if (flag == 3)
	{
		speedx += 0.1f;
	}
	if (flag == 4)
	{
		speedz -= 0.1f;
	}
	
	//�E��������
	if (speedx > 0.0f)
	{
		speedx = 0.0f;
		flag = 4;
	}
	//����������
	if (speedx < -9.0f)
	{
		speedx = -9.0f;
		flag = 2;
	}
	//���と�E��
	if (speedz > 9.0f)
	{
		speedz = 9.0f;
		flag = 3;
	}
	//�E�と�E��
	if (speedz < 0.0f)
	{
		speedz = 0.0f;
		flag = 1;
	}
	

	s = -scaling / 2;
	if (scaleflag == 1)
	{
		scaling += 0.01f;
	}
	if (scaleflag == 2)
	{
		scaling -= 0.01f;
	}
	if (scaling > 2.0f)
	{
		scaling = 2.0f;
		scaleflag = 2;

	}
	if (scaling < 0.0f)
	{
		scaling = 0.0f;
		scaleflag = 1;
	}

	speed_k[num - 1] -= 0.1f;
	if (speed_k[num - 1] < Maxs[num - 1])
	{
		speed_k[num - 1] = Maxs[num - 1];
		num++;
		if (num > 5)
		{
			num = 1;
			for (int i = 0; i < 5; i++)
			{
				speed_k[i] = 0.0f;
			}
		}
	}
}
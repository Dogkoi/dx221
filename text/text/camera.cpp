#include "camera.h"
#include "direct3d.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"

static LPDIRECT3DDEVICE9 pDevice = NULL;

void Camera_Init(void)
{
	pDevice = GetDevice();

	//�r���[�ϊ��s��̐ݒ�
	D3DXMATRIX mtxView;                //�r���[�ϊ��s��-
	D3DXVECTOR3 eye(0.0f, 5.0f,-10.0f);//�J�������W
	D3DXVECTOR3 at(0.0f, 0.0f, 0.0f);    //����ꏊ�i�����_�j�v���C���[�J�������W
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);    //������x�N�g��
	D3DXMatrixLookAtLH(&mtxView, &eye, &at, &up);//���n���W�n�����
	pDevice->SetTransform(D3DTS_VIEW, &mtxView);//�r���[�ϊ��s����f�o�C�X�ɑ���

	//�v���W�F�N�V�����i�p�[�X�y�N�e�B�u���W�j�ϊ��s��
	D3DXMATRIX mtxProjection;                                               //�v���W�F�N�V�����ϊ��s��
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(60), (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);
	//�����A��p�i���������W�A���p�Ŏw��j�A�A�X�y�N�g��i�X�N���[���̕��ƍ����̔��Anear:near >0�Afar
	pDevice->SetTransform(D3DTS_PROJECTION, &mtxProjection);//�v���W�F�N�V�����ϊ��s����f�o�C�X�ɑ���
}

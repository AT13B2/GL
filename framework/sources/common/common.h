//*****************************************************************************
//
// ���ʏ���
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// ��d��`�h�~
//*****************************************************************************
#pragma once

#ifndef _COMMON_H_
#define _COMMON_H_

//*****************************************************************************
// warning����
//*****************************************************************************
#pragma warning (disable : 4005)

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "basic/application.h"
#include "debug_tool/debug.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// ���S�Ƀf���[�g�������s��
#define SAFE_DELETE(p) if(p != NULL){delete p; p = NULL;}

// �z������S�Ƀf���[�g�������s��
#define SAFE_DELETE_ARRAY(p) if(p != NULL){delete[] p; p = NULL;}

// ���S�Ƀ����[�X�������s��
#define SAFE_RELEASE(p) if(p != NULL){p->Release();p = NULL;}

// ������
#define INIT(p)		if(p != NULL){if(!p->Init()){return false;}}

//*****************************************************************************
// �萔��`
//*****************************************************************************
const static int DEFAULT_FAIL = (-1);					// ���s������
const static int DEFAULT_SCREEN_WIDTH	= (1280);		// �X�N���[������
const static int DEFAULT_SCREEN_HEIGHT	= (720);		// �X�N���[���c��

//*****************************************************************************
// �\���̒�`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

#endif	// _COMMON_H_

//---------------------------------- EOF --------------------------------------
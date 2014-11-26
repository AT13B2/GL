//*****************************************************************************
//
// ���f���N���X
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <stdio.h>

// graphic
#include "interface/graphic/model/model.h"
#include "interface/graphic/device/device_holder.h"

// common
#include "common/common.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************

//=============================================================================
// �f�t�H���g�R���X�g���N�^
//=============================================================================
CModel::CModel(CDeviceHolder* device_holder)
{
	filename_ = NULL;

	// �O���t�B�b�N�f�o�C�X�̐ݒ�
	device_holder_ = device_holder;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CModel::~CModel(void)
{
}

//=============================================================================
// ���[�h����
//=============================================================================
bool CModel::Init(void)
{
	filename_ = NULL;

	return true;
}

//=============================================================================
// �I������
//=============================================================================
void CModel::Uninit(void)
{
	// �t�@�C�����̔j��
	SAFE_DELETE_ARRAY(filename_);
}

//=============================================================================
// �t�@�C�����̐ݒ菈��
//=============================================================================
void CModel::SetFilename(const s8* filename)
{
	int nLen = 0;

	// �t�@�C�����̒����̎擾
	nLen = strlen(filename);

	// �t�@�C�������m��
	filename_ = new char[nLen + 1];

	// �t�@�C�����̃R�s�[
	strcpy(filename_,filename);
}

//---------------------------------- EOF --------------------------------------
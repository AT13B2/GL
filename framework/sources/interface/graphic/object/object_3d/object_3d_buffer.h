//*****************************************************************************
//
// �I�u�W�F�N�g3D�o�b�t�@�N���X
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// ���d��`�h�~
//*****************************************************************************
#pragma once

#ifndef _OBJECT_3D_BUFFER_H_
#define _OBJECT_3D_BUFFER_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
// stl
#include <list>

// basic
#include "basic/basic.h"

//*****************************************************************************
// ���C�u�����̃����N
//*****************************************************************************

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �\���̒�`
//*****************************************************************************

//*****************************************************************************
// �N���X�̑O���Q��
//*****************************************************************************
class CObject3DData;
class CCamera;
class CModelManager;
class CTextureManager;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CObject3DBuffer : public CBasic
{
public:
	// �R���X�g���N�^
	CObject3DBuffer(void);

	// �f�X�g���N�^
	~CObject3DBuffer(void);

	// ������
	bool Init(void);

	// �`��
	void Draw(CCamera* camera,CTextureManager* texture_manager,CModelManager* model_manager);

	// �I��
	void Uninit(void);

	// �ǉ�
	void AddList(CObject3DData* pObjectData);

	// ���t���b�V��
	void Refresh(void);

private:
	// �o�b�t�@���X�g
	std::list<CObject3DData*> object_3d_data_list_;
};

#endif	// _OBJECT_3D_BUFFER_H_

//---------------------------------- EOF --------------------------------------
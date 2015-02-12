//*****************************************************************************
//
// �^�C�g���N���X
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// ���d��`�h�~
//*****************************************************************************
#pragma once

#ifndef _SCENE_RESULT_H_
#define _SCENE_RESULT_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "scene/scene.h"
#include "common/math/vector/vector2.h"

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
// �N���X�̑O���錾
//*****************************************************************************
class CSound;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CSceneResult : public CScene
{
public:
	// �R���X�g���N�^
	CSceneResult(CInterfaceManager* interface_manager);

	// �f�X�g���N�^
	virtual ~CSceneResult(void);

	// ������
	bool Init(void);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// �I��
	void Uninit(void);

	// ���[�h
	void Load(void);

	// �����̃t�@�N�g���[�̍쐬
	CSceneFactory* MakeFactory(void);
	
	static void SetResultFlag(bool fResult);

protected:

private:

	typedef enum TEXTURE_TYPE_
	{
		TEXTURE_TYPE_WIN,
		TEXTURE_TYPE_LOSE,
		TEXTURE_TYPE_PRESSENTER,
		TEXTURE_TYPE_MAX,
	}TEXTURE_TYPE;

	static const char* p_texture_names[TEXTURE_TYPE_MAX];

	static const VECTOR2 LOGO_DEFAULT_POS;
	static const VECTOR2 PRESSKEY_DEFAULT_POS;
	u32 test_object_key_;

	u32 logo_key_;						 //���S�\���ɕK�v
	u32 press_key_;						 //��ʉ��{�^�����͂܂��\���ɕK�v
	u32 model_key_;						 //model�\���ɕK�v

	static bool m_bResult;
};

#endif	// _SCENE_TITLE_H_

//---------------------------------- EOF --------------------------------------
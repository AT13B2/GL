//*****************************************************************************
//
// �o���b�g�}�l�[�W���[�N���X [bullet_manager.h]
//
// Author		: ooigawa Kazuma
//
//*****************************************************************************

//*****************************************************************************
// ��d��`�h�~
//*****************************************************************************
#pragma once

#ifndef _EXPLOSION_MANAGER_H_
#define _EXPLOSION_MANAGER_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
// character_manager
#include "explosion.h"
#include "interface/character/character_manager_interface.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �萔��`
//*****************************************************************************

//*****************************************************************************
// �\���̒�`
//*****************************************************************************

//*****************************************************************************
// �N���X�̑O���Q��
//*****************************************************************************
class CExplosion;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CExplosionManager : public CCharacterManagerInterface<CExplosion*>
{
public:
	//�R���X�g���N�^
	CExplosionManager();

	//�f�X�g���N�^
	~CExplosionManager();

	// ����������
	bool Init(void);
private:

};
#endif //_EXPLOSION_MANAGER_H_
//---------------------------------- EOF --------------------------------------
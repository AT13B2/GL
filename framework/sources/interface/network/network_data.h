//*****************************************************************************
//
// �l�b�g���[�N�f�[�^�N���X [network_data.h]
//
// Author		: KENJI KABUTOMORI
// Date			: 2014/09/17(Wed)
// Version		: 1.00
// Update Date	: 2014/09/17(Wed)
//
//*****************************************************************************

//*****************************************************************************
// ���d��`�h�~
//*****************************************************************************
#pragma once

#ifndef _NETWORK_DATA_H_
#define _NETWORK_DATA_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "basic.h"

//*****************************************************************************
// ���C�u�����̃����N
//*****************************************************************************

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
struct NETWORK_DATA_EVENT
{
	short Type;
};


struct NETWORK_DATA_POSITION
{
	float x, y, z;
};


struct NETWORK_DATA_ROTATION
{
	float x, y, z;
};

enum NETWORK_DATA_TYPE
{
	NETWORK_DATA_TYPE_EVENT    = 1,
	NETWORK_DATA_TYPE_POSITION = 2,
	NETWORK_DATA_TYPE_ROTATION = 3,
	NETWORK_DATA_TYPE_END      = 4,
};

struct NETWORK_DATA
{
	int		ID;
	int		Type;

	union
	{
		NETWORK_DATA_EVENT		Event;
		NETWORK_DATA_POSITION	Position;
		NETWORK_DATA_ROTATION	Rotation;
	};
};

#endif	// _NETWORK_DATA_H_

//---------------------------------- EOF --------------------------------------
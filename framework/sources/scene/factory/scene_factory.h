//*****************************************************************************
//
// �V�[���t�@�N�g���[�N���X
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// ���d��`�h�~
//*****************************************************************************
#pragma once

#ifndef _SCENE_FACTORY_H_
#define _SCENE_FACTORY_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "scene/scene.h"
#include "scene/title/scene_title.h"
#include "scene/game/scene_game.h"
#include "scene/load/scene_load.h"

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
class CInterfaceManager;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CSceneFactory
{
public:
	// �R���X�g���N�^
	CSceneFactory(CScene::TYPE scene_type){scene_type_ = scene_type;}

	// �f�X�g���N�^
	virtual ~CSceneFactory(void){}

	virtual CScene* Make(CInterfaceManager* interface_manager) = 0;

	CScene::TYPE scene_type(void){return scene_type_;}
protected:

private:
	CScene::TYPE scene_type_;
};

class CTitleFactory : public CSceneFactory
{
public:

	// �R���X�g���N�^
	CTitleFactory(void) : CSceneFactory(CScene::TYPE_TITLE){}

	// �f�X�g���N�^
	virtual ~CTitleFactory(void){}

	CScene* Make(CInterfaceManager* interface_manager){return new CSceneTitle(interface_manager);}
protected:

private:
};

class CGameFactory : public CSceneFactory
{
public:

	// �R���X�g���N�^
	CGameFactory(void) : CSceneFactory(CScene::TYPE_GAME){}

	// �f�X�g���N�^
	virtual ~CGameFactory(void){}

	CScene* Make(CInterfaceManager* interface_manager){return new CSceneGame(interface_manager);}

protected:

private:
};

class CLoadFactory : public CSceneFactory
{
public:

	// �R���X�g���N�^
	CLoadFactory(void) : CSceneFactory(CScene::TYPE_LOAD){}

	// �f�X�g���N�^
	virtual ~CLoadFactory(void){}

	CScene* Make(CInterfaceManager* interface_manager){return new CSceneLoad(interface_manager);}

protected:

private:
};

#endif	// _SCENE_FACTORY_H_

//---------------------------------- EOF --------------------------------------
//*****************************************************************************
//
// キャラクターマネージャーインターフェースクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _CHARACTER_MANAGER_INTERFACE_H_
#define _CHARACTER_MANAGER_INTERFACE_H_

//*****************************************************************************
// warning消し
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <windows.h>
#include <string>
#include <map>

// basic
#include "basic/basic.h"

//*****************************************************************************
// ライブラリのリンク
//*****************************************************************************

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// 構造体定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// クラスの前方参照
//*****************************************************************************
class CInterfaceManager;

//*****************************************************************************
// クラス定義
//*****************************************************************************
template <class T> class CCharacterManagerInterface : public CBasic
{
public:
	// コンストラクタ
	CCharacterManagerInterface(CInterfaceManager* interface_manager);

	// デストラクタ
	virtual ~CCharacterManagerInterface(void);

	// 初期化処理
	virtual bool Init(void) = 0;

	// 更新処理
	virtual void Update(void);

	// 終了処理
	virtual void Uninit(void);

protected:
	std::list<T> character_list_;
	CInterfaceManager* interface_manager_;

private:

};

//=============================================================================
// コンストラクタ
//=============================================================================
template <class T> CCharacterManagerInterface::CCharacterManagerInterface(CInterfaceManager* interface_manager)
{
	interface_manager_ = interface_manager;
}

//=============================================================================
// デストラクタ
//=============================================================================
template <class T> CCharacterManagerInterface::~CCharacterManagerInterface(void)
{
}

//=============================================================================
// 更新処理
//=============================================================================
template <class T> void CCharacterManagerInterface<T>::Update(void)
{
	for(auto it = character_list_.begin();it != character_list_.end();++it)
	{
		(*it)->Update();
	}
}

//=============================================================================
// 終了処理
//=============================================================================
template <class T> void CCharacterManagerInterface<T>::Uninit(void)
{
	for(auto it = character_list_.begin();it != character_list_.end();++it)
	{
		(*it)->Uninit();
	}

	character_list_.clear();
}

#endif	// _CHARACTER_MANAGER_INTERFACE_H_

//---------------------------------- EOF --------------------------------------

//*****************************************************************************
//
// プレイヤーマネージャークラス
//
// Author		: Chiharu Kamiyama
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _PLAYER_MANAGER_H_
#define _PLAYER_MANAGER_H_

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

//character_manager
#include "interface/character/character_manager_interface.h"
#include "player.h"

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
class CPlayer;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CPlayerManager : public CCharacterManagerInterface<CPlayer*>
{
public:
	// コンストラクタ
	CPlayerManager();

	// デストラクタ
	~CPlayerManager(void);

	// 初期化処理
	bool Init(void);

	// 終了処理
	void Uninit(void);

	void set_player( CPlayer *player ){ player_ = player; }

protected:


private:
	CPlayer* player_;
};

//---------------------------------- EOF --------------------------------------


#endif
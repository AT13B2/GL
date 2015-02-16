//*****************************************************************************
//
// プレイヤーマネージャークラス
//
// Author		: Chiharu Kamiyama
//
//*****************************************************************************


//*****************************************************************************
// インクルード
//*****************************************************************************
#include "player_manager.h"
#include "player.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayerManager::CPlayerManager(void)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayerManager::~CPlayerManager(void)
{
}

//=============================================================================
// 初期化
//=============================================================================
bool CPlayerManager::Init(void)
{
	return true;
}

//=============================================================================
// 終了処理
//=============================================================================
void  CPlayerManager::Uninit(void)
{
	CCharacterManagerInterface::Uninit();
}

//---------------------------------- EOF --------------------------------------

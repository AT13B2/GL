//*****************************************************************************
//
// テクスチャクラス [texture.cpp]
//
// Author		: KENJI KABUTOMORI
// Date			: 2014/06/10(Tue)
// Version		: 1.00
// Update Date	: 2014/06/10(Tue)
//
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "application.h"

#ifdef _USING_XAUDIO2_
#include "xaudio2_sound.h"
#endif

#include "sound.h"
#include <stdio.h>

#include "common.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************

//=============================================================================
// デフォルトコンストラクタ
//=============================================================================
CSound::CSound(void)
{
	// ファイル名
	m_pFilename = NULL;
}

//=============================================================================
// デストラクタ
//=============================================================================
CSound::~CSound(void)
{
}

//=============================================================================
// ロード処理
//=============================================================================
bool CSound::Init(void)
{
	m_pFilename = NULL;

	return true;
}

//=============================================================================
// 終了処理
//=============================================================================
void CSound::Uninit(void)
{
	SAFE_DELETE_ARRAY(m_pFilename);
}

//=============================================================================
// 作成処理
//=============================================================================
CSound* CSound::Create(CSoundDevice* pSoundDevice)
{
	CSound* pSound = NULL;

#ifdef _USING_XAUDIO2_
	pSound = new CXAudio2Sound(pSoundDevice);
#endif
	return pSound;
}

//=============================================================================
// ファイル名の設定処理
//=============================================================================
void CSound::SetFilename(const char* pFilename)
{
	int nLen = 0;

	// ファイル名の長さの取得
	nLen = strlen(pFilename);

	// ファイル名分確保
	m_pFilename = new char[nLen + 1];

	// ファイル名のコピー
	strcpy(m_pFilename,pFilename);
}

//---------------------------------- EOF --------------------------------------

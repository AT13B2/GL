//*****************************************************************************
//
// サウンドマネージャークラス [sound_manager.h]
//
// Author		: KENJI KABUTOMORI
// Date			: 2014/06/10(Tue)
// Version		: 1.00
// Update Date	: 2014/06/10(Tue)
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "common/file/file_manager.h"

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
class CSound;
class CSoundDevice;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CSoundManager : public CFileManager<CSound*>
{
public:
	// コンストラクタ
	CSoundManager(void);

	// デストラクタ
	~CSoundManager(void);

	// 初期化
	bool Init();

	// 終了
	void Uninit(void);

private:
	// サウンドデバイス
	CSoundDevice* m_pSoundDevice;

	// データの作成
	CSound* Create(const char* pFilename);

	// データの開放
	void ReleaseData(CSound* pSound);
};

#endif	// _SOUND_MANAGER_H_

//---------------------------------- EOF --------------------------------------

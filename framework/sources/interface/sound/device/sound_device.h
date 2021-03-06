//*****************************************************************************
//
// サウンドデバイスクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _SOUND_DEVICE_H_
#define _SOUND_DEVICE_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
// basic
#include "basic/application.h"
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
// クラスの前方参照
//*****************************************************************************
#ifdef _USING_XAUDIO2_
class CXAudio2;
#endif

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CSoundDevice : public CBasic
{
public:
	// コンストラクタ
	CSoundDevice(void);

	// デストラクタ
	virtual ~CSoundDevice(void);

	// 初期化処理
	bool Init(void);

	// 終了処理
	void Uninit(void);

#ifdef _USING_XAUDIO2_
	CXAudio2* device(void){return device_;}
#endif

private:

#ifdef _USING_XAUDIO2_
	CXAudio2* device_;
#endif
};

#endif // _GRAPHICS_API_H_

//---------------------------------- EOF --------------------------------------

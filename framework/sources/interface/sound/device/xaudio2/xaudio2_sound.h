//*****************************************************************************
//
// XAudio2サウンド処理 [xaudio2_sound.h]
//
// Author		: KENJI KABUTOMORI
// Date			: 2014/03/28(Fri)
// Version		: 1.00
// Update Date	: 2014/09/11(Thu)
//
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _XAUDIO2_SOUND_H_
#define _XAUDIO2_SOUND_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "sound.h"
#include <xaudio2.h>

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// クラスの前方参照
//*****************************************************************************
class CSoundDevice;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CXAudio2Sound : public CSound
{
public:
	// コンストラクタ
	CXAudio2Sound(CSoundDevice* pSoundDevice);

	// デストラクタ
	virtual ~CXAudio2Sound(void);

	// 初期化
	bool Init(void);

	// 終了
	void Uninit(void);

	// ロード
	bool Load(const char* pFilename);

	// 再生
	void Play(bool bLoopFlag);

	// 停止
	void Stop(void);

	// 一時停止
	void Pause(void);

	// 状態の取得
	bool GetStatus(void){return m_bPlayFlag;}
	// ボリュームの設定
	//void SetVolume();

protected:

private:
	// サウンドデバイス
	CSoundDevice* m_pSoundDevice;

	// プレイフラグ
	bool m_bPlayFlag;

	int m_nSoundId;											// サウンドID
	IXAudio2SourceVoice* m_pSourceVoice;					// ソースボイス
	BYTE* m_pDataAudio;										// オーディオデータ
	DWORD m_SizeAudio;										// オーディオデータサイズ
};

#endif // _XAUDIO2_SOUND_H_

//---------------------------------- EOF --------------------------------------

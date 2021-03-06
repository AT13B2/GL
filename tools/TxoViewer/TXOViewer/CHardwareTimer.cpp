//=============================================================================
//
// ハードウェアタイマークラス [CHardwareTimer.h]
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//
//=============================================================================

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "CHardwareTimer.h"

//*****************************************************************************
// 静的メンバ変数初期化
//*****************************************************************************
// タイマースタートフラグ
bool	CHardwareTimer::m_bTimerStarted = false;
// タイマーエンドフラグ
bool	CHardwareTimer::m_bTimerEnded = false;

//=============================================================================
// コンストラクタ
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//=============================================================================
CHardwareTimer::CHardwareTimer() :
m_uStart(0),
m_uEnd(0),
m_fFPS(0)
{
}

//=============================================================================
// デストラクタ
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//=============================================================================
CHardwareTimer::~CHardwareTimer()
{
}

//=============================================================================
// タイマーセットアップ
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//=============================================================================
void CHardwareTimer::SetupTimer(void)
{
	if(!m_bTimerStarted)
	{
		timeBeginPeriod(1);
		m_bTimerStarted = true;
	}
}

//=============================================================================
// タイマーエンド
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//=============================================================================
void CHardwareTimer::EndTimer(void)
{
	if(!m_bTimerEnded)
	{
		timeEndPeriod(1);
		m_bTimerEnded = true;
	}
}

//=============================================================================
// 初期化
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//=============================================================================
void CHardwareTimer::Init(void)
{
	m_uStart = m_uEnd = timeGetTime();
	m_fFPS = 0.0f;
}

//=============================================================================
// 更新
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//=============================================================================
bool CHardwareTimer::Update(void)
{
	m_uEnd = timeGetTime();

	if((m_uEnd - m_uStart) >= 1000.f / 60.f)
	{
		// FPS設定
		m_fFPS = 1000.f / (m_uEnd - m_uStart);
		// 開始時間を設定
		m_uStart = m_uEnd;

		// タイマー経過
		return true;
	}

	// タイマー経過してない
	return false;
}

//=============================================================================
// FPS取得
// Author : Ryo Kobayashi
// LastUpdate : 2014/9/30
//=============================================================================
float CHardwareTimer::GetFPS(void)
{
	return m_fFPS;
}

// EOF
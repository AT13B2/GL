//*****************************************************************************
//
// FPS管理処理
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "fps_manager.h"
#include <windows.h>

//*****************************************************************************
// ライブラリのリンク
//*****************************************************************************
#pragma comment (lib, "winmm.lib")			// timerの使用

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
// コンストラクタ
//=============================================================================
CFpsManager::CFpsManager(void)
{
	fps_ = 0;
	current_time_ = 0;
	fps_last_time_ = 0;
	frame_count_ = 0;
	last_time_ = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CFpsManager::~CFpsManager(void)
{
}

//=============================================================================
// 初期化
//=============================================================================
bool CFpsManager::Init(void)
{
	// 分解能を設定
	timeBeginPeriod(1);

	last_time_ = timeGetTime();
	fps_last_time_ = last_time_;

	return true;
}

//=============================================================================
// 更新
//=============================================================================
void CFpsManager::Update(void)
{
	// 0.5秒ごとに実行
	if((current_time_ - fps_last_time_) >= 500)
	{
		// FPSの計測
		fps_ = frame_count_ * 1000 / (current_time_ - fps_last_time_);
		fps_last_time_ = current_time_;
		frame_count_ = 0;
	}
}

//=============================================================================
// 終了
//=============================================================================
void CFpsManager::Uninit(void)
{
	// 分解能を戻す
	timeEndPeriod(1);
}

//=============================================================================
// FPSの確認
//=============================================================================
bool CFpsManager::CheckFps(void)
{
	// 時間の取得
	current_time_ = timeGetTime();

	// 60フレーム経過していたら
	if((current_time_ - last_time_) >= (1000.0f / 60.0f))
	{
		last_time_ = current_time_;
		frame_count_++;
		return true;
	}

	return false;
}

//-----------------------------------EOF---------------------------------------

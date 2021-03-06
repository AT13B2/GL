//*****************************************************************************
//
// FPS管理処理
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _FPS_MANAGER_H_
#define _FPS_MANAGER_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "basic/basic.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CFpsManager : public CBasic
{
public:
	// コンストラクタ
	CFpsManager(void);

	// デストラクタ
	~CFpsManager(void);

	// 初期化
	bool Init(void);

	// 更新
	void Update(void);

	// 終了
	void Uninit(void);

	// FPSの確認
	bool CheckFps(void);

private:
	u32 current_time_;
	u32 last_time_;
	u32 fps_last_time_;
	u32 frame_count_;
	u32 fps_;
};

#endif // _FPS_MANAGER_H_

//-----------------------------------EOF---------------------------------------

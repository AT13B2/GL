//*****************************************************************************
//
// スレッドクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _THREAD_H_
#define _THREAD_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "basic/basic.h"
#include <windows.h>

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CThread : public CBasic
{
public:
	// コンストラクタ
	CThread(void);

	// デストラクタ
	~CThread(void);

	// 初期化処理
	bool Init(void);

	// 終了処理
	void Uninit(void);

	// 開始処理
	bool Start(void* func,void* arg);

	// 停止処理
	void Stop(void);

	// 終了確認処理
	bool CheckEnd(void);

protected:

private:
	// スレッドハンドル
	HANDLE m_hThread;
};

#endif // _THREAD_H_

//---------------------------------- EOF --------------------------------------

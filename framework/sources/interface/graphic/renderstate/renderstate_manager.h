//*****************************************************************************
//
// レンダーステートマネージャークラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _RENDERSTATE_MANAGER_H_
#define _RENDERSTATE_MANAGER_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <windows.h>

// basic
#include "basic/basic.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// 定数定義
//*****************************************************************************

//*****************************************************************************
// 構造体定義
//*****************************************************************************

//*****************************************************************************
// クラスの前方参照
//*****************************************************************************
class CDeviceHolder;
class CRenderstate;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CRenderstateManager : public CBasic
{
public:
	enum TYPE
	{
		TYPE_ALL = 0,		// 全体に掛ける
		TYPE_2D,			// 2D全体に掛ける
		TYPE_3D,			// 3D全体に掛ける
		TYPE_LIGHT_OFF,		// ライトのオフ
		TYPE_WIREFRAME,		// ワイヤーフレーム
		TYPE_MAX			// タイプの最大数
	};

	// コンストラクタ
	CRenderstateManager(CDeviceHolder* device_holder);

	// デストラクタ
	~CRenderstateManager(void);

	// 初期化
	bool Init(void);

	// 終了
	void Uninit(void);

	// レンダーステートの取得
	CRenderstate* renderstate(const TYPE& type);
protected:

private:
	CDeviceHolder* device_holder_;
	CRenderstate* renderstate_[TYPE_MAX];
};

#endif // _INTERFACE_MANAGER_H_

//---------------------------------- EOF --------------------------------------

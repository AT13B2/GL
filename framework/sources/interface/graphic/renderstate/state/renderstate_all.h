//*****************************************************************************
//
// レンダーステートクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _RENDERSTATE_ALL_H_
#define _RENDERSTATE_ALL_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "renderstate.h"

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
class CGraphicsDevice;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CRenderstateAll : public CRenderstate
{
public:
	// コンストラクタ
	CRenderstateAll(CDeviceHolder* device_holder);

	// デストラクタ
	virtual ~CRenderstateAll(void);

	virtual bool Init(void) = 0;

	virtual void Uninit(void) = 0;

	virtual void Set(void) = 0;

	virtual void Unset(void) = 0;

	// 作成処理
	static CRenderstateAll* Create(CDeviceHolder* device_holder);

private:
};

#endif // _RENDERSTATE_H_

//---------------------------------- EOF --------------------------------------

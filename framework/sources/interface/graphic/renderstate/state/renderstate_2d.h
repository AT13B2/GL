//*****************************************************************************
//
// レンダーステート2Dクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _RENDERSTATE_2D_H_
#define _RENDERSTATE_2D_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
// graphic
#include "interface/graphic/renderstate/state/renderstate.h"

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
class CDeviceHolder;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CRenderstate2D : public CRenderstate
{
public:
	// コンストラクタ
	CRenderstate2D(CDeviceHolder* device_holder);

	// デストラクタ
	virtual ~CRenderstate2D(void);

	virtual bool Init(void) = 0;

	virtual void Uninit(void) = 0;

	virtual void Set(void) = 0;

	virtual void Unset(void) = 0;

	// 作成処理
	static CRenderstate2D* Create(CDeviceHolder* device_holder);

private:
};

#endif // _RENDERSTATE_2D_H_

//---------------------------------- EOF --------------------------------------

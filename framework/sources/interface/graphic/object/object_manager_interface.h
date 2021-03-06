//*****************************************************************************
//
// オブジェクトマネージャーインターフェースクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _OBJECT_MANAGER_INTERFACE_H_
#define _OBJECT_MANAGER_INTERFACE_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <list>

// basic
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

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CObjectManagerInterface : public CBasic
{
public:
	// コンストラクタ
	CObjectManagerInterface(void);

	// デストラクタ
	virtual ~CObjectManagerInterface(void);

	// レンダーステートの設定
	void SetRenderstate(const u32& state_type){renderstate_list_.push_back(state_type);}

protected:
	std::list<u32> renderstate_list_;
};

#endif	// _OBJECT_MANAGER_INTERFACE_H_

//---------------------------------- EOF --------------------------------------

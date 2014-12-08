//*****************************************************************************
//
// キャラクターインターフェースクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _CHARACTER_INTERFACE_H_
#define _CHARACTER_INTERFACE_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
// basic
#include "basic/basic.h"

// math
#include "common/math/math.h"

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
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// クラスの前方参照
//*****************************************************************************
class CInterfaceManager;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CCharacterInterface : public CBasic
{
public:
	// コンストラクタ
	CCharacterInterface(void);

	// デストラクタ
	~CCharacterInterface(void);

	// 前方ベクトルの設定
	void set_front_vector(const VECTOR3& front_vector){front_vector_ = front_vector;}
protected:
	VECTOR3 front_vector_;
};

#endif // _CHARACTER_INTERFACE_H_

//---------------------------------- EOF --------------------------------------

//*****************************************************************************
//
// フィールドクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************


//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _FIELD_H_
#define _FIELD_H_

//*****************************************************************************
// warning消し
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
// basic
#include "basic/basic.h"
#include "common/math/vector/vector3.h"

// character
#include "field_manager.h"
#include "interface/character/character_interface.h"

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
class CMeshfield;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CField : public CCharacterInterface
{
public:
	// コンストラクタ
	CField(CInterfaceManager* interface_manager);

	// デストラクタ
	~CField(void);

	// 初期化処理
	bool Init(void);

	// 更新処理
	void Update(void);

	// 終了処理
	void Uninit(void);

	//描画
	void Draw(void);

	// 高さ取得
	f32 get_height(const VECTOR3& in_position, VECTOR3* p_out_normal);

protected:
	

private:
	//インターフェースマネージャー
	CInterfaceManager* interface_manager_;

	//オブジェクトキー
	u32 object_key_;

	CMeshfield* meshfield_;
};

//---------------------------------- EOF --------------------------------------

#endif // _FIELD_H_
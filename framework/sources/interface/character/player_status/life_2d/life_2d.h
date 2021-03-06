//*****************************************************************************
//
// ライフ(2D)クラス
//
// Author		: Kazuma Ooigawa
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _LIFE_2D_H_
#define _LIFE_2D_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "common/math/math.h"
#include "../../character_interface.h"

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
class CInterfaceManager;
class CRectangle2D;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CLife2D : public CCharacterInterface
{
public:
	// コンストラクタ
	CLife2D(CInterfaceManager* interface_manager , s32 max_life , s32 max_length , int player_id );

	// デストラクタ
	~CLife2D(void);

	// 初期化
	bool Init(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 終了
	void Uninit(void);

	//位置取得
	VECTOR2 position( void ){ return position_; }

	//ライフ取得
	s32 life( void ){ return life_;}

	//位置セット
	void set_position( const VECTOR2& pos ){ position_ = pos ;}

	//ライフセット
	void set_life( const s32 life ){ life_ = life;}

	//ライフ増減
	void add_life( const s32 vol ){ life_ += vol ; }
	//消去
	void Erase( void );
private:
	u32 object_key_;
	VECTOR2 position_;
	u32 max_life_;
	s32 life_;
	u32 max_length_;
	s32 length_;
	int player_id_;
	CRectangle2D* rectangle_2d_;
	CInterfaceManager* interface_manager_;
};
#endif //_LIFE_2D_H_
//---------------------------------- EOF --------------------------------------

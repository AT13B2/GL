//*****************************************************************************
//
// バレットクラス
//
// Author		: Kazuma Ooigawa
//				: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _BULLET_H_
#define _BULLET_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "common/math/math.h"
#include "../character_interface.h"

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
class CBillboard;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CBullet : public CCharacterInterface
{
public:
	// コンストラクタ
	CBullet(CInterfaceManager* interface_manager);

	// デストラクタ
	~CBullet(void);

	// 初期化
	bool Init(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 終了
	void Uninit(void);

	// パラメータの設定
	void SetParameter(const VECTOR3& position,const VECTOR3& vector,const f32& speed , const s32& player_id );

	//位置取得
	VECTOR3 GetPosition( void ){ return position_; }

	//方向取得
	VECTOR3 GetVector( void ){ return vector_; }

	//位置セット
	void SetPosition( VECTOR3 _pos ){ position_ = _pos ;}

	//方向セット
	void SetVector( VECTOR3 _vec ){ vector_ = _vec ;}

private:
	static const f32 DEFAULT_RADIUS;
	u32 object_key_;
	VECTOR3 position_;
	VECTOR3 vector_;
	f32 speed_;
	f32 radius_;
	s32 player_id_;
	CInterfaceManager* interface_manager_;

};
#endif //_BULLET_H_
//---------------------------------- EOF --------------------------------------

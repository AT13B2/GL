//*****************************************************************************
//
// キャラクターカメラクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _PLAYER_CAMERA_H_
#define _PLAYER_CAMERA_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
// character
#include "character_camera.h"

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
class CPlayer;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CPlayerCamera : public CCharacterCamera
{
public:
	// コンストラクタ
	CPlayerCamera(CInterfaceManager* interface_manager,CPlayer* player);

	// デストラクタ
	virtual ~CPlayerCamera(void);

	// 初期化
	bool Init(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void){}

	// 終了
	void Uninit(void);
protected:

private:
	u32 camera_key_;
	f32 move_speed_;
	CPlayer* player_;
	f32 length_;
};

#endif	// _PLAYER_CAMERA_H_

//---------------------------------- EOF --------------------------------------

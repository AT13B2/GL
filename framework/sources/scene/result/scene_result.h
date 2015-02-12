//*****************************************************************************
//
// タイトルクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _SCENE_RESULT_H_
#define _SCENE_RESULT_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "scene/scene.h"
#include "common/math/vector/vector2.h"

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
// クラスの前方宣言
//*****************************************************************************
class CSound;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CSceneResult : public CScene
{
public:
	// コンストラクタ
	CSceneResult(CInterfaceManager* interface_manager);

	// デストラクタ
	virtual ~CSceneResult(void);

	// 初期化
	bool Init(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 終了
	void Uninit(void);

	// ロード
	void Load(void);

	// 自分のファクトリーの作成
	CSceneFactory* MakeFactory(void);
	
	static void SetResultFlag(bool fResult);

	void SetNonstaicResultFlag(bool fResult);

protected:

private:

	typedef enum TEXTURE_TYPE_
	{
		TEXTURE_TYPE_WIN,
		TEXTURE_TYPE_LOSE,
		TEXTURE_TYPE_PRESSENTER,
		TEXTURE_TYPE_MAX,
	}TEXTURE_TYPE;

	static const char* p_texture_names[TEXTURE_TYPE_MAX];

	static const VECTOR2 LOGO_DEFAULT_POS;
	static const VECTOR2 PRESSKEY_DEFAULT_POS;
	u32 test_object_key_;

	u32 logo_key_;						 //ロゴ表示に必要
	u32 press_key_;						 //画面下ボタン入力まち表示に必要
	u32 model_key_;						 //model表示に必要

	static bool m_bResult;

	bool m_bNonstaticResult;
};

#endif	// _SCENE_TITLE_H_

//---------------------------------- EOF --------------------------------------

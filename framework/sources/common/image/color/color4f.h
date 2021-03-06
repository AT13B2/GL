//*****************************************************************************
//
// カラークラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
/**
*	色情報の管理クラス\n
*	色情報を0.0fから1.0fで管理\n
*/
//*****************************************************************************

//*****************************************************************************
// 二重定義防止
//*****************************************************************************
#pragma once

#ifndef _COLOR4F_H_
#define _COLOR4F_H_

//*****************************************************************************
// インクルード
//*****************************************************************************

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// 定数定義
//*****************************************************************************

//*****************************************************************************
// 構造体定義
//*****************************************************************************
typedef struct COLOR4F
{
public:
	// 赤
	f32 _red;

	// 緑
	f32 _green;

	// 青
	f32 _blue;

	// 透明度
	f32 _alpha;

	//-----------------------------------------------------
	// コンストラクタ

	COLOR4F(void){_red = 0.0f;_green = 0.0f;_blue = 0.0f;_alpha = 0.0f;}
	COLOR4F(f32 red,f32 green,f32 blue,f32 alpha){_red = red;_green = green;_blue = blue;_alpha = alpha;}
	COLOR4F(const COLOR4F& color){_red = color._red;_green = color._green;_blue = color._blue;_alpha = color._alpha;}

}COLOR4F;

#endif // _COLOR4F_H_

//---------------------------------- EOF --------------------------------------

//*****************************************************************************
//
// オブジェクト2Dクラス [object_2d.cpp]
//
// Author		: KENJI KABUTOMORI
// Date			: 2014/04/21(Mon)
// Version		: 1.00
// Update Date	: 2014/05/14(Wed)
//
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
#ifdef _USING_OPENGL_
#include "opengl.h"
#endif

#ifdef _USING_DIRECTX_
#include "directx.h"
#endif


// basic
#include "basic/application.h"

// graphic
//#include "interface/graphic/object/object_2d/object_2d_data.h"
#include "interface/graphic/object/object_2d/object_2d.h"
#include "interface/graphic/vertex/vertex_2d.h"
#include "interface/graphic/texture/texture.h"
#include "interface/graphic/renderstate/state/renderstate.h"

// common
#include "common/common.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************

//=============================================================================
// コンストラクタ
//=============================================================================
CObject2D::CObject2D(CDeviceHolder* device_holder,OBJECT_2D_TYPE object_2d_type)
{
	device_holder_ = device_holder;

	object_2d_type_ = object_2d_type;
}

//=============================================================================
// デストラクタ
//=============================================================================
CObject2D::~CObject2D(void)
{
}

//void CObject2D::Draw(CObject2DData* pObject2DData)
//{
//
//}

void CObject2D::Draw(CVertex2D* pVertex2D)
{
	if(pVertex2D !=NULL)
	{
		//pVertex2D->D
	}
}

//---------------------------------- EOF --------------------------------------

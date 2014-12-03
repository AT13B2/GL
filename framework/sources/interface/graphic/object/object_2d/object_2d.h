//*****************************************************************************
//
// オブジェクト2Dクラス [object_2d.h]
//
// Author		: KENJI KABUTOMORI
// Date			: 2014/04/21(Mon)
// Version		: 1.00
// Update Date	: 2014/05/14(Wed)
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _OBJECT_2D_H_
#define _OBJECT_2D_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
// graphic
#include "interface/graphic/object/object.h"

// common
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
// クラスの前方参照
//*****************************************************************************
class CObject2DData;
class CDeviceHolder;
class CModel;
class CVertex2D;
class CTexture;
class CRenderstate;


//*****************************************************************************
// クラス定義
//*****************************************************************************
class CObject2D : public CObject
{
public:
	enum OBJECT_2D_TYPE
	{
		OBJECT_2D_TYPE_RECTANGLE = 0,
		OBJECT_2D_TYPE_BILLBOARD,
		OBJECT_2D_TYPE_OBJECT_MODEL,
		OBJECT_2D_TYPE_MAX
	};

	// コンストラクタ
	explicit CObject2D(CDeviceHolder* device_holder,OBJECT_2D_TYPE type);

	// デストラクタ
	virtual ~CObject2D(void);

	// 描画処理
	virtual void Draw(CObject2DData* object_2d_data) = 0;

	// 2Dポリゴンの描画処理
	void Draw(const MATRIX4x4& matrix,CVertex2D* vertex_2d,CTexture* texture,CRenderstate* renderstate);

	// 設定処理
	virtual void Set(void) = 0;

protected:
	CDeviceHolder* device_holder_;
	const MATRIX4x4& GetWorldMatrix(CObject2DData* object_2d_data);

private:
	OBJECT_2D_TYPE object_2d_type_;
};

#endif	// _OBJECT_2D_H_

//---------------------------------- EOF --------------------------------------

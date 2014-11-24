//*****************************************************************************
//
// OpenGLテクスチャクラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _GL_TEXTURE_H_
#define _GL_TEXTURE_H_

#ifdef _USING_OPENGL_

//*****************************************************************************
// インクルード
//*****************************************************************************
// graphic
#include "interface/graphic/texture/texture.h"
#include "interface/graphic/device/opengl/opengl.h"

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
class CDeviceHolder;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CGLTexture : public CTexture
{
public:
	// コンストラクタ
	CGLTexture(CDeviceHolder* device_holder);

	// コンストラクタ
	CGLTexture(CDeviceHolder* device_holder,const char* pFilename);

	// デストラクタ
	~CGLTexture(void);

	// 初期化
	bool Init(void);

	// 
	void Uninit(void);

	// ロード
	bool Load(const char* pFilename);

	// 
	bool Set(void);

	// 
	void Unset(void);

private:
	enum EXTENSION				// 拡張子
	{
		EXTENSION_NONE = 0,		// 識別不能
		EXTENSION_TGA,			// tgaファイル
		EXTENSION_PNG,			// pngファイル
		EXTENSION_MAX			// 対応ファイルの最大数
	};

	// テクスチャID
	unsigned int m_nTexture;

	// 拡張子の識別
	EXTENSION GetExtension(const char* pFilename);

	// TGAファイルのロード
	unsigned int LoadTga(const char* pFilename);

	unsigned int LoadPng(const char* pFilename);

};

#endif

#endif	// _GL_TEXTURE_H_

//---------------------------------- EOF --------------------------------------

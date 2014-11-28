//*****************************************************************************
//
// GLモデルクラス
//
// Author		: Ryo Kobayashi
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _GLMODEL_H_
#define _GLMODEL_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <Windows.h>
#include "interface/graphic/model/model.h"
#include "interface/graphic/vertex/vertex_3d.h"
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
class CDeviceHolder;
class Vertex3D;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CGLModel : public CModel
{
public:

	// コンストラクタ
	CGLModel(CDeviceHolder* device_holder);

	// デストラクタ
	~CGLModel(void);

	// 初期化
	bool Init(void);

	// 終了
	void Uninit(void);

	// ロード
	bool Load(const s8* filename);

	// 描画
	void Draw(const MATRIX4x4& matrix);

private:

	// データヘッダ
	struct DataHeader
	{
		u32 uVtx;
		u32 uIdx;
		u32 uMat;
		u32 uAtt;
	};
	
	// メッシュアトリビュート
	struct MeshAttribute
	{
		u32 idxStart;	// 開始インデックス
		u32 idxNum;	// インデックス数
		u32 vtxStart;	// 開始頂点番号
		u32 vtxNum;	// 頂点数
		u32 faceNum;	// プリミティブ数
	};
	
	// マテリアル情報
	struct Material
	{
		VECTOR4 Diffuse;
		VECTOR4 Ambient;
		VECTOR4 Specular;
		VECTOR4 Emissive;
		f32 SpecPower;
	};

	// テクスチャ付マテリアル情報
	struct TexMaterial
	{
		Material mat;
		s8 TexFileName[MAX_PATH];
	};

private:

	// 頂点バッファ
	CVertex3D *m_pVtxBuffer;
	
	// マテリアル数
	u32 m_uNumMaterial;
	// マテリアル
	TexMaterial* m_pMaterial;

	// アトリビュート
	MeshAttribute* m_pMeshAttribute;
};

#endif	// _MODEL_H_

//---------------------------------- EOF --------------------------------------

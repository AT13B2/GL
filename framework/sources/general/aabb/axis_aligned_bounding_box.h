//*****************************************************************************
//
// 軸平行バウンディングボックスクラス
//
// Author		: Ryo Kobayashi
//
//*****************************************************************************

//*****************************************************************************
// 多重定義防止
//*****************************************************************************
#pragma once

#ifndef _AXIS_ALIGNED_BOUNDING_BOX_H_
#define _AXIS_ALIGNED_BOUNDING_BOX_H_

//*****************************************************************************
// warning消し
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "common/math/vector/vector3.h"
#include <float.h>

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

//*****************************************************************************
// クラス定義
//*****************************************************************************
class AABB
{
public:

	AABB() : Min(FLT_MAX, FLT_MAX, FLT_MAX), Max(FLT_MIN, FLT_MIN, FLT_MIN){}

	AABB(const f32 minX, const f32 minY, const f32 minZ, const f32 maxX, f32 const maxY, const f32 maxZ) :
	Min(minX, minY, minZ), Max(maxX, maxY, maxZ){}

	AABB(const VECTOR3& min, const VECTOR3& max) : Min(min), Max(max){}

	~AABB(){}

	// ボックスの中心点を返す
	VECTOR3 center(void) const;

	// ボックスの各辺の長さを返す
	VECTOR3 size(void) const;
	// X軸方向の長さを返す
	f32 width(void) const;
	// Y軸方向の長さを返す
	f32 height(void) const;
	// Z軸方向の長さを返す
	f32 depth(void) const;

	// 指定したインデックス(0 ~ 7)からAABBの頂点を取得
	// 左手系と考え
	// Z軸を負から正の方向へ見た場合
	// (5)1----2(6)
	//    |    |
	//    |    |
	// (4)0----3(7)
	// という番号付けにする(即席で平面を作りたいとき以外あまり気にする必要はないかも)
	VECTOR3 corner(s32 nIndex) const;
	
	// 頂点を追加(必要な分だけ拡張する)
	void add(const f32 x, const f32 y, const f32 z);
	// 頂点を追加(必要な分だけ拡張する)
	void add(const VECTOR3& pos);
	// AABBを追加(必要な分だけ拡張する)
	void add(const AABB& aabb);

	// ボックス最小値
	VECTOR3 Min;
	// ボックス最大値
	VECTOR3 Max;
};

#endif	// _AXIS_ALIGNED_BOUNDING_BOX_H_

// EOF
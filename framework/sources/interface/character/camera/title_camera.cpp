//*****************************************************************************
//
// タイトルカメラクラス
//
// Author		: Chiharu Kamiyama
//
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "interface/character/camera/title_camera.h"

#include "interface/graphic/camera/camera.h"
#include "interface/graphic/camera/camera_manager.h"
#include "interface/graphic/device/device_holder.h"
#include "interface/graphic/graphic_manager.h"

#include "interface/input/input_manager.h"
#include "interface/input/input_manager.h"

#include "interface/interface_manager.h"

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
CTitleCamera::CTitleCamera(CInterfaceManager* interface_manager) : CCharacterCamera(interface_manager)
{
	move_speed_ = 0;

	camera_key_ = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CTitleCamera::~CTitleCamera(void)
{
}

//=============================================================================
// 初期化
//=============================================================================
bool CTitleCamera::Init(void)
{
	CGraphicManager* graphic_manager = interface_manager_->graphic_manager();
	WINDOW_DATA* window_data = interface_manager_->window_data();
	CCameraManager* camera_manager = graphic_manager->camera_manager();
	camera_key_ = camera_manager->CreateCamera();
	CCamera* camera = camera_manager->GetCamera(camera_key_);

	// 初期化失敗
	if(!camera->Init())
	{
		// 作ったカメラを削除
		camera_manager->EraseCamera(camera_key_);
		return false;
	}

	// 初期座標の設定
	camera->SetPosition(VECTOR3(0.0f,100.0f,120.0f),VECTOR3(0.0f,0.0f,0.0f));

	// パースペクティブの設定
	camera->SetPerspective(60.0f,((f32)(window_data->_width) / window_data->_height),1.0f,10000.0f);

	move_speed_ = 1.0f;

	length_ = 50.0f;

	return true;
}

//=============================================================================
// 更新
//=============================================================================
void CTitleCamera::Update(void)
{
	
}

//=============================================================================
// 終了
//=============================================================================
void CTitleCamera::Uninit(void)
{
	CGraphicManager* graphic_manager = interface_manager_->graphic_manager();
	WINDOW_DATA* window_data = interface_manager_->window_data();
	CCameraManager* camera_manager = graphic_manager->camera_manager();

	camera_manager->EraseCamera(camera_key_);
}

//---------------------------------- EOF --------------------------------------

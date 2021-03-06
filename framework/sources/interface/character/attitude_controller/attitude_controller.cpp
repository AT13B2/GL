//*****************************************************************************
//
// 姿勢制御クラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
// character
#include "attitude_controller.h"
#include "../character_interface.h"

// interface
#include "interface/interface_manager.h"

// input
#include "interface/input/input_manager.h"

// common
#include "common/common.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************
const f32 CAM_ROT_MAX=0.00625f;
const f32 CAM_ROT_MIN=-0.62f;

//=============================================================================
// コンストラクタ
//=============================================================================
CAttitudeController::CAttitudeController(CInterfaceManager* interface_manager) : interface_manager_(interface_manager)
{
	basic_vector_ = VECTOR3(0.0f,0.0f,1.0f);

	basic_vector_.Normalize();

	axis_ = VECTOR3(0.0f,1.0f,0.0f);

	axis_.Normalize();

	rotation_ = VECTOR3(0.0f,0.0f,0.0f);
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttitudeController::~CAttitudeController(void)
{
}

//=============================================================================
// 初期化
//=============================================================================
bool CAttitudeController::Init(void)
{
	return true;
}

//=============================================================================
// 終了
//=============================================================================
void CAttitudeController::Uninit(void)
{
}

//=============================================================================
// 更新
//=============================================================================
void CAttitudeController::Update(void)
{
	CInputManager* input_manager = interface_manager_->input_manager();

	//操作によりカメラを回転させる
	if(input_manager->CheckPress(INPUT_EVENT_RIGHT))
	{
		rotation_._y += MTH_DEGREE * 1.0f;
	}

	if(input_manager->CheckPress(INPUT_EVENT_LEFT))
	{
		rotation_._y -= MTH_DEGREE * 1.0f;
	}

	if(input_manager->CheckPress(INPUT_EVENT_DOWN))
	{
		rotation_._x -= MTH_DEGREE * 1.0f;
	}

	if(input_manager->CheckPress(INPUT_EVENT_UP))
	{
		rotation_._x += MTH_DEGREE * 1.0f;
	}


	//カメラの動きに制限をかける
	if(rotation_._x>=CAM_ROT_MAX)
	{
		rotation_._x=CAM_ROT_MAX;
	}

	if(rotation_._x<=CAM_ROT_MIN)
	{
		rotation_._x=CAM_ROT_MIN;
	}
	// 前方ベクトルを求める
	front_vector_ = basic_vector_.RotationAxis(VECTOR3(1.0f,0.0f,0.0f),rotation_._x);
	front_vector_.Normalize();
	front_vector_ = front_vector_.RotationAxis(VECTOR3(0.0f,1.0f,0.0f),rotation_._y);
	front_vector_.Normalize();

	// 右ベクトル
	right_vector_ = front_vector_.CrossProduct(VECTOR3(0.0f,1.0f,0.0f));
	right_vector_.Normalize();

	for(auto it = character_container_.begin();it != character_container_.end();++it)
	{
		(*it)->set_front_vector(front_vector_);
		(*it)->set_right_vector(right_vector_);
	}
}

//=============================================================================
// 追加処理
//=============================================================================
void CAttitudeController::Push(CCharacterInterface* character_interface)
{
	character_container_.push_back(character_interface);
}

//---------------------------------- EOF --------------------------------------

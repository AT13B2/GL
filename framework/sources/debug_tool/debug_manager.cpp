//*****************************************************************************
//
// デバッグマネージャークラス
//
// Author		: Kenji Kabutomori
//
//*****************************************************************************

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "debug_manager.h"
#include "debug_console.h"

#include "basic/application_manager.h"
#include "interface/interface_manager.h"
#include "interface/input/input_manager.h"

#include "common/thread/thread.h"
#include "common/common.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
CDebugManager CDebugManager::instance_;

//=============================================================================
// コンストラクタ
//=============================================================================
CDebugManager::CDebugManager(void)
{
#ifdef _DEBUG
	application_manager_ = NULL;
	debug_console_ = NULL;
#endif
}

//=============================================================================
// デストラクタ
//=============================================================================
CDebugManager::~CDebugManager(void)
{
}

//=============================================================================
// 初期化
//=============================================================================
bool CDebugManager::Init(void)
{
#ifdef _DEBUG
	debug_console_ = new CDebugConsole();

	// 初期化
	INIT(debug_console_);

	// コンソールを隠す
	//debug_console_->Hide();

	is_run_ = true;
	is_update_ = true;
	is_live_ = true;
#endif
	return true;
}

//=============================================================================
// 更新
//=============================================================================
void CDebugManager::Update(void)
{
#ifdef _DEBUG
	if(application_manager_ != NULL)
	{
		CInterfaceManager* interface_manager = application_manager_->interface_manager();
		CInputManager* input_manager = interface_manager->input_manager();

		if(input_manager->CheckRelease(INPUT_EVENT_F12))
		{
			debug_console_->SwitchWindow();
		}
	}
#endif
}

//=============================================================================
// 描画
//=============================================================================
void CDebugManager::Draw(void)
{
#ifdef _DEBUG
	// デバッグコンソールの描画
	debug_console_->Draw();
#endif
}

//=============================================================================
// 終了
//=============================================================================
void CDebugManager::Uninit(void)
{
#ifdef _DEBUG
	SAFE_RELEASE(debug_console_);
	is_live_ = false;
#endif
}


//=============================================================================
// スレッドの開始
//=============================================================================
void CDebugManager::Run(void)
{
#ifdef _DEBUG
	instance_.Init();

	instance_.thread_ = new CThread();

	instance_.thread_->Init();

	instance_.thread_->Start(Thread,nullptr);
#endif
}

//=============================================================================
// スレッドの終了
//=============================================================================
void CDebugManager::Stop(void)
{
#ifdef _DEBUG
	is_run_ = false;

	SAFE_RELEASE(thread_);

	Uninit();
#endif
}

//=============================================================================
// スレッドの開始
//=============================================================================
void CDebugManager::Thread(void)
{
#ifdef _DEBUG
	while(instance_.is_run_)
	{
		if(instance_.is_update_)
		{
			instance_.Update();
			instance_.Draw();
			instance_.is_update_ = false;
		}
	}
#endif
}

//-----------------------------------EOF---------------------------------------

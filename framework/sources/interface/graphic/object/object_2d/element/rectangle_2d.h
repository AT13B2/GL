//*****************************************************************************
//
// ��`2D�N���X [object_2d.h]
//
// Author		: KENJI KABUTOMORI
// Date			: 2014/04/21(Mon)
// Version		: 1.00
// Update Date	: 2014/05/14(Wed)
//
//*****************************************************************************

//*****************************************************************************
// ���d��`�h�~
//*****************************************************************************
#pragma once

#ifndef _RECTANGLE_2D_H_
#define _RECTANGLE_2D_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "../object_2d.h"

//*****************************************************************************
// ���C�u�����̃����N
//*****************************************************************************

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �\���̒�`
//*****************************************************************************

//*****************************************************************************
// �N���X�̑O���Q��
//*****************************************************************************
class CTexture;
class CGraphicsDevice;
class CVertex3D;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CRectangle2D : public CObject2D
{
public:
	// �R���X�g���N�^
	CRectangle2D(CDeviceHolder* device_holder);

	// �f�X�g���N�^
	virtual ~CRectangle2D(void);

	enum POINT
	{
		POINT_CENTER = 0,
		POINT_LEFT_UP,
		POINT_LEFT_MIDDLE,
		POINT_LEFT_DOWN,
		POINT_RIGHT_UP,
		POINT_RIGHT_MIDDLE,
		POINT_RIGHT_DOWN,
		POINT_MIDDLE_UP,
		POINT_MIDDLE_DOWN,
		POINT_MAX,
	};


//////////henkou

// ����������
	bool Init(void);

	// �`�揈��
	void Draw(CObject2DData* pObject2DData);

	// �I������
	void Uninit(void);

	// ���_���̐ݒ�
	virtual void Set(void);

	// �T�C�Y�̐ݒ�
	void set_size(const VECTOR2& size){size_ = size;}

	// �e�N�X�`�����W�̐ݒ�
	void set_texcoord(const f32& left,const f32& right,const f32& top,const f32& bottom){left_ = left;right_ = right;top_ = top;bottom_ = bottom;}

	// �J���[�̐ݒ�
	void set_color(const COLOR4F& color){for(int i = 0;i < VERTEX_MAX;i++){color_[i] = color;}}

	// �J���[�̐ݒ�
	void set_color(const COLOR4F& left_top,const COLOR4F& right_top,const COLOR4F& left_bottom,const COLOR4F& right_bottom){color_[0] = left_top;color_[1] = left_bottom;color_[2] = right_top;color_[3] = right_bottom;}

	// ���S�̐ݒ�
	void set_point(POINT point){point_ = point;}


	/////////////////////////////////////////
protected:
	static const int VERTEX_MAX = (4);

	// �T�C�Y
	VECTOR2 size_;

	// �F
	COLOR4F color_[VERTEX_MAX];

	// �e�N�X�`�����W
	f32 left_;
	f32 right_;
	f32 top_;
	f32 bottom_;

	// ���S�_
	POINT point_;

	// ���_���W
	VECTOR2 position_[VERTEX_MAX];

	// ���_���
	CVertex2D* vertex_2d_;
private:

};

#endif	// _RECTANGLE_2D_H_

//---------------------------------- EOF --------------------------------------
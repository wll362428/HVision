#pragma once
/*******************************************************************
* Copyright (C)  2016-2017 HSB Team. 
*All rights reserved.
* Model   Name�� ImagePreProcessing.h 
* Function    �� ͼ��Ԥ����
* Author      �� Willion
* Date Created�� 2016��8��19�� 
* Remark      ��
* 
*******************************************************************/
#include "chvision.h"
class H_DLL_EXPORT CImagePreProcessing :public CHVisionTool
{
public:
	CImagePreProcessing(void);
	~CImagePreProcessing(void);

	HObject   RGB2SingleChannel(int nChannel,bool bShow = true);
	BOOL  Emphasize();
};

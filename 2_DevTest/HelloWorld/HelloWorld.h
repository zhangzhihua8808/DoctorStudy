// HelloWorld.h : HelloWorld DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHelloWorldApp
// �йش���ʵ�ֵ���Ϣ������� HelloWorld.cpp
//

class CHelloWorldApp : public CWinApp
{
public:
	CHelloWorldApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

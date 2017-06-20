//MyFirstMenu.cpp

#include "stdafx.h"


#include "ProUtil.h"
#include "ProMenu.h"
#include "ProMessage.h"
#include "ProMenuBar.h"

//Ϊ���ܹ�ʹ��ProMessageDisplay 
#define  PRO_USE_VAR_ARGS  1


//���ò˵��ڲ�ͬģʽ�µ�״̬
static uiCmdAccessState  AccessDefault(uiCmdAccessMode access_mode)
{
	return ACCESS_AVAILABLE;
}

//�Զ��庯��
void Test()
{
	AfxMessageBox("Hello World");
}

//������ڣ� ProE��VC�Ľӿ�
/*
extern "C" int user_initialize()
{
	ProError  status;
	ProFileName  MsgFile;
	ProStringToWstring(MsgFile,"IconMessage.txt");    //�ַ���ת��

	uiCmdCmdId PushButton1_cmd_id,PushButton2_cmd_id;

	//��Help�������һ��Function
	status = ProMenubarMenuAdd("MainMenu","Function","Help",PRO_B_TRUE,MsgFile);

	//Test�Ƕ�������
	//ProCmdActionAdd()


	return status;
}
*/

extern "C" int user_initialize()
{
	ProError status;

    ProFileName MsgFile;
	ProStringToWstring(MsgFile,"Message.txt");    //�ַ���ת��
    
	uiCmdCmdId cmd_id;

	//�����������������ú�����ִ�к�Ĭ�ϣ�
	status = ProCmdActionAdd("ShowTest", (uiCmdCmdActFn)Test, uiCmdPrioDefault, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &cmd_id);

	//�˵��������ߣ�
	status = ProMenubarmenuPushbuttonAdd("Utilities", "ShowMessageText", "ShowMessageText", "Active ShowMessageTest menu", 
		NULL, PRO_B_TRUE, cmd_id, MsgFile);

	return status;
}

extern "C" void  user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}
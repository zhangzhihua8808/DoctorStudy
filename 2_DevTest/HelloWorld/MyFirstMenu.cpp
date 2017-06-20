//MyFirstMenu.cpp

#include "stdafx.h"


#include "ProUtil.h"
#include "ProMenu.h"
#include "ProMessage.h"
#include "ProMenuBar.h"

//为了能够使用ProMessageDisplay 
#define  PRO_USE_VAR_ARGS  1


//设置菜单在不同模式下的状态
static uiCmdAccessState  AccessDefault(uiCmdAccessMode access_mode)
{
	return ACCESS_AVAILABLE;
}

//自定义函数
void Test()
{
	AfxMessageBox("Hello World");
}

//函数入口， ProE与VC的接口
/*
extern "C" int user_initialize()
{
	ProError  status;
	ProFileName  MsgFile;
	ProStringToWstring(MsgFile,"IconMessage.txt");    //字符串转换

	uiCmdCmdId PushButton1_cmd_id,PushButton2_cmd_id;

	//在Help后面添加一个Function
	status = ProMenubarMenuAdd("MainMenu","Function","Help",PRO_B_TRUE,MsgFile);

	//Test是动作函数
	//ProCmdActionAdd()


	return status;
}
*/

extern "C" int user_initialize()
{
	ProError status;

    ProFileName MsgFile;
	ProStringToWstring(MsgFile,"Message.txt");    //字符串转换
    
	uiCmdCmdId cmd_id;

	//添加命令（设置两个调用函数：执行和默认）
	status = ProCmdActionAdd("ShowTest", (uiCmdCmdActFn)Test, uiCmdPrioDefault, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &cmd_id);

	//菜单条（工具：
	status = ProMenubarmenuPushbuttonAdd("Utilities", "ShowMessageText", "ShowMessageText", "Active ShowMessageTest menu", 
		NULL, PRO_B_TRUE, cmd_id, MsgFile);

	return status;
}

extern "C" void  user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<windows.h>
//#define WINAPI      __stdcall 代表参数传递顺序，从右到左一次入栈，并且在函数返回之前清空栈
int WINAPI WinMain(
	HINSTANCE hinstances,//应用程序实例句柄
	HINSTANCE hPrevInstance,//上一个应用程序句柄，在win32环境下，参数返回一般为NULL，不起作用了
	LPSTR lpCmLine,//char * argv[]
	int nShowCmd)//显示命令，最大化，最小化，正常
{
	//1.窗口设计
	//2.注册窗口
	//3.创建窗口
	//4.显示和更新
	//5.通过循环取消息
	//6.处理消息
	return 0;
}

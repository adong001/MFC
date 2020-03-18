#include<Windows.h >

//6.������Ϣ(���ڹ���)
//CALLBACK --stdcall �����Ĵ���˳�򣬴�������������ջ�������ں�������ʱ�����ջ
 LRESULT CALLBACK WindowProc(
	 HWND hwnd,    //��Ϣ��������λ��
	 UINT uMsg,    //������Ϣ���ƣ�WM_XXX
	 WPARAM wParam,//���̸�����Ϣ 
	 LPARAM lParam //��긽����Ϣ
	 )
{
	 switch (uMsg)
	 {
	   case WM_CLOSE://�ر�
	  	 DestroyWindow(hwnd);//������һ����ϢWM_DESTORY
	  	 break;
	   case WM_DESTROY:
	  	 PostQuitMessage(0);
	  	 break;
	  
	   case WM_LBUTTONDOWN://����������
	   {
	  	int xPos = LOWORD(lParam);
	    int yPos = HIWORD(lParam);
	    
		char buff[1024] = {0};
		wsprintf(buff,TEXT("x = %d,y = %d"), xPos, yPos);
	  	MessageBox(hwnd, TEXT("���"), TEXT("����������"), MB_OK);
	  	break;
	   }
	   case WM_KEYDOWN://����
	   {
		MessageBox(hwnd, TEXT("����"), TEXT("���̰���"), MB_OK);
		break;
	   }
	   case WM_PAINT://��ͼ
	   {
		PAINTSTRUCT ps;//��ͼ�ṹ��
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("��ͼHello"), strlen("��ͼHello"));
		EndPaint(hwnd, &ps);
		break;
	   }
	 }
	 //����ֵĬ�ϴ���ʽ
	 return DefWindowProc(hwnd,uMsg,wParam,lParam);
}

//������ں���
//WINAPI --stdcall �����Ĵ���˳�򣬴�������������ջ�������ں�������ʱ�����ջ
int WINAPI WinMain(
	HINSTANCE hinstance,    //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance,//��һ��Ӧ�ó���ʵ���������Win32�����£�����һ��ΪNULL����������
	LPSTR lpCmdLine,        //char* argv[]
	int nShowCmd)			//��ʾ�����󻯣���С��������...
{
	/*1.��ƴ���
	  2.ע�ᴰ����
	  3.��������
	  4.��ʾ�͸���
	  5.ͨ��ѭ��ȡ��Ϣ
	  6.������Ϣ(���ڹ���)
	*/

	//1.��ƴ���
	WNDCLASS wc;
	wc.cbWndExtra = 0;//��Ķ����ڴ�
	wc.cbWndExtra = 0;//���ڵĶ����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ñ���
	wc.hCursor = LoadCursor(NULL, IDC_HAND);//���ù��,��һ������ΪNULL�����ϵͳ�ṩ�ģ�IDC_HAND--���͹��
	wc.hIcon = LoadIcon(NULL,IDI_ERROR);//����ͼ��
	wc.hInstance = hinstance;//Ӧ�ó���ʵ�����������WinMain�е��βμ���
	wc.lpfnWndProc = WindowProc;//���ڹ��̵ĺ���(�ص�����)
	wc.lpszClassName = TEXT("��һ��Windows��������");//ָ�����ڵ�������
	wc.lpszMenuName = TEXT("��һ��Windows���ڲ˵�");//�˵�����
	wc.style = 0;//��ʾ���0����Ĭ�Ϸ��

	//2.ע�ᴰ����
	RegisterClass(&wc);

	//3.��������
	/*HAND CreateWindowW(
				lpClassName,  ����
				lpWindowName, ������
				dwStyle,	  ��� Ĭ��WS_OVERAPPEDWINDOW
				x,			  ��ʾ����
				y, 
		        nWidth,		  ���
				nHeight,	  
				hWndParent,   ������ NULL
				hMenu,		  �˵�  NULL
				hInstance,    ʵ����� hinstance
		        lpParam)      ����ֵ NULL*/
	HWND hwnd = CreateWindow(wc.lpszClassName,TEXT("��һ��windows���ڱ�����"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinstance, NULL);

	//4.��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	//5.ͨ��ѭ��ȡ��Ϣ
	/*
		HWND hwnd     �����ھ��
		UINT message  ������Ϣ����
		WPARAN wParam ������Ϣ��������Ϣ
		LPAPAN lParam ������Ϣ�������Ϣ(���Ҽ�)
		SWORD time    ��Ϣ����ʱ��
		POINT pt      ������Ϣ�������Ϣ(�����x��y)
	*/
	MSG msg;
	while (1)
	{
	/*bool WINAPI
	GetMessageW(
	_Out_ LPMSG lpMsg,      ��Ϣ
	_In_opt_ HWND hWnd,     ���񴰿ڣ�NULL���������д���
	_In_ UINT wMsgFilterMin,��С�����Ĺ��˵���Ϣ��һ����0
	_In_ UINT wMsgFilterMax);0������������Ϣ*/   
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		//������Ϣ
		TranslateMessage(&msg);//������ϼ�ctrl+c/v

		//�ַ���Ϣ
		DispatchMessage(&msg);
		
	}

	return 0;
}
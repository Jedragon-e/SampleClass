#include "SampleClass.h"

LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

SampleClass::SampleClass()
	:path("./data.ini")
{
}

SampleClass::~SampleClass()
{
}

wstring SampleClass::read_ini(LPCWSTR section, LPCWSTR name)
{
	wstring result{};
	LPWSTR cBuf = (LPWSTR)malloc(sizeof(LPWSTR) * 256);
	GetPrivateProfileString(section, name, nullptr, cBuf, 256, s2ws(path).c_str());
	if (cBuf)
		result = cBuf;
	free(cBuf);
	
	if (!result.empty())
		wprintf(L"section [%ls]\n%ls=%ls", section, name, result.c_str());

	return result;
}

wstring SampleClass::s2ws(const string& str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buf, len);
	wstring wstr(buf);
	delete[] buf;
	return wstr;
}

void SampleClass::OnKey(WORD keyCode)
{
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = keyCode;

	input.ki.dwFlags = 0; // 0: key press
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP: key release
	SendInput(1, &input, sizeof(INPUT));
}

void SampleClass::OnTest()
{
	cout << "TEST" << endl;
}

int SampleClass::GetTaskbarHeight()
{
	HWND taskbar = FindWindow(L"Shell_TrayWnd", nullptr);
	if (!taskbar)
	{
		cout << "Not Find Task Bar" << endl;
		return -1;
	}

	RECT rect{};
	GetWindowRect(taskbar, &rect);

	return rect.bottom - rect.top;
}

void SampleClass::Animation_On()
{
	int frame = 0;
	while (frame < 129)
	{
		SetWindowPos(m_hWnd, HWND_TOP,
			GetSystemMetrics(SM_CXSCREEN) - 256,
			GetSystemMetrics(SM_CYSCREEN) - frame - GetTaskbarHeight(),
			256,
			128,
			SWP_SHOWWINDOW | SWP_NOSIZE);

		frame++;
		Sleep(10);
	}

	Sleep(1000);
	while (frame > 0)
	{
		SetWindowPos(m_hWnd, HWND_TOP,
			GetSystemMetrics(SM_CXSCREEN) - 256,
			GetSystemMetrics(SM_CYSCREEN) - frame - GetTaskbarHeight(),
			256,
			128,
			SWP_SHOWWINDOW | SWP_NOSIZE);

		frame--;
		Sleep(10);
	}
}

void SampleClass::Start_0()
{
	wstring key = read_ini(L"Ssection", L"Nname");

	WCHAR character = key[0];
	WORD keyCode{};
	if ((character >= L'a' && character <= L'z') || (character >= L'A' && character <= L'Z')) {
		keyCode = toupper(character); // toupper는 소문자를 대문자로 변환

		for (int i = 0; i < 10; i++)
		{
			Sleep(2000);
			OnKey(keyCode);
		}
	}
	else {
		cout << "SampleClass::SampleClass >> Error" << endl;
	}
}

void SampleClass::Start_1()
{
	// Width Height
	int consoleWidth = 600;
	int consoleHeight = 1200;

	// 화면의 전체 해상도를 얻습니다.
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// 콘솔 창의 핸들을 얻습니다.
	HWND consoleWindow = GetConsoleWindow();

	// 콘솔 창을 화면의 우측 하단에 위치시킵니다.
	MoveWindow(consoleWindow,
		screenWidth - consoleWidth,
		screenHeight - consoleHeight - 40,
		consoleWidth, 
		consoleHeight,
		TRUE);
}

void SampleClass::Start_2()
{
	for (int i = 5; i >= 1; --i) {
		std::cout << "\r" << i << "s" << std::flush; // 현재 라인을 덮어쓰기
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << "\rDone!" << std::endl; // 마지막 메시지 출력
}

void SampleClass::Satrt_3()
{
	HWND hwndNotepad = FindWindow(NULL, TEXT("제목 없음 - Windows 메모장"));
	if (hwndNotepad != NULL)
	{
		// 메모장 창을 화면의 최전면으로 가져옵니다.
		SetForegroundWindow(hwndNotepad);

		// 메모장 내의 특정 컨트롤 (예를 들어, 편집 컨트롤)의 핸들을 얻습니다.
		// 메모장의 편집 컨트롤의 정확한 클래스 이름은 시스템 또는 메모장 버전에 따라 다를 수 있으므로, 
		// 이 예제에서는 간단히 메모장의 메인 윈도우 핸들을 사용합니다.
		HWND hwndEdit = FindWindowEx(hwndNotepad, NULL, TEXT("Edit"), NULL);
		if (hwndEdit != NULL)
		{
			// 메모장의 편집 컨트롤에 포커스를 설정합니다.
			SetFocus(hwndEdit);
		}
	}
}

void SampleClass::BJ_01()
{


	cout << "         ,r'\"7" << endl;
	cout << "r`-_   ,'  ,/" << endl;
	cout << " \\. \".L_r\'" << endl;
	cout << "   `~\\/" << endl;
	cout << "      |" << endl;
	cout << "      |" << endl;

}

void SampleClass::InitWindow()
{
	m_hInstance = GetModuleHandle(nullptr);

	const wchar_t* CLASS_NAME = L"My Window Class";

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WndProc; // Fix later
	wndClass.hbrBackground = ::CreateSolidBrush(RGB(25, 25, 25));

	RegisterClass(&wndClass);

	//DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
	DWORD style = WS_POPUPWINDOW;

	int width = 256;
	int height = 256;

	RECT rect{};
	rect.left = 100;
	rect.top = 100;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Title",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hInstance,
		NULL
	);

	ShowWindow(m_hWnd, SW_SHOW);
	SetWindowPos(m_hWnd, HWND_TOP,
		(GetSystemMetrics(SM_CXSCREEN)/ 2) - 128,
		0,
		256,
		128,
		SWP_SHOWWINDOW);
}

void SampleClass::DeinitWindow()
{
	const wchar_t* CLASS_NAME = L"My Window Class";

	UnregisterClass(CLASS_NAME, m_hInstance);
}

bool SampleClass::ProcessMessages()
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return false;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

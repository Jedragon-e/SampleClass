#include "SampleClass.h"

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

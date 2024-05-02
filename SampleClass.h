#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include <Windows.h>

using namespace std;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class SampleClass
{
public:
	SampleClass();
	~SampleClass();

	wstring read_ini(LPCWSTR section, LPCWSTR name);
	wstring s2ws(const string& str);
	void OnKey(WORD keyCode);
	void OnTest();
	int GetTaskbarHeight();
	void Animation_On();

	// ini Read to Sandkey
	void Start_0();

	// Console Move
	void Start_1();

	// 카운트 다운
	void Start_2();

	// WindowFocus
	void Satrt_3();

	void BJ_01();

public:
	void InitWindow();
	void DeinitWindow();
	bool ProcessMessages();

private:
	string path;

private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;

};


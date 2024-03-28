#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include <Windows.h>

using namespace std;

class SampleClass
{
public:
	SampleClass();
	~SampleClass();

	wstring read_ini(LPCWSTR section, LPCWSTR name);
	wstring s2ws(const string& str);
	void OnKey(WORD keyCode);
	void OnTest();

	// ini Read to Sandkey
	void Start_0();

	// Console Move
	void Start_1();

	// ī��Ʈ �ٿ�
	void Start_2();

private:
	string path;

};


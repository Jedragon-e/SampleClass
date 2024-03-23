#pragma once

#include <iostream>
#include <string>

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

	void Start_0();

private:
	string path;

};


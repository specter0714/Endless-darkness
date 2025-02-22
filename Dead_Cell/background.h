#pragma once
#include<easyx.h>
#include<string>
#include<graphics.h>
#include<windows.h>
#include<iostream>

class Background {
public:

	Background();
	~Background();

	IMAGE img_background_1;
	IMAGE img_background_2;
	IMAGE img_background_3;
	IMAGE img_background_4;
	IMAGE img_background_5;

	IMAGE img_ui1;
	IMAGE img_ui2;

	LOGFONT text_style;

	TCHAR str_ad[20] = L"�ƶ�: A D";
	TCHAR str_k[20] = L"��Ծ: K";
	TCHAR str_l[20] = L"���: L";
	TCHAR str_j[20] = L"����: J";

	void load_background();
	void put_background();


	void load_ui();
	void put_ui1();
	void put_ui2();

	void put_text();
};

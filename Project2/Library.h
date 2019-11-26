#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <iomanip>

#include <stdio.h>
#include <conio.h>
#include <ctime> 
#include "windows.h" 
using namespace std;
string to_lower(string );
string to_upper(string);
// Phần này là thư viện console, do 1 người dùng đã định nghĩa sẵn
// Chỉ lấy lại để sử dụng, không tái định nghĩa
#define KEY_NONE	-1
//========= lấy tọa độ x của con trỏ hiện tại =======
int whereX();
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);
//============= đặt màu cho chữ =========
void SetColor(WORD color);
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);
//======= trả về mã phím người dùng bấm =========
int inputKey();



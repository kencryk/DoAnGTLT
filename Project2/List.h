#pragma once

#include "SinhVien.h"
bool TangDan(int , int );
bool GiamDan(int , int );
void Swap(SinhVien&, SinhVien&);
class List
{
private:
	SinhVien* sv;
	int n;
public:
	//	List();
	List(int = 0);
	List(const List&);
	~List();
	// Xay dung ham them
	void ThemVaoDau();
	void ThemVaoBatKy(int);
	void ThemVaoCuoi();
	void DocFile(SinhVien&); // Ham giong nhu them vao cuoi, nhung khong co buoc tao phong.
	// Xay dung ham xoa
	void XoaDau();
	void XoaBatKy(int);
	void XoaCuoi();
	void XoaTheoKhoa(int);

	void LinearSearch_Classroom();
	void LinearSearch_Name();
	
	void Delete_Space(string&);
	void Delete_Between_Word(string&);
	void Delete_Between_Word_Class(string&);

	void SortByMSSV(SinhVien*, bool(int, int)); 
	void SortByClass(SinhVien*, bool(string, string));
	void Show();
	void ShowTotalScholarship();
	// MENU:
	void Menu();
	void AddMenu();
	void DeleteMenu();
	void SearchMenu();
	void InputAllRecord(const char*);
	void WriteRecord(const char*);
};


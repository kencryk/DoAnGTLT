#pragma once
#include "Library.h"
#include "Birthday.h"
#include "ClassRoom.h"
using namespace std;

class SinhVien {
private: 
	// 11 Components.
	int MSSV;
	string FirstName;
	string LastName;
	BirthDay birthDay; 
	int Gender; // Chu y: 0 : Nu, 1: Nam, con lai: LOI 
	ClassRoom classRoom;
	double MathPoint;
	double PhysicalPoint;
	double ITPoint;
	double AveragePoint;
	int ScholarshipPoint;
public:
	int getMSSV();
	SinhVien(); //Default Constructor
	SinhVien(int, string, string, BirthDay, int, ClassRoom, double, double, double);
	~SinhVien(); // Destructor
	SinhVien(const SinhVien& sv);
	// Xử lý:
	string getStringSinhVien();
	ClassRoom getClass();
	void XuatSinhVien(int );
	string getFirstName();
	string getLastName();

};
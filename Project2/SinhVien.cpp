#include "SinhVien.h";
int SinhVien::getMSSV()
{
	return this->MSSV;
}
SinhVien::SinhVien() {
	BirthDay bd;
	ClassRoom cl;
	this->MSSV = 0;
	this->FirstName = "";
	this->LastName = "";
	this->birthDay = bd; 
	this->Gender = 0;
	this->classRoom = cl;
	this->MathPoint = 0;
	this->PhysicalPoint = 0;
	this-> ITPoint = 0;
	this->AveragePoint = 0;
	this->ScholarshipPoint = 0;
};
SinhVien::SinhVien(int mssv,
	string lastName,
	string firstName,
	BirthDay bd,
	int gender,
	ClassRoom cl,
	double scoreMath,
	double scorePhysic,
	double scoreIT) 
{
	this->MSSV = mssv;
	this->FirstName = firstName;
	this->LastName = lastName;
	this->birthDay = bd; 
	this->Gender = gender;
	this->classRoom = cl;
	this->MathPoint = scoreMath;
	this->PhysicalPoint = scorePhysic;
	this->ITPoint = scoreIT;
	double scoreAverage = (scoreMath + scorePhysic + scoreIT) / 3;
	this->AveragePoint = scoreAverage;
	if (scoreAverage >= 8) this->ScholarshipPoint = 200;
	else if (scoreAverage >= 7 && scoreAverage <= 8) this->ScholarshipPoint = 100;
	else this->ScholarshipPoint = 0;
};
SinhVien::~SinhVien() {}
SinhVien::SinhVien(const SinhVien& sv)
{
	this->MSSV = sv.MSSV;
	this->FirstName = sv.FirstName;
	this->LastName = sv.LastName;
	this->birthDay = sv.birthDay; // ATTENTION THIS SHIT.
	this->Gender = sv.Gender;
	this->classRoom = sv.classRoom;
	this->MathPoint = sv.MathPoint;
	this->PhysicalPoint = sv.PhysicalPoint;
	this->ITPoint = sv.ITPoint;
	this->AveragePoint = sv.AveragePoint;
	this->ScholarshipPoint = sv.ScholarshipPoint;
}
; // Destructor

string SinhVien::getStringSinhVien()
{
	string gender;
	if (this->Gender == 1) gender = "Nam";
	if (this->Gender == 0) gender = "Nu";
	return  to_string(this->MSSV ) + "," + this->LastName + "," + this->FirstName + "," + this->birthDay.toStringDate() + "," + gender + "," + this->classRoom.toStringClassRoom()
		+ "," + to_string(this->MathPoint) + "," + to_string(this->PhysicalPoint) + "," + to_string(this->ITPoint) + "," + to_string(this->AveragePoint)
		+ "," + to_string(this->ScholarshipPoint);
}

ClassRoom SinhVien::getClass()
{
	return this->classRoom;
}


// Xuat Sinh Vien: 
void SinhVien::XuatSinhVien(int NumericalOrder) {

	string GioiTinh;
	if (this->Gender == 1) GioiTinh = "Nam";
	if (this->Gender == 0) GioiTinh = "Nu";
	if (NumericalOrder < 10) {
		std::cout << NumericalOrder << setw(21) << this->MSSV << setw(20) << this->LastName << setw(20) << this->FirstName << setw(20) << this->birthDay.toStringDate() << setw(20)
			<< GioiTinh << setw(20) << this->classRoom.toStringClassRoom() << setw(20) 
			<< setprecision(2) << fixed << this->MathPoint << setw(20) 
			<< setprecision(2) << fixed << this->PhysicalPoint << setw(20)
			<< setprecision(2) << fixed << this->ITPoint << setw(20) 
			<< setprecision(2) << fixed << this->AveragePoint <<
			setw(20) << this->ScholarshipPoint << endl;
	}
	else {
		std::cout << NumericalOrder << setw(20) << this->MSSV << setw(20) << this->LastName << setw(20) << this->FirstName << setw(20) << this->birthDay.toStringDate() << setw(20)
			<< GioiTinh << setw(20) << this->classRoom.toStringClassRoom() << setw(20) 
			<< setprecision(2) << fixed << this->MathPoint << setw(20)
			<< setprecision(2) << fixed << this->PhysicalPoint << setw(20)
			<< setprecision(2) << fixed << this->ITPoint << setw(20)
			<< setprecision(2) << fixed << this->AveragePoint << setw(20)
			 << this->ScholarshipPoint << endl;
	}

}

string SinhVien::getFirstName()
{
	return this->FirstName;
}

string SinhVien::getLastName()
{
	return this->LastName;
}

int SinhVien::getScholarshipPoint()
{
	return this->ScholarshipPoint;
}



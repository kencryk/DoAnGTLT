#include "List.h"
bool TangDan(int left, int right) { 
	return left > right;
}
bool GiamDan(int left, int right) { 
	return left < right;
}
bool TangDan(string left, string right) {
	return left > right;
}
bool GiamDan(string left, string right) {
	return left < right;
}
string StandardizeString(string String) {
	for (unsigned int i = 0; i < String.length(); i++) {
		if (String[i] == '\t') {
			String[i] = ' ';
		}
	}
	while (String[String.length() - 1] == ' ') {
		String.erase(String.length() - 1, 1);
	}
	while (String[0] == ' ')
		String.erase(0, 1);
	for (unsigned int i = 0; i < String.length(); i++) {
		if (String[i] == ' ' && String[i + 1] == ' ') {
			while (String[i + 1] == ' ') {
				String.erase(i + 1, 1);
			}
		}
	}
	return String;
}
void Swap(SinhVien& a, SinhVien& b) {
	SinhVien temp;
	temp = a;
	a = b;
	b = temp;
}
SinhVien TaoSinhVien() {
	int mssv;
	// Co can phai valid MSSV?
	std::cout << "Nhap ma so sinh vien: ";
	std::cin >> mssv;
	std::cin.ignore();
	string firstName;
	std::cout << "Nhap ho: ";
	getline(std::cin, firstName);
	string lastName;
	std::cout << "Nhap ten: ";
	getline(std::cin, lastName);
	//std::cin.ignore();
	std::cout << "Nhap thang nam sinh: " << std::endl;
	BirthDay bd = BirthDay().InputBirthday();
	int checkGender;
	do {
		std::cout << "Nhap gioi tinh: (0: Nu, 1: Nam): ";
		std::cin >> checkGender;
		if (checkGender < 0 || checkGender > 1)
			std::cout << "Moi ban nhap lai: ";
	} while (checkGender < 0 || checkGender > 1);
	std::cout << "Nhap lop ma sinh vien dang hoc: "<< std::endl;
	ClassRoom cl = ClassRoom().inputClassRoom();
	double mathPoint;
	std::cout << "Nhap diem toan: ";
	std::cin >> mathPoint;
	double physicalPoint;
	std::cout << "Nhap diem ly: ";
	std::cin >> physicalPoint;
	double itPoint;
	std::cout << "Nhap diem tin: ";
	std::cin >> itPoint;
	SinhVien sv(mssv, firstName, lastName, bd, checkGender, cl, mathPoint, physicalPoint, itPoint);
	return sv;
}

List::List(int x)
{
	this->n = x;
	this->sv = new SinhVien[this->n];
}

List::List(const List& p)
{
	this->n = p.n;
	this->sv = new SinhVien[this->n];
	for (int i = 1; i < this->n; i++) {
		this->sv[i] = p.sv[i];
	}
}



List::~List()
{
	delete[] this->sv;
}

void List::ThemVaoDau()
{
	SinhVien p = TaoSinhVien();
	int x = ++this->n;
	SinhVien* p1 = new SinhVien[x];
	for (int i = 1; i < x; i++) {
		p1[i] = this->sv[i - 1];
	}
	p1[0] = p;
	delete[] this->sv;
	this->sv = new SinhVien[x];
	this->n = x;

	for (int i = 0; i < this->n; i++) {
		this->sv[i] = p1[i];
	}
	delete[] p1;
	//std::cout << "Tao Sinh Vien Thanh Cong (Them vao dau Danh sach)." << std::endl;

}

void List::ThemVaoBatKy(int ViTri)
{
	int x = ++this->n;
	SinhVien p = TaoSinhVien();
	SinhVien* p1 = new SinhVien[x];
	for (int i = 0; i < this->n - 1; i++) {
		p1[i] = this->sv[i];
	}
	delete[] this->sv;

	for (int i = x - 1; i > ViTri; i--) {
		p1[i] = p1[i - 1];
	}
	p1[ViTri] = p;
	this->sv = new SinhVien[x];
	this->n = x;
	for (int i = 0; i < this->n; i++) {
		this->sv[i] = p1[i];
	}
	delete[] p1;
	//std::cout << "Tao sinh vien thanh cong (O vi tri bat ky) " << std::endl;

}

void List::ThemVaoCuoi()
{
	int x = ++this->n;
	SinhVien* p1 = new SinhVien[x];
	for (int i = 0; i < x - 1; i++) {
		p1[i] = this->sv[i];
	}
	delete[] this->sv;
	SinhVien p = TaoSinhVien();
	p1[x - 1] = p;
	this->sv = new SinhVien[x];
	this->n = x;
	for (int i = 0; i < this->n; i++) {
		this->sv[i] = p1[i];
	}
	delete[] p1;
	//std::cout << "Tao Sinh Vien Thanh Cong (Them vao cuoi danh sach)." << std::endl;

}

void List::DocFile(SinhVien& p)
{
	int x = ++this->n;
	SinhVien* p1 = new SinhVien[x];
	for (int i = 0; i < x - 1; i++) {
		p1[i] = this->sv[i];
	}
	delete[] this->sv;
	p1[x - 1] = p;
	this->sv = new SinhVien[x];
	this->n = x;
	for (int i = 0; i < this->n; i++) {
		this->sv[i] = p1[i];
	}
	delete[] p1;
}

void List::XoaDau()
{
	int x = this->n;
	SinhVien* p1 = new SinhVien[x];
	for (int i = 0; i < this->n; i++) {
		p1[i] = this->sv[i];
	}
	delete[] this->sv;

	for (int i = 0; i < x - 1; i++) {
		p1[i] = p1[i + 1];
	}
	x--;
	this->sv = new SinhVien[x];
	this->n = x;
	for (int i = 0; i < this->n; i++) {
		this->sv[i] = p1[i];
	}
	delete[] p1;
//	std::cout << "Xoa Sinh Vien Thanh Cong (Xoa o dau) " << std::endl;
}

void List::XoaBatKy(int ViTri)
{
	int x = this->n;
	SinhVien* p1 = new SinhVien[x];
	for (int i = 0; i < this->n; i++) {
		p1[i] = this->sv[i];
	}
	delete[] this->sv;

	for (int i = ViTri; i < x - 1; i++) {
		p1[i] = p1[i + 1];
	}
	x--;
	this->sv = new SinhVien[x];
	this->n = x;
	for (int i = 0; i < this->n; i++) {
		this->sv[i] = p1[i];
	}
	delete[] p1;
	//std::cout << "Xoa thanh cong (o vi tri bat ky)" << std::endl;
}

void List::XoaCuoi()
{
	int x = this->n;
	SinhVien* p1 = new SinhVien[x];
	for (int i = 0; i < this->n; i++) {
		p1[i] = this->sv[i];
	}
	delete[] this->sv;
	x--;
	this->sv = new SinhVien[x];
	this->n = x;
	for (int i = 0; i < this->n; i++) {
		this->sv[i] = p1[i];
	}
	delete[] p1;
	//std::cout << "Xoa Thanh Cong (Xoa o Cuoi) " << std::endl;
}

void List::XoaTheoKhoa(int khoaHoc)
{
	bool check = false;
	for (int i = 0; i < this->n; i++) {
		if (this->sv[i].getClass().getYear() == khoaHoc) {
			check = true;
			this->XoaBatKy(i);
			i--;
		}
	}
	if (!check) std::cout << "Khoa hoc nay khong co trong danh sach." << std::endl;
}

void List::LinearSearch_Classroom()
{
	cin.ignore();
	int count = 0;
	std::cout << " \t \t Nhap vao lop ma ban muon tim kiem trong danh sach";
	std::cout << endl;
	int year;
	std::string major;
	int index;
	std::cout << "\t \t Nhap so khoa: ";
	std::cin >> year;
	std::cin.ignore();
	std::cout << "\t \t Nhap ten lop: ";
	getline(std::cin, major);
	Delete_Space(major);
	Delete_Between_Word_Class(major);
	std::cout << "\t \t Nhap so lop: ";
	std::cin >> index;
	std::cin.ignore();
	std::cout << "Lop Can tim" " = ";
	std::cout << year;
	std::cout << major;
	std::cout << index << std::endl;
	//std::cout << ". Cac sinh vien trong lop : " << std::endl;
	cout << "STT" << setw(15) << "MSSV" << setw(20) << "Ho" << setw(22) << "Ten"
		<< setw(21) << "Ngay Sinh" << setw(24) << "Gioi Tinh" << setw(14) << "Lop" << setw(26) << "Diem Toan" <<
		setw(20) << "Diem Ly" << setw(20) << "Diem Tin" <<
		setw(20) << "Diem Trung Binh" << setw(20) << "Hoc Bong" << endl;
	for (int i = 0; i < n; i++)
	{
		//string lowerMajor = to_lower((this->sv + i)->getClass().getMajor());

		if ((this->sv + i)->getClass().getYear() == year && to_lower(((this->sv + i)->getClass().getMajor())) == to_lower(major)  && (this->sv + i)->getClass().getIndex() == index)
		{
			(this->sv + i)->XuatSinhVien(i+1);
			count = 1;
		}
	}
	if (count == 0)
	{
		cout << endl;
		cout << "Khong tim duoc sinh vien nao trong lop nay. " << endl;
	}
	cout << endl;
}

void List::LinearSearch_Name()
{
	cin.ignore();
	int count = 0;
	std::cout << " \t \t Nhap vao ten sinh vien ma ban muon tim kiem trong danh sach";
	std::cout << endl;
	std::string LastName;
	std::cout << "\t \t Ho : ";
	getline(std::cin, LastName);
	Delete_Space(LastName);
	Delete_Between_Word(LastName);
	std::string FirstName;
	std::cout << "\t \t Ten : ";
	getline(std::cin, FirstName);
	Delete_Space(FirstName);
	Delete_Between_Word(FirstName);
	SetColor(14);
	std::cout << "Ten Can tim" " = " << LastName << " " << FirstName << std::endl;
	SetColor(2);
	std::cout << setw(130) << "---------DANH SACH SINH VIEN -----------" << std::endl;
	SetColor(3);
	cout << "STT" << setw(18) << "MSSV" << setw(18) << "Ho" << setw(22) << "Ten"
		<< setw(21) << "Ngay Sinh" << setw(24) << "Gioi Tinh" << setw(14) << "Lop" << setw(26) << "Diem Toan" <<
		setw(18) << "Diem Ly" << setw(20) << "Diem Tin" <<
		setw(23) << "Diem Trung Binh" << setw(20) << "Hoc Bong" << endl;
	SetColor(15);
	for (int i = 0; i < n; i++)
	{
		if (to_upper((this->sv + i)->getFirstName()) == to_upper(FirstName) && to_upper((this->sv + i)->getLastName()) == to_upper(LastName))
		{
			(this->sv + i)->XuatSinhVien(i+1);
			count = 1;
		}
	}
	if (count == 0)
	{
		cout << endl;
		cout << "Khong tim duoc sinh vien " << endl;
	}
	cout << endl;
}

void List::Delete_Space(string& str)
{
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
}

void List::Delete_Between_Word(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
}
void List::Delete_Between_Word_Class(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
}
void List::SortByMSSV(SinhVien* B, bool SoSanh(int, int))
{
	for (int i = 0; i < this->n - 1; i++) {
		for (int j = i; j < this->n; j++) {
			if (SoSanh(B[i].getMSSV(), B[j].getMSSV())) Swap(B[i], B[j]);
		}
	}
}

void List::SortByClass(SinhVien* B, bool SoSanh(string, string))
{
	for (int i = 0; i < this->n - 1; i++) {
		for (int j = i; j < this->n; j++) {
			if (SoSanh(B[i].getClass().toStringClassRoom(), B[j].getClass().toStringClassRoom())) Swap(B[i], B[j]);
		}
	}
}



void List::Show()
{
	if (this->n != 0) {
		SetColor(2);
		std::cout << setw(130) << "---------DANH SACH SINH VIEN -----------" << std::endl;
		SetColor(3);
		cout << "STT" << setw(18) << "MSSV" << setw(18) << "Ho" << setw(22) << "Ten"
			<< setw(21) << "Ngay Sinh" << setw(24) << "Gioi Tinh" << setw(14) << "Lop" << setw(26) << "Diem Toan" <<
			setw(18) << "Diem Ly" << setw(20) << "Diem Tin" <<
			setw(23) << "Diem Trung Binh" << setw(20) << "Hoc Bong" << endl;
		SetColor(15);
		for (int i = 0; i < this->n; i++) {
			this->sv[i].XuatSinhVien(i+1);
		}
	}
	else {
		SetColor(4);
		std::cout << setw(130) << "KHONG CO SINH VIEN. " << std::endl;
		SetColor(15);
	}
}

void List::ShowTotalScholarship()
{
	int x = this->n;
	// Khoi tao 1 List khác để dễ dàng thực hiện
	SinhVien* p1 = new SinhVien[x];
	for (int i = 0; i < this->n; i++) {
		p1[i] = this->sv[i];
	}
	
	this->SortByClass(p1,TangDan);

	string Class = p1[0].getClass().toStringClassRoom();
	string checkClass = p1[0].getClass().toStringClassRoom();
	int TotalStudents = 0;
	int TotalSchorlarship = 0;
	SetColor(2);
	std::cout << setw(80) << "Lop " << setw(40) << "Tong so hoc sinh" << setw(40) << "Tong hoc bong" << std::endl;
	for (int i = 0; i < this->n; i++) {
		Class = p1[i].getClass().toStringClassRoom();
		if (Class == checkClass) {
			TotalStudents += 1;
			TotalSchorlarship += p1[i].getScholarshipPoint();
		}
		else {
			SetColor(14);
			std::cout << setw(80) << checkClass << setw(35) << TotalStudents << setw(40) << TotalSchorlarship << std::endl;
			checkClass = p1[i].getClass().toStringClassRoom();
			TotalStudents = 1;
			TotalSchorlarship = p1[i].getScholarshipPoint();
			if (i == this->n - 1) {
				std::cout << setw(80) << Class << setw(35) << TotalStudents << setw(40) << TotalSchorlarship << std::endl;
				checkClass = p1[i].getClass().toStringClassRoom();
			}
			SetColor(15);
		}
	}
}

void List::Menu()
{
	int LuaChon = 0;
	while (LuaChon != 7) {
		SetColor(2);
		std::cout.width(150); std::cout << "================================  MENU  ================================" << std::endl;
		SetColor(12);
		std::cout.width(124); std::cout << std::right << "1. Hien thi danh sach sinh vien:" << std::endl;
		std::cout.width(110); std::cout << std::right << "2. Them Sinh Vien:" << std::endl;
		std::cout.width(127); std::cout << std::right << "3. Hien thi bang thong ke theo lop:" << std::endl;
		std::cout.width(109); std::cout << std::right << "4. Xoa Sinh Vien:" << std::endl;
		std::cout.width(114); std::cout << std::right << "5. Tim kiem doi tuong:" << std::endl;
		std::cout.width(139); std::cout << std::right << "6. Sap xep danh sach sinh vien (Theo Khoa Hoc):" << std::endl;
		std::cout.width(130); std::cout << std::right << "7. Ghi vao file va thoat chuong trinh:" << std::endl;
		SetColor(15);
		do {
			std::cout.width(120); std::cout << std::right << "Nhap lua chon cua ban:  "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 7) std::cout << endl <<  "\t \t Yeu cau nhap lai. " << std::endl;
		} while (LuaChon < 1 || LuaChon > 7);
		switch (LuaChon) {
		case 1:
		{
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			this->AddMenu();
			break;
		}
		case 3:
		{
			this->ShowTotalScholarship();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			this->DeleteMenu();
			break;
		}
		case 5:
		{
			this->SearchMenu();
			break;
		}
		case 6:
		{
			char c;
			do {
				SetColor(14);
				std::cout.width(100); std::cout << std::right << "Ban muon sap xep tang dan hay giam dan. Nhap T de sap xep tang dan. Nhap G de sap xep giam dan:";
				std::cin >> c;
				if (c == 'T' || c == 't') {
					std::cout << "\t \t Danh sach duoc sap xep tang dan: " << std::endl;
					this->SortByClass(this->sv, TangDan);
					this->Show();
					break;
				}
				else if (c == 'G' || c == 'g') {
					std::cout << "\t \t Danh sach duoc sap xep giam dan: " << std::endl;
					this->SortByClass(this->sv, GiamDan);
					this->Show();
					break;
				}
				else {
					std::cout << "\t \t Ban nhap sai. Moi ban nhap lai" << std::endl;
				}
			} while (true);
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			this->WriteRecord("../test.csv");
			break;
		}
		}
		if (LuaChon == 7) break;
	}
}

void List::AddMenu()
{
	int LuaChon = 0;
	while (LuaChon != 4) {
		SetColor(2);
		std::cout.width(150); std::cout << "================================  ADD MENU  ================================" << std::endl;
		SetColor(9);
		std::cout.width(129); std::cout << std::right << "1. Them sinh vien vao dau danh sach:" << std::endl;
		std::cout.width(130); std::cout << std::right << "2. Them sinh vien vao cuoi danh sach:" << std::endl;
		std::cout.width(129); std::cout << std::right << "3. Them sinh vien vao vi tri bat ky:" << std::endl;
		std::cout.width(120); std::cout << std::right << "4. Quay tro lai menu chinh:" << std::endl;
		SetColor(15);
		do {
			std::cout.width(120); std::cout << std::right << "Nhap lua chon cua ban:  "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 4) {
				std::cout.width(130); std::cout << std::right << "Yeu cau nhap lai. " << std::endl;
			}
		} while (LuaChon < 1 || LuaChon > 4);
		switch (LuaChon) {
		case 1:
		{
			this->ThemVaoDau();
			std::cout << "\t \t Da them sinh vien vao dau danh sach" << endl;
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			this->ThemVaoCuoi();
			std::cout << "\t \t Da them sinh vien vao cuoi danh sach" << endl;
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			int ViTri = -1;
			do {
				std::cout << "\t \t Nhap vi tri can them: "; std::cin >> ViTri;
				if (ViTri > this->n) {
					std::cout << "\t \t Vi tri can them khong hop le. Yeu cau nhap lai " << std::endl;
				}
			} while (ViTri > this->n);
			this->ThemVaoBatKy(ViTri);
			std::cout << "\t \t Da them sinh vien vao vi tri " << ViTri << endl;
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			system("cls");
			//this->Menu();
			break;
		}
		}
		if (LuaChon == 4) break;
	}
}

void List::DeleteMenu()
{
	int LuaChon = 0;
	while (LuaChon != 5) {
		SetColor(2);
		std::cout.width(150); std::cout << "================================  DELETE MENU  ================================" << std::endl;
		SetColor(11);
		std::cout.width(129); std::cout << std::right << "1. Xoa sinh vien o dau danh sach:" << std::endl;
		std::cout.width(130); std::cout << std::right << "2. Xoa sinh vien o cuoi danh sach:" << std::endl;
		std::cout.width(129); std::cout << std::right << "3. Xoa sinh vien o vi tri bat ky:" << std::endl;
		std::cout.width(129); std::cout << std::right << "4. Xoa sinh vien o 1 khoa bat ky:" << std::endl;
		std::cout.width(123); std::cout << std::right << "5. Quay tro lai menu chinh:" << std::endl;
		SetColor(15);
		do {
			std::cout.width(120); std::cout << std::right << "Nhap lua chon cua ban:   "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 5) { std::cout.width(130); std::cout << std::right << "Yeu cau nhap lai. " << std::endl; }
		} while (LuaChon < 1 || LuaChon > 5);
		switch (LuaChon) {
		case 1:
		{
			this->XoaDau();
			std::cout << "Da xoa sinh vien o dau danh sach" << endl;
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			this->XoaCuoi();
			std::cout << "Da xoa sinh vien o cuoi danh sach" << endl;
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			int ViTri = -1;
			do {
				std::cout << "\t \t Nhap vi tri can xoa: "; std::cin >> ViTri;
				if (ViTri > this->n) {
					std::cout << endl <<"\t \t Vi tri can them khong hop le. Yeu cau nhap lai " << std::endl;
				}
			} while (ViTri > this->n);
			this->XoaBatKy(ViTri);
			std::cout << "\t \t Da xoa sinh vien o vi tri " << ViTri << endl;
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			int khoaHoc;
			std::cout << "\t \t Nhap khoa hoc can xoa:"; std::cin >> khoaHoc;
			this->XoaTheoKhoa(khoaHoc);
			std::cout << "Da xoa khoa hoc: " << khoaHoc << endl;
			this->Show();
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			system("cls");
		//	this->Menu();
			break;
		}
		}
	if (LuaChon == 5) 	break;
	}
}

void List::SearchMenu()
{
	int LuaChon = 0;
	while (LuaChon != 3)
	{
		SetColor(2);
		std::cout.width(150); std::cout << std::right << "================================  Search MENU  ================================" << std::endl;
		SetColor(13);
		std::cout.width(117); std::cout << std::right << "1. Tim kiem theo ten Lop:" << std::endl;
		std::cout.width(123); std::cout << std::right << "2. Tim kiem theo ten Sinh Vien:" << std::endl;
		std::cout.width(119); std::cout << std::right << "3. Quay tro lai menu chinh:" << std::endl;
		SetColor(15);
		do {
			std::cout.width(120); std::cout << std::right << "Nhap lua chon cua ban: "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 4) { std::cout.width(130); std::cout << std::right << "Yeu cau nhap lai. " << std::endl; }
		} while (LuaChon < 1 || LuaChon > 3);
		switch (LuaChon) {
		case 1:
		{
			this->LinearSearch_Classroom();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			this->LinearSearch_Name();
			system("pause");
			system("cls");
			break;
		}
		default:
			system("cls");
	//		this->Menu();
			break;
		}
		break;
	}
}

void List::InputAllRecord(const char* filePath)
{
	int NumericalOrder = 0;
	ifstream ip(filePath);
	string MSSV, DiemToan, DiemLy, DiemTin, DiemTB, HocBong; // ATTENTION USE STOI TO CONVERT INTEGER
	string Ho, Ten, NgaySinh, Lop, GioiTinh;
	string line;

	while (ip.good()) {
		NumericalOrder++;
		// Get MSSV & set into Object SV
		getline(ip, MSSV, ',');
		if (MSSV == "") break;
		int _MSSV = stoi(MSSV);

		// Get FirstName & set into Object SV
		getline(ip, Ten, ',');

		// Get LastName & set into Object SV
		getline(ip, Ho, ',');

		// Get Birthday & set into Object SV
		getline(ip, NgaySinh, ',');
		string _NgaySinh = NgaySinh;
		char delimeter = '/';
		int DeLiMeter[2] = { 0,0 };
		string check = "";
		int count = 0;
		for (char _a : _NgaySinh) {
			count++;
			if (_a == delimeter) {
				if (DeLiMeter[0] == 0) DeLiMeter[0] = count;
				else DeLiMeter[1] = count;
			};

		}

		string day = _NgaySinh.substr(0, DeLiMeter[0] - 1);
		int _day = stoi(day);

		string month = _NgaySinh.substr(DeLiMeter[0], DeLiMeter[1] - DeLiMeter[0]);
		int _month = stoi(month);

		string year = _NgaySinh.substr(DeLiMeter[1]);
		int _year = stoi(year);
		BirthDay bd(_day, _month, _year);

		// Get Gender & set into Object SV
		getline(ip, GioiTinh, ',');
		int gioiTinh;
		if (to_lower(GioiTinh) == "nam") gioiTinh = 1;
		if (to_lower(GioiTinh) == "nu") gioiTinh = 0;

		// Get ClassRoom****
		getline(ip, Lop, ',');

		string _Lop = Lop;
		string classYear = "";
		string classMajor = "";
		string classIndex = "";
		int countClass = 0;
		for (char c : _Lop) {
			int b = c;
			if (b >= 48 && b <= 57) classYear += c;
			else {
				break;
			}
			countClass++;
		}
		int Cyear = stoi(classYear);
		_Lop = _Lop.substr(countClass);
		countClass = 0;
		for (char c : _Lop) {

			int b = c;
			if (b >= 65 && b <= 90) classMajor += c;
			else {
				break;
			}
			countClass++;
		}
		_Lop = _Lop.substr(countClass);
		classIndex = _Lop;
		int Cindex = stoi(classIndex);
		ClassRoom cl(Cyear, classMajor, Cindex);



		//sv.setClassRoom(Lop);
		// Get Points & set into Object SV
		getline(ip, DiemToan, ',');
		double _DiemToan = stod(DiemToan);

		getline(ip, DiemLy, ',');
		double _DiemLy = stod(DiemLy);

		getline(ip, DiemTin, ',');
		double _DiemTin = stod(DiemTin);

		getline(ip, DiemTB, ',');
		double _DiemTB = stod(DiemTB);

		getline(ip, HocBong, '\n');


		SinhVien sv(_MSSV, Ho, Ten, bd, gioiTinh, cl, _DiemToan, _DiemLy, _DiemTin);
		this->DocFile(sv);
	}

	ip.close();
}

void List::WriteRecord(const char* filePath)
{
	ofstream myFile(filePath, ios::out);
	for (int i = 0; i < this->n; i++) {
		myFile << this->sv[i].getStringSinhVien();
		if (i != this->n - 1) myFile << "\n";
	}
	myFile.close();
}


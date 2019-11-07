#include "List.h"
bool TangDan(int left, int right) { 
	return left > right;
}
bool GiamDan(int left, int right) { 
	return left < right;
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
	this->sv = p.sv;
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
	std::cout << "Tao Sinh Vien Thanh Cong (Them vao dau Danh sach)." << std::endl;

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
	std::cout << "Tao sinh vien thanh cong (O vi tri bat ky) " << std::endl;

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
	std::cout << "Tao Sinh Vien Thanh Cong (Them vao cuoi danh sach)." << std::endl;

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
	std::cout << "Xoa Sinh Vien Thanh Cong (Xoa o dau) " << std::endl;
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
	std::cout << "Xoa phong thanh cong (o vi tri bat ky)" << std::endl;
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
	std::cout << "Xoa Phong Thanh Cong (Xoa o Cuoi) " << std::endl;
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
	std::cout << "\t \t Nhap so lop: ";
	std::cin >> index;
	std::cin.ignore();
	for (int i = 0; i < n; i++)
	{
		if ((this->sv + i)->getClass().getYear() == year && (this->sv + i)->getClass().getMajor() == major && (this->sv + i)->getClass().getIndex() == index)
		{
			std::cout << " \t \t \t ";
		//	std::cout << "Lop Can tim" " = ";
			std::cout << year;
			std::cout << major;
			std::cout << index;
			std::cout << endl;
		//	std::cout << "Cac sinh vien trong lop : ";
			std::cout << endl;
			(this->sv + i)->XuatSinhVien(i);
			count = 1;
		}
	}
	if (count == 0)
	{
		cout << endl;
		cout << "Khong tim duoc lop " << endl;
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
	std::cout << "\t \t LastName : ";
	getline(std::cin, LastName);
	std::string FirstName;
	std::cout << "\t \t FirstName : ";
	getline(std::cin, FirstName);
	for (int i = 0; i < n; i++)
	{
		if ((this->sv + i)->getFirstName() == FirstName && (this->sv + i)->getLastName() == LastName)
		{
			std::cout << " \t \t \t ";
			std::cout << "Ten Can tim" " = ";
			std::cout << LastName;
			std::cout << FirstName;
			std::cout << endl;
			std::cout << "Cac sinh vien tim duoc : ";
			std::cout << endl;
			(this->sv + i)->XuatSinhVien(i);
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


void List::SelectionSort(SinhVien* B, bool SoSanh(int, int))
{
	for (int i = 0; i < this->n - 1; i++) {
		for (int j = i; j < this->n; j++) {
			if (SoSanh(B[i].getMSSV(), B[j].getMSSV())) Swap(B[i], B[j]);
		}
	}
}


void List::Show()
{
	if (this->n != 0) {
		std::cout << "---------DANH SACH SINH VIEN -----------" << std::endl;
		cout << "STT" << setw(15) << "MSSV" << setw(20) << "Ho" << setw(22) << "Ten"
			<< setw(21) << "Ngay Sinh" << setw(24) << "Gioi Tinh" << setw(14) << "Lop" << setw(26) << "Diem Toan" <<
			setw(20) << "Diem Ly" << setw(20) << "Diem Tin" <<
			setw(20) << "Diem Trung Binh" << setw(20) << "Hoc Bong" << endl;
		for (int i = 0; i < this->n; i++) {
			this->sv[i].XuatSinhVien(i+1);
		}
	}
	else {
		std::cout << "KHONG CO SINH VIEN. " << std::endl;
	}
}

void List::Menu()
{
	int LuaChon = 0;
	while (LuaChon != 7) {
		std::cout << "=========================MENU======================" << std::endl;
		std::cout << "1. Hien thi danh sach sinh vien " << std::endl;
		std::cout << "2. Them Sinh Vien " << std::endl;
		std::cout << "3. Cap nhat thong tin Sinh Vien. " << std::endl;
		std::cout << "4. Xoa Sinh Vien " << std::endl;
		std::cout << "5. Tim kiem doi tuong. " << std::endl;
		std::cout << "6. Sap xep danh sach sinh vien " << std::endl;
		std::cout << "7. Ghi vao file va thoat chuong trinh " << std::endl;
		do {
			std::cout << "Nhap lua chon cua ban: "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 7) std::cout << "Yeu cau nhap lai. " << std::endl;
		} while (LuaChon < 1 || LuaChon > 7);
		switch (LuaChon) {
		case 1:
		{
			this->Show();
			break;
		}
		case 2:
		{
			this->AddMenu();
			break;
		}
		case 3:
		{
			//this->CapNhat();
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
			//this->InterpolationSearch(giaPhong);
			system("pause");
			break;
		}
		case 6:
		{
			char c;
			do {
				std::cout << "Ban muon sap xep tang dan hay giam dan. Nhap T de sap xep tang dan. Nhap G de sap xep giam dan:";
				std::cin >> c;
				if (c == 'T' || c == 't') {
					std::cout << "Danh sach duoc sap xep tang dan: " << std::endl;
					SelectionSort(this->sv, TangDan);
					this->Show();
					break;
				}
				else if (c == 'G' || c == 'g') {
					std::cout << "Danh sach duoc sap xep giam dan: " << std::endl;
					SelectionSort(this->sv, GiamDan);
					this->Show();
					break;
				}
				else {
					std::cout << "Ban nhap sai. Moi ban nhap lai" << std::endl;
				}
			} while (true);
			break;
		}
		default:
			this->WriteRecord("../test.csv");
			break;
		}
		if (LuaChon == 7) break;
	}
}

void List::AddMenu()
{
	int LuaChon = 0;
	while (LuaChon != 7) {
		std::cout << "=========================ADD MENU======================" << std::endl;
		std::cout << "1. Them sinh vien vao dau danh sach " << std::endl;
		std::cout << "2. Them sinh vien vao cuoi danh sach " << std::endl;
		std::cout << "3. Them sinh vien vao vi tri bat ky . " << std::endl;
		std::cout << "4. Quay tro lai menu chinh " << std::endl;
		do {
			std::cout << "Nhap lua chon cua ban: "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 4) std::cout << "Yeu cau nhap lai. " << std::endl;
		} while (LuaChon < 1 || LuaChon > 4);
		switch (LuaChon) {
		case 1:
		{
			this->ThemVaoDau();
			break;
		}
		case 2:
		{
			this->ThemVaoCuoi();
			break;
		}
		case 3:
		{
			int ViTri = -1;
			do {
				std::cout << "Nhap vi tri can them: "; std::cin >> ViTri;
				if (ViTri > this->n) {
					std::cout << "Vi tri can them khong hop le. Yeu cau nhap lai " << std::endl;
				}
			} while (ViTri > this->n);
			this->ThemVaoBatKy(ViTri);
			break;
		}
		default:
			this->Menu();
			break;
		}
		break;
	}
}

void List::DeleteMenu()
{
	int LuaChon = 0;
	while (LuaChon != 5) {
		std::cout << "=========================DELETE MENU======================" << std::endl;
		std::cout << "1. Xoa sinh vien o dau danh sach " << std::endl;
		std::cout << "2. Xoa sinh vien o cuoi danh sach " << std::endl;
		std::cout << "3. Xoa sinh vien o vi tri bat ky . " << std::endl;
		std::cout << "4. Xoa sinh vien o 1 khoa bat ky. " << std::endl;
		std::cout << "5. Quay tro lai menu chinh " << std::endl;
		do {
			std::cout << "Nhap lua chon cua ban: "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 4) std::cout << "Yeu cau nhap lai. " << std::endl;
		} while (LuaChon < 1 || LuaChon > 5);
		switch (LuaChon) {
		case 1:
		{
			this->XoaDau();
			break;
		}
		case 2:
		{
			this->XoaCuoi();
			break;
		}
		case 3:
		{
			int ViTri = -1;
			do {
				std::cout << "Nhap vi tri can xoa: "; std::cin >> ViTri;
				if (ViTri > this->n) {
					std::cout << "Vi tri can them khong hop le. Yeu cau nhap lai " << std::endl;
				}
			} while (ViTri > this->n);
			this->XoaBatKy(ViTri);
			break;
		}
		case 4:
		{
			int khoaHoc;
			std::cout << "Nhap khoa hoc can xoa:"; std::cin >> khoaHoc;
			this->XoaTheoKhoa(khoaHoc);
			break;
		}
		default:
			this->Menu();
			break;
		}
		break;
	}
}

void List::SearchMenu()
{
	int LuaChon = 0;
	while (LuaChon != 3)
	{
		std::cout << "=========================Search MENU======================" << std::endl;
		std::cout << "1. Tim kiem theo ten Lop " << std::endl;
		std::cout << "2. Tim kiem theo ten sinh vien " << std::endl;
		std::cout << "3. Quay tro lai menu chinh " << std::endl;
		do {
			std::cout << "Nhap lua chon cua ban: "; std::cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 4) std::cout << "Yeu cau nhap lai. " << std::endl;
		} while (LuaChon < 1 || LuaChon > 3);
		switch (LuaChon) {
		case 1:
		{
			this->LinearSearch_Classroom();
			system("pause");
			break;
		}
		case 2:
		{
			this->LinearSearch_Name();
			system("pause");
			break;
		}
		default:
			this->Menu();
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
		getline(ip, Ho, ',');

		// Get LastName & set into Object SV
		getline(ip, Ten, ',');

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


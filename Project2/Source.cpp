#include "Birthday.h"
#include "SinhVien.h"
#include "Library.h"
#include "List.h"

int main() {
	List l;
	std::cout << "Chuong trinh tu dong cap nhat du lieu tu database vao. " << std::endl;
	std::cout << "Bam 1 nut bat ky de bat dau chuong trinh: ";
	system("pause");
	system("cls");
	l.InputAllRecord("../test.csv");
	l.Menu();

	return 0;
}

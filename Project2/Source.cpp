#include "Birthday.h"
#include "SinhVien.h"
#include "Library.h"
#include "List.h"

int main() {
	List l;
	std::cout << "Chuong trinh tu dong cap nhat du lieu tu database vao. " << std::endl;
	l.InputAllRecord("../test.csv");
	l.Menu();

	return 0;
}

#include "ClassRoom.h"

ClassRoom::ClassRoom()
{
	this->year = 0;
	this->major = "";
	this->index = 0;
}

ClassRoom::ClassRoom(int year, string major, int index)
{
	this->year = year;
	this->major = major;
	this->index = index;
}

ClassRoom::ClassRoom(const ClassRoom& cl)
{
	this->year = cl.year;
	this->major = cl.major;
	this->index = cl.index;
}

std::string ClassRoom::toStringClassRoom()
{
	return (to_string(this->year) + to_upper(this->major) + to_string(this->index));
}

ClassRoom ClassRoom::inputClassRoom()
{

	int year;
	std::string major;
	int index;
	std::cout << "Nhap so khoa: ";
	std::cin >> year;
	std::cin.ignore();
	std::cout << "Nhap ten lop: ";
	getline(std::cin, major);
	std::cout << "Nhap so lop: ";
	std::cin >> index;
	std::cin.ignore();
	ClassRoom cl(year, major, index);
	return cl;


}

int ClassRoom::getYear()
{
	return this->year;
}

int ClassRoom::getIndex()
{
	return this->index;
}

string ClassRoom::getMajor()
{
	return this->major;
}




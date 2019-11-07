#include "Birthday.h"
bool isLeapYear(int year) {
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}
bool BirthDay::isValidYear(int year) {
	if ((year < 1800) || (year > 9999)) return false;
	return true;
}
bool BirthDay::isValidMonth(int month) {
	if (month < 0 || month > 12) return false;
	return true;
}
BirthDay::BirthDay()
{
	this->Month = 0;
	this->Day = 0;
	this->Year = 0;
}
BirthDay::BirthDay(int day, int month, int year)
{
	this->Month = month;
	this->Day = day;
	this->Year = year;
}
BirthDay::BirthDay(const BirthDay& bd)
{
	this->Month = bd.Month;
	this->Year = bd.Year;
	this->Day = bd.Day;
}
BirthDay::~BirthDay()
{
}
bool BirthDay::isValidDay(int day, int month, int year) {
	if (day < 0 || day > 31) return false;
	if (month == 2 && day > 28) return false;
	if (isLeapYear(year) && month == 2 && day == 29) return true;
	return true;
}
BirthDay BirthDay::InputBirthday() {
	int year;
	int month;
	int day;
	do {
		
		std::cout << "Nhap nam: ";
		std::cin >> year;
		if (isValidYear(year))
		{
			this->Year = year;
			break;
		};
	} while (true);
	do {
		
		std::cout << "Nhap thang  : ";
		std::cin >> month;
		if (isValidMonth(month))
		{
			this->Month = month;
			break;
		};
	} while (true);
	do {
		
		std::cout << "Nhap ngay : ";
		std::cin >> day;
		if (isValidDay(day, this->Month, this->Year))
		{
			this->Day = day;
			break;
		};
	} while (true);
	BirthDay d(day, month, year);
	return d;
}
std::string BirthDay::toStringDate()
{
	if (this->Day == 0 && this->Month == 0 && this->Year == 0) return "NULL";
	else
		return (to_string( this->Day ) + "/" + to_string(this->Month) + "/" + to_string(this->Year ));
}

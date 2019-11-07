#pragma once
#include "Library.h"
using namespace std;
bool isLeapYear(int);
class BirthDay {
private:
	int Month;
	int Day;
	int Year;
public:
	BirthDay();
	BirthDay(int, int, int);
	BirthDay(const BirthDay&);
	~BirthDay();
	bool isValidDay(int,int,int);
	bool isValidMonth(int);
	bool isValidYear(int);
	BirthDay InputBirthday();
	std::string toStringDate();
};
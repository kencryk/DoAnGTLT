#pragma once
#include "Library.h"
class ClassRoom
{
private: 
	int year;
	string major;
	int index;
public:
	ClassRoom();
	ClassRoom(int, string, int);
	ClassRoom(const ClassRoom&);
	std::string toStringClassRoom();
	ClassRoom inputClassRoom();
	int getYear();
	string getMajor();
	int getIndex();
};


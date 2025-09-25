// Log.cpp aqui se definen las funciones de registro
#include "Log.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


Log::Log(string m, int d, string t, string i, string mot) {
	month = m;
	day = d;
	time = t;
	ip = i;
	motive = mot;
	dateNum = change2date(month, day, time);
}

long long Log::change2date(const string& month, int day, const string& time) { //de stack overflow: https://stackoverflow.com/questions/13787702/comparing-2-dates-in-c
	int M = monthToNum(month);
	int H = 0, Min = 0, S = 0;
	char c;
	stringstream ss(time);
	if (!(ss >> H >> c >> Min >> c >> S)) {
		// si el parsing falla dejamos 0
		H = Min = S = 0;
	}
	long long val = 2025LL * 10000000000LL
		+ (long long)M * 100000000LL
		+ (long long)day * 1000000LL
		+ (long long)H * 10000LL
		+ (long long)Min * 100LL
		+ (long long)S;
	return val;
}
void Log::show() const {
	std::cout << month << ' ' << day << ' ' << time << " " << ip << " " << motive << " | dateNum=" << dateNum << endl;
}

int Log::monthToNum(string month) { // Cambia la adverviatura del mes a un int
	if (month == "Jan") return 1;
	else if (month == "Feb") return 2;
	else if (month == "Mar") return 3;
	else if (month == "Apr") return 4;
	else if (month == "May") return 5;
	else if (month == "Jun") return 6;
	else if (month == "Jul") return 7;
	else if (month == "Aug") return 8;
	else if (month == "Sep") return 9;
	else if (month == "Oct") return 10;
	else if (month == "Nov") return 11;
	else if (month == "Dec") return 12;
	else return 0;
}

Log::~Log() {}

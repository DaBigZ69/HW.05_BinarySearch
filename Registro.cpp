// Registro.cpp aqui se definen las funciones de registro
#include "Registro.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Log(string m, int d, string t, string i, string mot) {
	month = m;
	day = d;
	time = t;
	ip = i;
	motive = mot;
	dateNum = change2date(month, day, time);
}

static long long change2date(const string& month, int day, const string& time) { //de stack overflow: https://stackoverflow.com/questions/13787702/comparing-2-dates-in-c
	int M = monthToNum(month);
	int H, Min, S;
	char c;
	stringstream ss(time);
	ss >> H >> c >> Min >> c >> S;

	return 2025LL * 10000000000 +
		M * 100000000 +
		day * 1000000 +
		H * 10000 +
		Min * 100 +
		S;
}

static int mesToNum(string month); {
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

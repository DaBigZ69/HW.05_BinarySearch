// Registro.h aqui se hace la clase registro que es la que lee la información 
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Log {
public:
	string month;
	unsigned int day;
	string time;
	string ip;
	string motive;
	long long dateNum;

	Log();

	Log(string m, int d, string t, string i, string mot);
	void show();

	static long long change2date(const string& month, int day, const string& time);
private:
	static int mesToNum(string month);

public:
	~Log();
};
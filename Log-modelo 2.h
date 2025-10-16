// Log.h aqui se hace la clase registro que es la que lee la información 
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Log {
public:
	string month;
	unsigned int day { 0 };
	string time;
	string ip;
	string motive;
	long long dateNum{ 0 };


	Log(string m, int d, string t, string i, string mot);

	void show() const;

	static long long change2date(const string& month, int day, const string& time);
private:
	static int monthToNum(string month);
	long long changeip(string ip);
	 
public:
	~Log();
};
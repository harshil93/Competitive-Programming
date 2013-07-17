#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class Time{
public:
	string whatTime(int seconds){
		stringstream ss;
		int sec = seconds%60;
		int min = (seconds/60)%60;
		int hours = (seconds/3600)%24;

		
		ss<<hours<<":"<<min<<":"<<sec;
		string ans = ss.str();
		return ans;
	}
};
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class LISNumberDivTwo
{
public:
	int calculate(vector <int> seq){
		int count=1;
		int cur_int = seq[0];
		for (int i = 1; i < seq.size(); ++i)
		{
			if(cur_int < seq[i]){
				cur_int = seq[i];
				continue;
			}else{
				cur_int = seq[i];
				count++;
			}
		}

		return count;
	}

	/* data */
};


int main(){
	LISNumberDivTwo test;

	int testval[] = {1, 1, 9, 9, 2, 2, 3, 3};
	std::vector<int> v(testval,testval+8);

	cout<<test.calculate(v)<<endl;
}
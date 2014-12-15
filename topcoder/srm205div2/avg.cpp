#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class Average
{
public:
	int belowAvg(vector<int> math,vector<int> verbal){
		double avg=0;
		int n= math.size();
		int sum[50]={0};
		for (int i = 0; i < n; ++i)
		{
			sum[i] = math[i] + verbal[i];
			avg += sum[i]/(double)n;
		}
		int count=0;
		for (int i = 0; i < n; ++i)
		{	
			if(sum[i]<avg){
				count++;
			}
		}
		return count;
	}
};

int main(){
	int math1[] = {200,250,700,700};
	int verbal1[]={400,400,400,400};
	std::vector<int> math(math1,math1+4);
	std::vector<int> verbal(verbal1,verbal1+4);
	Average test;
	cout<<test.belowAvg(math,verbal)<<endl;
}
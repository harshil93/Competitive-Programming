#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class SemiPerfectSquare{
	int array[30];
public:
	SemiPerfectSquare(){
		for (int i = 2; i < 32; ++i)
		{
			array[i-2] = i*i;
		}
	}
	string check(int N){
		string s = "No";
		for (int i = 0; i < 30; ++i)
		{
			if (N%array[i]==0)
			{
				int b = N/array[i];
				// PR(b);
				// PR(i);
				if (b<i+2)
				{
					s = "Yes";
					break;
				}
			}
		}
		return s;
	}
};

int main(){
	SemiPerfectSquare s;
	int n;
	n = 4;
	cin>>n;
	cout<<s.check(n)<<endl;
	
	return 0;
}
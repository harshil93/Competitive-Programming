#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
inline int fast_int()
{
int n=0;
int ch=getchar();
while(ch<48)ch=getchar();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar();
return n;
}

int main(){

	int elem[]={3,4,5,6};
	for (int i = 1; i < 16; ++i)
	{
		bitset<4> temp = std::bitset<4>(i);
		if(temp.count() == 2){
			for (int j = 0; j < 4; ++j)
			{
				if(temp[j]){
					cout<<elem[j]<<" ";
				}
			}cout<<endl;
		}
		
	   
	}
	

}
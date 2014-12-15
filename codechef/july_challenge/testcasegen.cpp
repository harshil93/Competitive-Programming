#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
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
	cout<<30<<endl;
	srand(time(NULL));
	for (int i = 0; i < 30; ++i)
	{
		cout<<(int)pow(-1,rand())*rand()%50<<" "<<(int)pow(-1,rand())(int)(rand()%50)<<endl;
	}
}
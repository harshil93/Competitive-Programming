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
int ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

int main(){
	printf("%d\n",100000 -10);
	srand(time(NULL));

	for (int i = 1; i <= 100000 -10; ++i)
	{
		printf("%d ",1+rand()%30);
	}
	printf("\n");
	for (int i = 1; i <= 100000 -10; ++i)
	{
		int a = rand()%(100000-10);
		int b = rand()%(100000-10);
		if (a>b)
		{
			int temp = a;
			a=b;
			b=temp;
		}
		printf("query %d %d\n",a,b);
	}
}
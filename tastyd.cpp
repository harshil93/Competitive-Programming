#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define sc(x) scanf("%d",&x);
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
	int t;
	sc(t);

	while(t--){
		int n;
		sc(n);
		for (int i = 0; i < n; ++i)
		{
			/* code */
		}
	}
}
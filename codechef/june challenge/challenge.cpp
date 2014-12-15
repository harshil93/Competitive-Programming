#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

inline int fast_int()
{
int n=0;
int ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

bool base3(int m){
	int rem, divisor;

	while(m!=0){
		rem = m%3;
		m = m/3;
		if (rem==2)
		{
			return false;
		}
	}

	return true;
}


int main(){
	int n;
	int M[100005];
	std::vector<int> v;
	n=fast_int();
	for (int i = 0; i < n; ++i)
	{
		M[i] = fast_int();
	}

	for (int i = 0; i < n; ++i)
	{
		if (base3(M[i]))
		{
			v.push_back(M[i]);
		}
	}

	printf("%d\n", v.size());

	for (int i = 0; i < v.size(); ++i)
	{
		printf("%d ",v[i] );
	}
	printf("\n");

}
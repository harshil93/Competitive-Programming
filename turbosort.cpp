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
int ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

inline int64_t ipow(int64_t n, int64_t k){
	if (k==0)
	{
		return 1;
	}else if(k==1){
		return 10;
	}else if(k==2){
		return 100;
	}else if(k==3){
		return 1000;
	}else if (k==4)
	{
		return 10000;
	}else if (k==5)
	{
		return 100000;
	}else if (k==6)
	{
		return 1000000;
	}
}
inline int64_t ndigfromlast(int64_t a, int64_t n){
	return (a/ipow(10,n-1))%10;
}

int main(){
	int64_t t;
	t = fast_int();
	int *array = (int *)malloc(t*sizeof(int));
	int *temp = (int *)calloc(t,sizeof(int));
	int freq[10] = {0};
	for (int i = 0; i < t; ++i)
	{
		scanf("%d",&array[i]);
	}

	for (int i = 1; i <= 6; ++i)
	{

		for (int j = 0; j < t; ++j)
		{
			
			freq[ndigfromlast(array[j],i)]++;
		}
		for (int j = 0; j < 9; ++j)
		{

			freq[j+1] = freq[j+1] + freq[j];
		}

		for (int j = t-1; j >=0; --j)
		{
			int dig = ndigfromlast(array[j],i);
			temp[freq[dig] -1] = array[j];
			freq[dig]--;
		}
		for (int i = 0; i < t; ++i)
		{
			array[i]=temp[i];
		}

		for (int i = 0; i < 10; ++i)
		{
			freq[i] = 0;
		}
	}
	for (int i = 0; i < t; ++i)
	{
		printf("%d\n",array[i] );
	}


return 0;


}
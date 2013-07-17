#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "fstream"
using namespace std;
int stored[100000];
unsigned long long maxdollar(unsigned long long n){

	if (n==0)
	{
		return 0;
	}
	if (n<100000 && stored[n])
	{
		return stored[n];
	}
	unsigned long long n2,n3,n4;
	n2 = maxdollar(n/2);n3=maxdollar(n/3);n4=maxdollar(n/4);

	if (n2 + n3 + n4 > n)
	{
		if(n<100000) stored[n] = n2+n3+n4;
		return n2+n3+n4;
	}else{
		if( n<100000) stored[n] = n;
		return n;
	}

}
int main(){
	unsigned long long n;
	while(scanf("%lld",&n)>0){
		printf("%lld\n",maxdollar(n));
	}
	return 0;
}
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define sfI(t) scanf("%d",&t)
#define sfllI(t) scanf("%lld",&t)

int main(){
	int t;

	sfI(t);
	int k;
	while(t--){
		sfI(k);

		int dividend = 103993;
		int divisor = 33102;

		if (k==0)
		{
			printf("%d\n",3 );
			continue;
		}
		printf("3.");
		int quotient;
		 dividend = (dividend%divisor)*10;

		while(k--){
			quotient = dividend/divisor;
			dividend = (dividend%divisor)*10;
			putchar(quotient+'0');
		}
		printf("\n");
	}

	return 0;
}
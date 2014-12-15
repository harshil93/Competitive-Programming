#include "cmath"
#include "cstdio"

int main(){
	
	double x = (14*exp(lgamma(14) - 6*lgamma(2) - 2*lgamma(1)))/64;
	long long int y = (long long int)(x*28)%3046201;

	printf("%lld\n",y);
}
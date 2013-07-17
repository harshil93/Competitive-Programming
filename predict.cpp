#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	double p_a;
	int t;

	scanf("%d",&t);

	while(t--){
		scanf("%lf",&p_a);

		if (p_a<0.5)
		{
			p_a = 1- p_a;
		}
		double answer = (1+2*(1-p_a))*10000*p_a;
		printf("%.6f\n",answer );
	}
}
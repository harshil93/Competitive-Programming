#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
unsigned long long nCk(int n,int k)
{
	unsigned long long val=1;
	if(k>(n/2)) k=n-k;
	for(int i=1;i<k+1;i++)
	{
		val = val * (n-i+1)/i ;
	}
	
	return val;
}
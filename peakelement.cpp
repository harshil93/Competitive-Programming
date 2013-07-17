/*Program to find peak element - Peak element is a element which is greater than its neighbours.
The idea is to use divide and conquer.*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


int peakelementfind(int *in, int start, int end,int n){
	if (abs(start-end) ==1)
	{
		return in[start]>in[end]?in[start]:in[end];
	}
	int mid = start + (end-start)/2;
	if (in[mid-1]<in[mid] && in[mid+1]<in[mid])
	{
		return in[mid];
	}

	if (in[mid-1] > in[mid])
	{
		peakelementfind(in, start, mid,n);
	}else if (in[mid+1] > in[mid])
	{
		peakelementfind(in, mid, end,n);
	}
}

int peakelement(int *in, int n){
	return peakelementfind( in,  0,  n-1,  n);
}

int main(){
	int n;
	int in[1000];
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&in[i]);
	}

	printf("%d\n", peakelement(in,n));


}
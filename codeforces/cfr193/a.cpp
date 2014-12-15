#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int main(){
	int n,k;
	cin>>n>>k;
	int abs[1000000];

	for (int i = 0; i < n; ++i)
	{
		cin>>abs[i];
	}
	int sum1=0;
	for (int i = 0; i < k; ++i)
	{
		sum1+=abs[i];
	}
	int s1=0;
	int xyz = n-k-1;
	for (int i = k; i <= xyz; ++i)
	{
		if(sum1 - abs[i-k] + abs[i] >= sum1){
			s1 = i-k + 1;
			sum1 = sum1 - abs[i-k] + abs[i];
		}
	}
	int sum2=0;
	for (int i = s1+k; i < s1+k+k; ++i)
	{
		sum2 += abs[i];
	}
	int s2 = s1+k;
	for (int i = s2 + k; i < n; ++i)
	{
		if(sum2 - abs[i-k] + abs[i] >= sum2){
			s2 = i-k +1;
			sum2 = sum2 - abs[i-k] + abs[i];
		}

	}
	int sum3=0;
		int s3 =0;
	
	if(s1>=k){
		
		for (int i = 0; i < k; ++i)
		{
			sum3 += abs[i];
		}

		for (int i = k; i < s1; ++i)
		{
			if(sum3 - abs[i-k] + abs[i] >= sum3){
				s3 = i-k + 1;
				sum3 = sum3 - abs[i-k] + abs[i];
			}
		}

	}
	PR(s1)PR(s2)PR(s3)
	if(sum3>=sum2){
		s2=s3;
	}

	// cout<<sum1+sum2<<endl;

	if(s1<s2)
		cout<<s1+1<<" "<<s2+1<<endl;
	else
		cout<<s2+1<<" "<<s1+1<<endl;
	return 0;
}
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";


int main(){
	char a[1001],b[1001];
	while(gets(a)){
		gets(b);
		int af[256]={0};
		int bf[256]={0};
		char ans[10000];
		char cnt=0;
		for (int i = 0; i < strlen(a); ++i)
		{
			af[a[i]]++;
		}
	
		for (int i = 0; i < strlen(b); ++i)
		{
			bf[b[i]]++;
		}
		
		for (int i = 0; i < 256; ++i)
		{
			int t = min(af[i],bf[i]);
			char cur = i;
			while(t--){
				ans[cnt] = i;
				cnt++;			
			}
		}
		ans[cnt] = '\0';
	}
	return 0;
}
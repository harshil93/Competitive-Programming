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
int ch=getchar();
while(ch<48)ch=getchar();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar();
return n;
}
std::vector<int> primes;
int num_fact[100005];
void calcPrimes(){
	char seive[100005]={0};
	primes.push_back(2);
	for (int i = 2; i < 100001; i=i+2)
	{
		seive[i]=1;
	}
	for (int i = 3; i < 100001; i=i+2)
	{
		if(seive[i]==0){
			primes.push_back(i);
			int j=2;
			while(i*j<100001){
				seive[i*j]=1;
				j++;
			}
		}


	}
}

void ini(){
	for (int i = 2; i < 100001; ++i)
	{
		int count = 0;
		int num =i;
		for (int j = 0; j < primes.size(); ++j)
		{
			int flag = 0;
			if(num%primes[j]==0){
				count++;
				num = num/primes[j];
			}
			if(primes[j]>num)
				break;
			if(count>5){
				count=0;
				break;
			}
		}
		num_fact[i]=count;
	}
}
int main(){
	int t = fast_int();
	calcPrimes();
	ini();
	int count[6]={0};
	int count1[100002]={0};
	int count2[100002]={0};
	int count3[100002]={0};
	int count4[100002]={0};
	int count5[100002]={0};
	for (int i = 2; i < 100001; ++i)
	{
		count[num_fact[i]]++;
		count1[i] = count[1];
		count2[i] = count[2];
		count3[i] = count[3];
		count4[i] = count[4];
		count5[i] = count[5];
	}
	while(t--){
		int a,b,k;
		a=fast_int();
		b=fast_int();
		k=fast_int();
		int badacount;
		switch(k){
			case 1:
				badacount = count1[b] - count1[a-1] ;
				break;
			case 2:
				badacount = count2[b] - count2[a-1] ;
				break;
			case 3:
				badacount = count3[b] - count3[a-1] ;
				break;
			case 4:
				badacount = count4[b] - count4[a-1] ;
				break;
			case 5:
				badacount = count5[b] - count5[a-1] ;
				break;

		}
		
		printf("%d\n",badacount);

	}

	return 0;
}
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define mod 1000000007
typedef unsigned long long ull;

inline ull fast_int()
{
ull n=0;
ull ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

ull power2(int n){
	if (n==1)
	{
		return 2;
	}

	if (n%2==0)
	{
		ull temp = power2(n/2);
		return (temp*temp)%mod;
	}else{
		ull temp = power2(n/2);
		return (temp*temp*2)%mod;
	}
	
}

ull	**matrixpower(ull n){
	if (n==1)
	{
		ull **matrix = new ull*[3];
		matrix[0] = new ull[3]();
		matrix[1] = new ull[3]();
		matrix[2] = new ull[3]();
		matrix[0][0] = 1;
		matrix[0][1] = 1;
		matrix[0][2] = 1;
		matrix[1][0] = 1;
		matrix[2][1] = 1;
		return matrix;
	}

	if (n%2==0)
	{
		ull **temp = matrixpower(n/2);
		ull **returnval = new ull*[3]();
		returnval[0]= new ull[3]();
		returnval[1]= new ull[3]();
		returnval[2]= new ull[3]();
		returnval[0][0]= (temp[0][0]*temp[0][0] + temp[0][1]*temp[1][0] + temp[0][2]*temp[2][0])%mod;
		returnval[0][1]= (temp[0][0]*temp[0][1] + temp[0][1]*temp[1][1] + temp[0][2]*temp[2][1])%mod;
		returnval[0][2]= (temp[0][0]*temp[0][2] + temp[0][1]*temp[1][2] + temp[0][2]*temp[2][2])%mod;
		returnval[1][0]= (temp[1][0]*temp[0][0] + temp[1][1]*temp[1][0] + temp[1][2]*temp[2][0])%mod;
		returnval[1][1]= (temp[1][0]*temp[0][1] + temp[1][1]*temp[1][1] + temp[1][2]*temp[2][1])%mod;
		returnval[1][2]= (temp[1][0]*temp[0][2] + temp[1][1]*temp[1][2] + temp[1][2]*temp[2][2])%mod;
		returnval[2][0]= (temp[2][0]*temp[0][0] + temp[2][1]*temp[1][0] + temp[2][2]*temp[2][0])%mod;
		returnval[2][1]= (temp[2][0]*temp[0][1] + temp[2][1]*temp[1][1] + temp[2][2]*temp[2][1])%mod;
		returnval[2][2]= (temp[2][0]*temp[0][2] + temp[2][1]*temp[1][2] + temp[2][2]*temp[2][2])%mod;

		return returnval;
	}else{
		ull **temp = matrixpower(n/2);
		ull **returnval = new ull*[3];
		returnval[0]= new ull[3];
		returnval[1]= new ull[3];
		returnval[2]= new ull[3];
		returnval[0][0]= (temp[0][0]*temp[0][0] + temp[0][1]*temp[1][0] + temp[0][2]*temp[2][0])%mod;
		returnval[0][1]= (temp[0][0]*temp[0][1] + temp[0][1]*temp[1][1] + temp[0][2]*temp[2][1])%mod;
		returnval[0][2]= (temp[0][0]*temp[0][2] + temp[0][1]*temp[1][2] + temp[0][2]*temp[2][2])%mod;
		returnval[1][0]= (temp[1][0]*temp[0][0] + temp[1][1]*temp[1][0] + temp[1][2]*temp[2][0])%mod;
		returnval[1][1]= (temp[1][0]*temp[0][1] + temp[1][1]*temp[1][1] + temp[1][2]*temp[2][1])%mod;
		returnval[1][2]= (temp[1][0]*temp[0][2] + temp[1][1]*temp[1][2] + temp[1][2]*temp[2][2])%mod;
		returnval[2][0]= (temp[2][0]*temp[0][0] + temp[2][1]*temp[1][0] + temp[2][2]*temp[2][0])%mod;
		returnval[2][1]= (temp[2][0]*temp[0][1] + temp[2][1]*temp[1][1] + temp[2][2]*temp[2][1])%mod;
		returnval[2][2]= (temp[2][0]*temp[0][2] + temp[2][1]*temp[1][2] + temp[2][2]*temp[2][2])%mod;
		returnval[0][0]= (returnval[0][0] + returnval[0][1])%mod;
		returnval[0][1]= (returnval[0][0] + returnval[0][2])%mod;
		returnval[0][2]= (returnval[0][0])%mod;
		returnval[1][0]= (returnval[1][0] + returnval[1][1])%mod;
		returnval[1][1]= (returnval[1][0] + returnval[1][2])%mod;
		returnval[1][2]= (returnval[1][0])%mod;
		returnval[2][0]= (returnval[2][0] + returnval[2][1])%mod;
		returnval[2][1]= (returnval[2][0] + returnval[2][2])%mod;
		returnval[2][2]= (returnval[2][0])%mod;
		return returnval;
	}
}

ull func(ull n){
	if (n==1)
	{
		return 2;
	}else if(n==2){
		return 4;
	}else if(n==3){
		return 7;
	}
	ull v1[3] = {2,4,7};
	ull **temp = matrixpower(n-3);

	return (temp[0][0]*v1[0] + temp[0][1]*v1[1]+ temp[0][2]*v1[2])%mod;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ull n;
		n = fast_int();
		printf("power2 %lld\n",power2(n) );
		printf("func %lld\n",func(n) );
		printf("%lld\n",power2(n) - func(n) );
	}
}
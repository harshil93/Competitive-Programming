#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define MAX_NUM 1000 // 200

// array will be initialized to 0 being global
int primes[MAX_NUM];

void gen_sieve_primes(void)
{
    for (int p=2; p<MAX_NUM; p++) // for all elements in array
    {
        if(primes[p] == 0) // it is not multiple of any other prime
            primes[p] = 1; // mark it as prime

        // mark all multiples of prime selected above as non primes
        int c=2;
        int mul = p * c;
        for(; mul < MAX_NUM;)
        {
            primes[mul] = -1;
            c++;
            mul = p*c;
        }
    }
}

int main()
{
    gen_sieve_primes();

   int T;
   cin>>T;

   while(T--){
	   	int l,u;

	   	cin>>l>>u;
	   int count=0;
	   	for (int i = l; i <= u; ++i)
	   	{
	   			int sum = 0;
	   		int num = i;
	   		while(num){
	   			sum += num%10;
	   			num = num /10;
	   		}
	   			// PR(sum)
	   		if(primes[sum] == 1){
	   			count++;
	   		}
	   	}


   	cout<<count<<endl;
   }



    return 0;
}

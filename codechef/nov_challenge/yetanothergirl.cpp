#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int,int> 
#define VI vector<int> 
#define VII vector <VI >
#define REP(i,s,e) for(int i=s; i<e; i++)
#define ff first
#define ss second
#define  pb push_back

vector<int> sieveErato(int limit){
	std::vector<int> v;
	std::vector<char> sieve(limit+1,0);
	v.pb(2);
	for (int i = 3; i < limit + 1; i = i+2)
	{
		if(sieve[i]==0) v.pb(i);
		else{
			continue;
		}
		int z=3;
		for (int j = 3*i; j <= limit; j = z*i)
		{
			sieve[j] = 1;
			z= z+2;
		}

	}
	return v;
} 

vector<int> segSieveErato(int l, int r){
	std::vector<int> v;
	int limit = r - l +1;
	std::vector<char> sieve(limit+1,0);
	std::vector<int> psqn = sieveErato(sq(l));
	for (int i = 3; i < limit + 1; i = i+2)
	{
		if(sieve[i]==0) v.pb(i);
		else{
			continue;
		}
		int z=3;
		for (int j = 3*i; j <= limit; j = z*i)
		{
			sieve[j] = 1;
			z= z+2;
		}

	}
	return v;
} 


int main(){
	std::vector<int> primes = sieveErato(30);
	for (int i = 0; i < primes.size(); ++i)
	{
		cout<<primes[i]<<" ";
	}
	cout<<endl;
}

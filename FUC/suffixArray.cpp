#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
struct entry{
		int a,b,pos;	
};
bool cmpEntry(const struct entry x, const struct entry y){
			 return (x.a == y.a)?((x.b<y.b)?(true):(false)):((x.a<y.a)?(true):(false));
};
class suffixArray
{
	entry *L;
	string A;
public:
	int **P;
	int N;
	int steps;
	suffixArray(string str){
		A = str;
		N = str.length();
		steps = (int)ceil(log2(str.length()));
		PR(steps)
		L = new entry[str.length()];
		P = new int*[(int)ceil(log2(str.length())) + 1];
		for (int i = 0; i < ceil(log2(str.length())); ++i)
		{
			P[i] = new int[str.length()];
		}
		buildArray();
	};
	
	
	void buildArray(){
		for (int i = 0; i < N; ++i)
		{
			P[0][i] = A[i] - 'a';
		}

		int step = 1; int count = 1;

		while(count<N){

			for (int i = 0; i < N; ++i)
			{
				L[i].a = P[step-1][i];
				L[i].b = i+count<N?P[step-1][i+count]:-1;
				L[i].pos = i;
			}

			sort(L,L+N,cmpEntry);

			for (int i = 0; i < N; ++i)
			{
				if(i>0 && L[i].a == L[i-1].a && L[i].b == L[i-1].b ){
					P[step][L[i].pos] = P[step][L[i - 1].pos ];
				}else{
					PR(step)
					PR(L[i].pos)
					P[step][L[i].pos]= i;
				}
			}

			step++;
			count = count*2;
		}
	}
	
};

int main(){
	string bobo=  "bobocel";

	suffixArray s(bobo);
	for (int i = 0; i < s.steps; ++i)
	{
		for (int j = 0; j < s.N; ++j)
		{
			cout<<s.P[i][j]<<" ";
		}
		cout<<endl;
	}
}
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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
inline int min(int a,int b, int c, int d){
	int arr[4];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;

	sort(arr,arr+4);

	return arr[0];
}
struct e
{
	int top,left,right,bottom;
	char d;

	e(){
		top =0; left=0;  right=0;  bottom = 0;
	}
};
e matrix[501][501];

int r,c;
int xC[] = {0,1,0,-1};
int yC[] = {1,0,-1, 0};
void preProcess(){

	for (int i = 1; i < r; ++i)
	{
		for (int j = 1; j < c; ++j)
		{
			if(matrix[i][j].d == '^' && matrix[i][j-1].d == '^'){
				matrix[i][j].left = matrix[i][j-1].left + 1;
			}

			if(matrix[i][j].d == '^' && matrix[i-1][j].d == '^'){
				matrix[i][j].top = matrix[i-1][j].top + 1;
			}
		}
	}

	for (int i = r-2; i >= 0; --i)
	{
		for (int j = c-2; j >0; --j)
		{
			if(matrix[i][j].d == '^' && matrix[i][j+1].d == '^'){
				matrix[i][j].right = matrix[i][j+1].right + 1;
			}

			if(matrix[i][j].d == '^' && matrix[i+1][j].d == '^'){
				matrix[i][j].bottom = matrix[i+1][j].bottom + 1;
			}
		}
	}
}

int primeLess[500];
int main(){
	int T;
	cin>>T;
		for (int i = 0; i < 95; ++i)
		{
			primeLess[primes[i]]++;
		}

		for (int i = 1; i < 500; ++i)
		{
			primeLess[i] += primeLess[i-1];
		}

		
	while(T--){

		cin>>r>>c;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>matrix[i][j].d;
				matrix[i][j].top= 0;
				matrix[i][j].left= 0 ;
				matrix[i][j].right =0 ;
				matrix[i][j].bottom =0 ;
			}
			
		}
		preProcess();

		int64_t count =0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if(matrix[i][j].d == '^'){
					int temp =  primeLess[min(matrix[i][j].top,matrix[i][j].left,matrix[i][j].right,matrix[i][j].bottom)];
					count+=temp;
				}
			}
			
		}

		if(r<=4 || c<= 4){
			cout<<0<<endl;
		}else
			cout<<count<<endl;

	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

char pat[10][8] = {"1111111","1111111","1111111","1111111","1111111","1111111","1111111","1111111","1111111","1111111"};
void buildPat()
{
       pat[0][6]='0';
       pat[1][0]='0';
       pat[1][3]='0';
       pat[1][4]='0';
       pat[1][5]='0';
       pat[1][6]='0';
       pat[2][5]='0';
       pat[2][2]='0';
       pat[3][4]='0';
       pat[3][5]='0';
       pat[4][0]='0';
       pat[4][3]='0';
       pat[4][4]='0';
       pat[5][1]='0';
       pat[5][4]='0';
       pat[6][1]='0';
       pat[7][3]='0';
       pat[7][4]='0';
       pat[7][5]='0';
       pat[7][6]='0';
       pat[9][4]='0';
}
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
}
unsigned int d[10];
unsigned int inp[101];
int main(){
	buildPat();
	for (int i = 0; i < 10; ++i)
	{
		d[i] = 0;
		for (int j = 0; j <= 6; ++j)
		{
			d[i] = d[i]<<1;
			d[i] = d[i] | (pat[i][j] - '0');

		}
	}
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=-1;
		int startDig;
		for (int i = 0; i < n; ++i)
		{
			string str ; cin>>str;
			inp[i] = 0;
			for (int j = 0; j <= 6; ++j)
			{
				inp[i] = inp[i]<<1;
				inp[i] = inp[i] | (str[j] - '0');
			}
		}

		for (int i = 0; i < 1<<7; ++i)
		{
			bool isPos = 1;
			for (int j = 0; j < n; ++j)
			{
				if(inp[j]&i){
					isPos = 0;
					break;
				}
			}
			if(!isPos) continue;

			for (int j = 9; j >=0 ; j--)
			{
				isPos = 1;
				int curDig = j;
				for (int k = 0; k < n; ++k)
				{
					if( d[curDig]&~i != inp[k]){
						isPos = 0;
						break;
					}
					curDig--;
					if(curDig<0) curDig = 9;
				}
				if(isPos){

					for (int k = 0; k < n; ++k)
					{
						if(d[curDig] & ~inp[k]){
							isPos = 0;
							break;
						}
					}
					if(isPos){
						ans = curDig;
						startDig = j;
						break;
					}
					
				}
			}
			if(isPos) break;

		}
		if(ans>=0)
			cout<<pat[ans]<<" : "<<ans<<" : "<<startDig<<endl;
		else 
			cout<<"Error"<<endl;

	}







}
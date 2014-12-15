#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;
typedef unsigned long long int ull;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( auto i=a.begin();i!=a.end();i++)

#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod
#define gc getchar_unlocked

int main()
{
    ios_base::sync_with_stdio(0);
    long n;
    int l,r,ql,qr;
    cin>>n>>l>>r>>ql>>qr;
    int w[n];
    for(long i=0;i<n;i++) cin>>w[i];
    int lst=-1;
    long tot=0,cmin;

    if(n==1){
		if(l<r){
			cout<<l*w[0]<<endl;
			return 0;
		}else{
			cout<<r*w[0]<<endl;
			return 0;
		}
	}
	
    for(long i=0,j=n-1;i<=j;)
    {
        if(lst==-1)
        {
            if(w[j]*l+ql<w[i]*r+qr)
            {
                cmin=w[i]*l;
                i++;
                lst=0;
            }
            else
            {
                cmin=w[j]*r;
                j--;
                lst=1;
            }
        }
        else if(lst==0)
        {
            if((w[j]*l)+ql<w[j]*r)
            {
                cmin=w[i]*l+ql;
                lst=0;
                i++;
            }
            else
            {
                cmin=w[j]*r;
                lst=1;
                j--;
            }
        }
        else
        {
            if(w[i]*l<w[i]*r+qr)
            {
                cmin=w[i]*l;
                i++;
                lst=0;
            }
            else
            {
                cmin=w[j]*r+qr;
                j--;
                lst=1;
            }
        }
        tot+=cmin;
    }

    cout<<tot<<endl;
    return 0;
}
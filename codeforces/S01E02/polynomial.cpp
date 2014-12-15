#include <iostream>
#include <string>
#include <climits>
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

int main(int argc, char const *argv[])
{
    int deg,x, count=0;;
    int coeff[110];
    while(1)
    {
        count++;
        int plus=0, ans=0, xans=0;
        scanf("%d",&deg);
        scanf("%d",&coeff[0]);

        if (!deg && !coeff[0]) return 0;
        
        for (int i = 1; i < deg+1; ++i)
        {
            scanf("%d",&coeff[i]);
            if (coeff[i]!=0)
            {
                plus++;
            }
        }   
        scanf("%d",&x);
        for (int i = 0; i < deg+1; ++i)
        {
            xans+=pow(x,i)*coeff[deg-i];
        }
        ans=plus + 1 + deg-1 + deg ;
        for (int i = 1; i < deg+1; ++i)
        {
            while(coeff[i]!=0)
            {
                ans++;
                coeff[i]/=10;
            }
        }
        if (deg==0)
        {
            while(coeff[0]!=0)
            {
                ans++;
                coeff[0]/=10;
            }
            ans++;
        }
        printf("Polynomial %d: %d %d\n",count, xans, ans ); 
    }
    return 0;
}


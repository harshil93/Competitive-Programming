#include <cstdio>
#include <string>
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
#include <functional>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,n) for( int i =0 ; i < n ; i++ )

#define MAX 1004

int a[MAX],b[MAX][MAX],c[MAX][MAX];

struct pt
{
    int cost;
    int pos;
};

bool ptcmp(pt p,pt q)
{
    return (p.cost<q.cost) || (p.cost==q.cost && p.pos<q.pos);
}

pt pt[MAX];

int main()
{
    int t,n,m,k,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]--;
            
        }
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&b[i][j]);
              
            } 
        }
        for(int i=0;i<n;i++)
        {
            pt[i].cost = INT_MIN;
            pt[i].pos = i;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&c[i][j]);
                if(j!=a[i]) pt[i].cost = max(pt[i].cost,b[i][j]-c[i][j]);
               
            }
            pt[i].cost -= b[i][a[i]];
            
        }
        sort(pt,pt+n,ptcmp);
        ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            int j = pt[i].pos;
            ans += b[j][a[j]];
            if(k && pt[i].cost>0)
            {
                ans += pt[i].cost;
                k--;
            }
        }
        printf("%d\n",ans );
    }
    return 0;
}
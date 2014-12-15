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
#include <functional>
#include <cassert>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int64_t> vi; 
typedef vector<vi> vvi; 
typedef pair<int64_t,int64_t> ii; 
#define sz(a) int64_t((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,n) for( int64_t i =0 ; i < n ; i++ )
#define MOD 1000000007
struct matrix
{
    int64_t mat[2][2];
};

int64_t gmat[2][2];

matrix expe(matrix m, int64_t n){
    
    assert(n!=0);

    if(n==1){
        matrix s;
        s.mat[0][0] = 1;
        s.mat[0][1] = -1;
        s.mat[1][0] = 1;
        s.mat[1][1] = 0;
       
    return s;
    }

    if(n%2 == 0){
        matrix m1 = expe(m,n/2);
        int64_t t1 = m1.mat[0][0]*m1.mat[0][0] + m1.mat[0][1]*m1.mat[1][0];
        int64_t t2 = m1.mat[0][0]*m1.mat[0][1] + m1.mat[0][1]*m1.mat[1][1];
        int64_t t3 = m1.mat[1][0]*m1.mat[0][0] + m1.mat[1][1]*m1.mat[1][0];
        int64_t t4 = m1.mat[1][0]*m1.mat[0][1] + m1.mat[1][1]*m1.mat[1][1];
        m1.mat[0][0] = t1%MOD;
        m1.mat[0][1] = t2%MOD;
        m1.mat[1][0] = t3%MOD;
        m1.mat[1][1] = t4%MOD;

     
        
        return m1;
    }else{
        matrix m1 = expe(m,n/2);
        int64_t t1 = m1.mat[0][0]*m1.mat[0][0] + m1.mat[0][1]*m1.mat[1][0];
        int64_t t2 = m1.mat[0][0]*m1.mat[0][1] + m1.mat[0][1]*m1.mat[1][1];
        int64_t t3 = m1.mat[1][0]*m1.mat[0][0] + m1.mat[1][1]*m1.mat[1][0];
        int64_t t4 = m1.mat[1][0]*m1.mat[0][1] + m1.mat[1][1]*m1.mat[1][1];
        m1.mat[0][0] = t1%MOD;
        m1.mat[0][1] = t2%MOD;
        m1.mat[1][0] = t3%MOD;
        m1.mat[1][1] = t4%MOD;
        

        t1 = m1.mat[0][0]*gmat[0][0] + m1.mat[0][1]*gmat[1][0];
        t2 = m1.mat[0][0]*gmat[0][1] + m1.mat[0][1]*gmat[1][1];
        t3 = m1.mat[1][0]*gmat[0][0] + m1.mat[1][1]*gmat[1][0];
        t4 = m1.mat[1][0]*gmat[0][1] + m1.mat[1][1]*gmat[1][1];

        
        m1.mat[0][0] = t1%MOD;
        m1.mat[0][1] = t2%MOD;
        m1.mat[1][0] = t3%MOD;
        m1.mat[1][1] = t4%MOD;
        
        return m1;

    }
}

int main(){
    matrix s;
    gmat[0][0] = 1;
    gmat[0][1] = -1;
    gmat[1][0] = 1;
    gmat[1][1] = 0;

    s.mat[0][0] = 1;
    s.mat[0][1] = -1;
    s.mat[1][0] = 1;
    s.mat[1][1] = 0;

    int64_t x,y,n; cin>>x>>y>>n;
    int64_t ans;
    if(n==1){
        ans = x;
    }else if(n==2){
        ans = y;

    }else{
        int64_t power = n-2;
        matrix m1 = expe(s,power);
        ans = m1.mat[0][0]*y + m1.mat[0][1]*x;
    }

    if(ans < 0){
        ans += MOD;
        ans = ans%MOD;
    }

    cout<<ans<<endl;


}
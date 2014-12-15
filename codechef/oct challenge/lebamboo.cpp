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


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a,b;
        int suma = 0, sumb=0;
        for(int i=0; i<n;i++){
            int t; cin>>t; a.push_back(t);
            suma+=t;
        }
        int issame = 1;
        int maxdiff = 0;
        for(int i=0; i<n;i++){
            int t; cin>>t; b.push_back(t);
            if(t!=a[i]) issame=0;
            maxdiff = max(maxdiff,abs(t-a[i]));
            sumb+=t;
        }
        if(issame) cout<<0<<endl;
        else{
            int diff = sumb - suma;

            if( n>2 ){

                if(diff<=0 || maxdiff>diff){
                    cout<<-1<<endl;
                }else{
                    if(diff%(n-2)==0)
                        cout<<diff/(n-2)<<endl;
                    else
                        cout<<-1<<endl;
                }

            }else if(n == 1){
                if(suma >= sumb){
                    cout<<suma-sumb<<endl;
                }
                else
                    cout<<-1<<endl;
            } else if(n==2){
                if(suma == sumb)
                {
                    int ans = a[0] - b[0];
                    if(ans<0) ans = -ans;
                    cout<<ans<<endl;
                }
                else cout<<-1<<endl;
            }




    }

    }
    return 0;
}

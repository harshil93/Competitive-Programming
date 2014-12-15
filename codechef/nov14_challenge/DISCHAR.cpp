#include <bits/stdc++.h>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> II; 
#define SZ(a) int((a).size()) 
#define PB push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FOR(i,n) for( int i =0 ; i < n ; i++ )
#define ll long long
#define FF first
#define SS second

int main(){
	int T;
	cin>>T;
	bool freq[256];
	while(T--){
		memset(freq,0,sizeof(freq));
		int i=0,j=0;
		string a; cin>>a;
		int ans = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if(!freq[a[i]]) ans++;
			freq[a[i]] = true;
		}
		cout<<ans<<endl;
	}
}
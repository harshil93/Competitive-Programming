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
	while(T--){
		string a; cin>>a;
		int i=0,j = a.size()-1;
		string b = a;
		bool deleted = false;
		int ans = 2;
		while(i<=j){
			if(a[i] == a[j]){
				i++;j--;
			}else{
				a[i] = '1';
				b[j] = '1';
				break;
			}
		}

		i=0;j=a.size()-1;
		while(i<=j){
			if(a[i] == a[j]){
				i++;j--;
			}else if(a[i] == '1'){
				i++;
			}else{
				ans--;
				break;
			}
		}
		i=0;j=a.size()-1;
		while(i<=j){
			if(b[i] == b[j]){
				i++;j--;
			}else if(b[j] == '1'){
				j--;
			}else{
				ans--;
				break;
			}
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
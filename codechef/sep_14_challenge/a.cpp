#include <iostream>

using namespace std;
#define MOD (1000000007)

int main(){
	int t;
	cin>>t;

	while(t--){
		string s;cin>>s;
		
		long long ans = 1;
		
		for (int i = 0; i < s.size(); ++i)
		{
			if( i%2 ){
				if(s[i] == 'l')
					ans = (ans*2 - 1)%MOD;
				else
					ans = ((ans*2) + 1)%MOD;
			}else{
				if(s[i] == 'l')
					ans = (ans*2)%MOD;
				else
					ans = ((ans*2) + 2)%MOD;
			}
		}

		cout<<ans<<endl;
	}
}

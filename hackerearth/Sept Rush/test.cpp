#include "iostream"
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		string m;
		cin>>m;
		int ans=0;
		for (int i = 0; i < m.size(); ++i)
		{
			for (int j = i; j < m.size(); ++j)
			{
				int flag = 0;
				for (int k = i; k <=j; ++k)
				{
					if(m[k]=='a' || m[k]=='z'){ ans++; break; }
				}
			}
		}

		cout<<ans<<endl;
	}
}
#include "iostream"
#include "stdint.h"
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		string m;
		cin>>m;
		int64_t ans=0;
		int64_t prevCnt=1;

		for (int i = 0; i < m.size(); ++i)
		{
			if(m[i]=='a' || m[i]=='z'){
				ans += (m.size() - i)*prevCnt;
				prevCnt = 1;
			}else{
				prevCnt++;
			}
		}
			cout<<ans<<endl;
	}
	return 0;
}
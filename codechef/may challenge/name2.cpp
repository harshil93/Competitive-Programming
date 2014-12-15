#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
// unsigned int LCSmatrix[25003][25003];
int main(){
	int t;
	string m,n,small,large;
	cin>>t;
	while(t--){
		cin>>m>>n;
		small = m.length()<n.length()?m:n;
		large = m.length()>=n.length()?m:n;
		int pos = -1;
		bool ok = true;
		pos = -1;
		ok = true;
		// if (small.length()==large.length())	
		// {
		// 	cout<<"into";
		// 	cout<<small<<endl;
		// 	cout<<large<<endl;
		// 	for (int i = 0; ok && i < small.length(); i++)
		// 	{
		// 		if (small[i]!=large[i])
		// 		{
		// 			ok=false;
		// 		}
		// 	}
		// }else{
			for (int i = 0 ; ok && i != small.size() ; i++) {
				ok = (pos = large.find(small[i], pos+1)) != string::npos;
			}
		// }
		cout << (ok ? "YES" : "NO") << endl;


	}
	return 0;
}
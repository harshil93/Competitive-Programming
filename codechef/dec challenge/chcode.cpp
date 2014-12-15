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
#include <cctype>
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

struct p
{
	char c;int f;
};

bool comp(p a, p b){
	if(a.f == b.f){
		return a.c < b.c;
	}else{
		return a.f<b.f;
	}
}

int main(){
	int T;cin>>T;
	while(T--){

		string freq;
		cin>>freq;
		
		char tx[150002];
		getchar();
		cin.getline(tx,150001,'\n');
		string text(tx);

		p arr[26];
		for (int i = 0; i < 26; ++i)
		{
			arr[i].c = i + 'a';
			arr[i].f = 0;
		}
		for (int i = 0; i < text.size(); ++i)
		{
			char c = tolower(text[i]);
			
			if( 'a'<= c && c<='z')
				arr[c - 'a'].f++;
		}
		
		

		sort(arr, arr+26, comp);
		char decry[27];
		for (int i = 0; i < 26; ++i)
		{
			decry[i] = arr[i].c;
		}
		decry[26]='\0';
		map<char, char> mp;

		for (int i = 0; i < 26; ++i)
		{
			mp[decry[i]] = freq[i];
		}
		string ans = text;
		for (int i = 0; i < text.size(); ++i)
		{
			if('a'<= text[i] && 'z'>= text[i]){
				ans[i] = mp[text[i]];
			}else if('A'<= text[i] && 'Z'>= text[i]){
				ans[i] = mp[tolower(text[i])] - 'a' + 'A';
			}
		}
		cout<<ans<<endl;
	}
}
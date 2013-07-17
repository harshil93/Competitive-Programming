#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
inline int fast_int()
{
int n=0;
int ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

struct song
{
	int64_t b,l;
};
bool cmpFnB(struct song s1, struct song s2){
	return s1.b<s2.b;
}

bool cmpFnL(struct song s1, struct song s2){
	return s1.l<s2.l;
}
int main(){
	int t;
	cin>>t;
	struct song s[100005];
	
	while(t--){
		vector <struct song> min_len, rem;
		int64_t n = fast_int();
		for (int i = 0; i < n; ++i)
		{
			s[i].b = fast_int();
			s[i].l = fast_int();
		}

		std:sort(s,s+n,cmpFnB);
		int64_t cur_band = s[0].b;
		int64_t cur_band_min_len = s[0].l;
		for (int i = 1; i < n; ++i)
		{
			if(cur_band == s[i].b && cur_band_min_len>s[i].l){
				struct song temp;
				temp.b = cur_band;temp.l = cur_band_min_len;
				rem.push_back(temp);
				cur_band_min_len = s[i].l;

			}else if(cur_band != s[i].b){
				struct song temp; temp.b = cur_band; temp.l = cur_band_min_len;
				min_len.push_back(temp);
				cur_band = s[i].b;
				cur_band_min_len = s[i].l;
			}else{
				rem.push_back(s[i]);
			}
		}
		struct song temp; temp.b = cur_band; temp.l =cur_band_min_len;
		min_len.push_back(temp);
		std::sort(min_len.begin(),min_len.end(),cmpFnL);
		int64_t sweetness=0;
		for (int i = 1; i <= min_len.size(); ++i)
		{
			sweetness+=min_len[i-1].l * i;
		}
		int64_t no_of_distinct_bands = min_len.size();
		for (int i = 0; i < rem.size(); ++i)
		{
			sweetness+= rem[i].l*no_of_distinct_bands;
		}

		cout<<sweetness<<endl;
	}
	return 0;
}
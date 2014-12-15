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
#define mod(n) (n > 0 ? n : -1*n)
struct bomb
{
	int x,  y, state;
	bomb(){
		state = 1;
	}
};

bool cmpX(const bomb p1,const bomb p2){
   	return (mod(p2.x) + mod(p2.y) > mod(p1.x) + mod(p1.y));    	
 }

void destroy(int x, int y){
	if(x!=0){
		char r = 'R';
		char l = 'L';
		printf("1 %d ",abs(x) );
		// cout<<"1 "<<abs(x)<<" ";
		if(x>0){
			printf("%c\n", r);
		}else{
			printf("%c\n",l );
		}
	}

	if(y!=0){
		char u = 'U';
		char d = 'D';
		// cout<<"1 "<<abs(y)<<" ";
		printf("1 %d ", abs(y));
		if(y>0){
			printf("%c\n",u );
		}else{
			printf("%c\n",d );
		}
	}
	printf("2\n");
	// cout<<2<<endl;
	if(y!=0){
		char u = 'U';
		char d = 'D';
		// cout<<"1 "<<abs(y)<<" ";
		printf("1 %d ",abs(y) );
		if(y>0){
			printf("%c\n",d );
		}else{
			printf("%c\n",u );
		}
	}
	if(x!=0){
		char r = 'R';
		char l = 'L';
		// cout<<"1 "<<abs(x)<<" ";
		printf("1 %d ",abs(x) );
		if(x>0){
			printf("%c\n", l);
		}else{
			printf("%c\n", r);
		}
	}
	printf("3\n");
	// cout<<3<<endl;
}

int main(){
	int n;

	cin>>n;
	bomb s[100000];
	int64_t ans = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",&s[i].x, &s[i].y);
		if(s[i].x!=0) ans = ans +2;
		if(s[i].y!=0) ans = ans +2;
	}
	ans = ans + 2*n;
	sort(s,s+n,cmpX);
	cout<<ans<<endl;
	for (int i = 0; i <n; ++i)
	{
		// cout<<s[i].x<<" "<<s[i].y<<endl;
		destroy(s[i].x,s[i].y);
	}
}
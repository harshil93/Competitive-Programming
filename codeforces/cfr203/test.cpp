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
    
    
    int main(){
    	int n;
    
    	cin>>n;
    	bomb s[100000];
    	for (int i = 0; i < n; ++i)
    	{
    		scanf("%d %d",&s[i].x, &s[i].y);
    	}
    	sort(s,s+n,cmpX);
    }    
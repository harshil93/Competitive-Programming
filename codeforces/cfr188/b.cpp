#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";


int main(){
	char str[1000003];
	scanf("%s",str);
	int64_t len = strlen(str);
	int64_t no_of_heavy=0;
	int64_t no_of_metal=0;
	int64_t ans=0;
	for (int64_t i = 0; i <=len-5; ++i)
	{
		if (strncmp(str+i,"heavy",5)==0)
		{
			no_of_heavy++;
		}else
		if (strncmp(str+i,"metal",5)==0)
		{
			no_of_metal++;
			ans = ans + no_of_heavy;
		}
	}

	cout<<ans<<endl;
}
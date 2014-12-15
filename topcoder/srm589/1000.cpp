#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class FlippingBitsDiv2 {
public:
	int getmin(vector <string> S, int M) {
		string s="";

		for (int i = 0; i < S.size(); ++i)
		{
			s+=S[i];
		}

		int prefix[s.size()][2];
		int suffix[s.size()][2];

		for (int i = 0; i < s.size(); ++i)
		{
			prefix[i][0] = 0;
			prefix[i][1] = 0;
			suffix[i][0] = 0;
			suffix[i][1] = 0;
		}

		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '0'){
				prefix[i][0]++;
			}else{
				prefix[i][1]++;
			}
		}

		for (int i = 1; i < s.size(); ++i)
		{
			prefix[i][0] += prefix[i-1][0];
			prefix[i][1] += prefix[i-1][1];
		}


		for (int i = s.size() - 1; i >=0; --i)
		{
			if(s[i] == '0'){
				suffix[i][0]++;
			}else{
				suffix[i][1]++;
			}
		}

		for (int i = s.size() - 2; i >=0; --i)
		{
			suffix[i][0] += suffix[i+1][0];
			suffix[i][1] += suffix[i+1][1];
		}
		int max = 0;
		int max_index =0;
		for (int i = 0; i < s.size(); i=i+M)
		{
			if( (prefix[i][0] -  prefix[i][1] ) > max){
				max = prefix[i][0] -  prefix[i][1];
				max_index = i;
			}
		}

		for (int i = 0; i < s.size(); i=i+M)
		{
			if( (prefix[i][s.size() - 1] -  prefix[i][1] ) > max){
				max = prefix[i][0] -  prefix[i][1];
				max_index = i;
			}
		}



		return min;
	}
};


int main(int argc, char const *argv[])
{
	
	return 0;
}
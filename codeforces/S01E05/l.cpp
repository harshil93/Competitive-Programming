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


int main(){
	int n;
	cin>>n;

	string a[21][2];
	std::map<string, int> m;
	getchar();
	for (int i = 0; i < n; ++i)
	{
		  std::getline (std::cin,a[i][0]);
		  std::getline (std::cin,a[i][1]);

		  // PR(a[i][0])
		  // PR(a[i][1])
	}

	int m_;

	cin>>m_;
	getchar();
	for (int i = 0; i < m_; ++i)
	{
		string temp;
		std::getline(std::cin,temp);
		m[temp]++;
	}
	unsigned currentMax = 0;
	string arg_max;
	std::map<string,int>::iterator it;
	// PR(m[a[0][0]])
	bool tie = false;
	for(it = m.begin(); it != m.end(); ++it ){
		    if (it ->second > currentMax) {
	        	arg_max = it->first;
	        	currentMax = it->second;
	        	tie = false;
	    	}else if(it->second == currentMax){
	    		tie = true;
	    	}
	}

	if(tie)
		cout<<"tie"<<endl;
	else
		for (int i = 0; i < n; ++i)
		{
			if(arg_max == a[i][0]){
				cout<<a[i][1]<<endl;
				break;
			}
		}

		return 0;

}
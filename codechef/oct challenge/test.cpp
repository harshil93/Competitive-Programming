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
	int myints[] = {1,3,5,7,8};
	std::vector<int> v(myints,myints+5);

	std::vector<int>::iterator low,up;

	low = lower_bound(v.begin(),v.end(),2);
	up = upper_bound(v.begin(),v.end(),3);
	std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  	std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
}
#include "iostream"
#include "algorithm"
#include "cstdio"
#include "vector"
using namespace std;

int main(){
	int myints[] = {10,20,30,5,15};
  	vector<int> v1(myints,myints+5);
  	vector<int> v2(myints,myints+5);
  	make_heap (v1.begin(),v1.end());
  	make_heap (v2.begin(),v2.end(),comp);

  	// cout<< pop_heap(v1.begin(),v1.end()) <<endl;
  	// cout<< pop_heap(v2.begin(),v2.end()) <<endl;
}

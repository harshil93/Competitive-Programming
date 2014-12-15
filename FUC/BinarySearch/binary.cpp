#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int binarySearchGreater(std::vector<int> &v,int s,int e,int val){
	int mid = s + (e-s)/2;
	if(v[mid]== val){
		return mid+1;
	}
	if(s==e){
		if(v[s] > val){
			return s;
		}else{
			return s+1;
		}
	}
	if(v[mid] > val){
		if(s<=mid-1)
			return binarySearchGreater(v,s,mid-1,val);
		else
			return s;
	}else{
		if(mid+1<=e)
			return binarySearchGreater(v,mid+1,e,val);
		else
			return e+1;
	}
}
int main(){
	int arr[] = {1,3,4,8,9,10};
	std::vector<int> v(arr,arr+6);
	while(1){
	int val ; cin>>val;
	cout<<"ans = ";
	cout<< binarySearchGreater(v,0,v.size() - 1,val)<<endl;
	}
}
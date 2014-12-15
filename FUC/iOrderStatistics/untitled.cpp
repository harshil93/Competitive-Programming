/*
* Working for array of size 10, some corner cases when n%5 !=-0 are missing.
* 
* 
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class iOrderStatistics
{

public:
	int partition(vector<int> &arr,int pivot_pos){
		int i=-1;
		int n = arr.size();
		int temp = arr[pivot_pos];
		arr[pivot_pos] = arr[n-1];
		arr[n-1] = temp;
		int pivot = arr[n-1];
		for (int j = 0; j < n-1; ++j)
		{
			if(arr[j]<pivot){
				i++;
				swap(arr,i,j);
			}
		}
		swap(arr,i+1,n-1);
		return i+1;
	}
	void swap(vector<int> &arr,int i,int j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	int select(std::vector<int> &arr, int s, int e,int k){
		if(e-s+1 <=5){
			sort(arr.begin() + s,arr.begin() + e);
			// PR(arr[s+k])
			return s+k;
		}

		int no_of_partitions = (e-s+1)/5;
		int sizeoflastpartition = (e-s+1)%5;
		int i=0;
		for (i = 0; i < no_of_partitions; ++i)
		{
			sort(arr.begin() + 5*i,arr.begin() + 5*i+5);
		}
		for (int i = 0; i < no_of_partitions; ++i)
		{
			swap(arr,i,5*i+2);
		}

		if(sizeoflastpartition){
			sort(arr.begin() + 5*i,arr.end());
			int medpos = sizeoflastpartition%2 ? sizeoflastpartition/2 : sizeoflastpartition/2 + 1;
			swap(arr,medpos,i);
			no_of_partitions++;
		}
		int medpos = no_of_partitions%2 ? no_of_partitions/2 : no_of_partitions/2 - 1;
		int med_of_med_pos = select(arr,0,no_of_partitions-1,medpos);
		int q = partition(arr,med_of_med_pos);
		// int q = 2;
	
		if(q==k){
			// PR(arr[q])
			return arr[q];
		}
		if(k<q){
			return select(arr,s,q-1,k);
		}else{
			return select(arr,q,e,k-q);
		}
	}
};
int main(){
	iOrderStatistics S;
	int arr[] = {12,65,2,46,5,842,6,4,34,3};
	std::vector<int> v(arr,arr+10);
	sort(arr,arr+8);
	for (int i = 0; i < 10; ++i)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	cout<<S.select(v,0,v.size()-1,0)<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<"\t";
	}
	cout<<endl;

}
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class Heap
{
private:
	std::vector<int> A;


	public:
		void buildHeap(std::vector<int> v){
			for (int i = 0; i < v.size(); ++i)
			{
				A.push_back(v[i]);
			}
			
			for (int i = v.size()/2 -1; i >= 0; --i)
			{
				 maxHeapify(i);
			}
		}

		int left(int i){
			return 2*(i+1) -1 ;
		}
		int right(int i){
			return 2*(i+1);
		}

		int parent(int i){
			return (i-1)/2;
		}

		void swap(int i,int j){
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}

		void maxHeapify(int i){
			cout<<i<<endl;
			int l = left(i);
			int r = right(i);
			int largest = i;
			if(l < A.size() && A[l] > A[i]){
				largest = l;
			}

			if(r < A.size() && A[r] > A[largest]){
				largest = r;
			}

			if(largest != i){
				swap(i,largest);
				maxHeapify(largest);
			}
			return;
		}

		int extractMax(){
			int retVal = A[0];
			swap(0,A.size()-1);
			A.pop_back();
			maxHeapify(0);
			return retVal;
		}

		void printHeap(){
			for (int i = 0; i < A.size(); ++i)
			{
				cout<<A[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	Heap h;
	int arr[] = {5,6,751,13,47,45};
	std::vector<int> v(arr,arr+6);
	h.buildHeap(v);
	h.printHeap();
	return 0;
}
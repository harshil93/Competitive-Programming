#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;


class adjListNode{
	int dest,weight;
	adjListNode *next;

	public:
	adjListNode(int _dest, int _weight){
		dest = _dest; 
		weight = _weight;
		next = NULL;
	};
	void setDest(int _dest){
		dest = _dest;
	};

	void setWeight(int _weight){
		weight = _weight;
	};

	void setNext(adjListNode *ptr){
		next = ptr;
	}

	int getDest(){
		return dest;
	};

	int getWeight(){
		return weight;
	};

	adjListNode *getNext(){
		return next;
	}
};



class adjList
{
	public:
	adjListNode *head;
};

class graph{
	int n;
	adjList *array;

public:
	graph(int _n){
		n=_n;
		array = new adjList[_n];
		for (int i = 0; i < _n; ++i)
		{
			array[i].head = NULL;
		}
	};

	void addEdge(int _src, int _dest,int _weight){
		adjListNode *newNode = new adjListNode(_dest,_weight);
		newNode->setNext(array[_src].head);
		array[_src].head = newNode;

		newNode = new adjListNode(_src,_weight);
		newNode->setNext(array[_dest].head);
		array[_dest].head = newNode;
	}
};


class minHeap{
private:
	std::vector<int> A;
	int leftChild(int i){
		return 2*i+1;
	};
	int rightChild(int i){
		return 2*i+2;
	};
	int parent(int i){
		return (i-1)/2;
	};
	void swap(int i, int j){
		int temp = A[i];
		A[i]=A[j];
		A[j] = temp;
	};
	void heapify(int i){
		int l = leftChild(i);
		int r= rightChild(i);
		int smallest=-1;
		if (l<A.size() && A[l]<A[i])
		{
			smallest = l;
		}else{
			smallest = i;
		}

		if (r<A.size() && A[r]<A[smallest])
		{
			smallest = r;
		}

		if (smallest!=i)
		{
			swap(i,smallest);
			heapify(smallest);
		}
	};
public:
	void buildHeap(vector<int> v){

		for (int i = 0; i < v.size(); ++i)
		{
			A.push_back(v[i]);
		}

		for (int i = A.size()/2; i >=0; --i)
		{
			heapify(i);
		}
		// printf("size of a %d\n",A.size() );
	}

	void printHeap(){
		for (int i = 0; i < A.size(); ++i)
		{
			printf("%d\t", A[i]);
		}
		printf("\n");
	};

	int extractMin(){
		int temp = A[0];
		swap(0,A.size());
		A.pop_back();
		heapify(0);
		return temp;
	}

};

int main(){
	int myints[]= {12,332,3,4,43,6,54,8};

	std::vector<int> v(myints, myints+8);

	minHeap M;

	M.buildHeap(v);
	M.printHeap();

	for (int i = 0; i < 4; ++i)
	{
		printf("Min is %d \n",M.extractMin() );
	}
	return 0;
}
/*
* Range Minimum Query - Segment Trees
* O(n) - Preprocessing , O(logn) - Query, O(logn) - update
* By - h43k3r
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class RMQmin
{
private:
	int *M;
	int l;
	std::vector<int> A;
public:

	void inilialize(std::vector<int> &v){
		A=v;
		int logval = (int)(log(v.size())/log(2)) + 1;
		int size = 1;
		for (int i = 0; i < logval; ++i)
		{
			size *=2;
		}
		l = 2*size - 1;
		M = new int[2*size];
		memset(M,-1,2*size*sizeof(M));
		M[0] = constructST(0,v.size() - 1,0);
	}
	
	int constructST(int m, int n,int pos){
		// cout<<"m = "<<m<<" n ="<<n<<" pos="<<pos<<endl;
		if(m==n){
			M[pos] = m;
			return m;
		}else{
			int left = constructST(m,(m+n)/2, 2*(pos+1) - 1);
			int right = constructST((m+n)/2 +1 , n , 2*(pos+1) );
			M[2*(pos+1) - 1] = left;
			M[2*(pos+1)] = right;
			// PR(left);
			// PR(right);
			return A[left]<A[right]?left:right; 
		}
	}

	int query(int a, int b){
		return queryInternal(a,b,0,A.size() - 1,0);
	}

	int queryInternal(int a,int b, int m, int n,int pos){
		int retVal;

		// cout<<a<<" "<<b<<" "<<m<<" "<<n<<" "<<pos<<endl;
		if(m==a && n==b){
			return M[pos];
		}
		if(m<=a && b<=(m+n)/2){
			retVal = queryInternal(a,b,m,(m+n)/2, 2*(pos+1) - 1);
		}else if((m+n)/2 < a && b<=n ){
			retVal = queryInternal(a,b,(m+n)/2 + 1,n,2*(pos+1));
		}else{
			int retVal1 = queryInternal(a,(m+n)/2,m,(m+n)/2,2*(pos+1) - 1);
			int retVal2 = queryInternal((m+n)/2+1,b,(m+n)/2 +1, n,2*(pos+1));
			retVal = A[retVal1]<A[retVal2]?retVal1:retVal2;
		}
	}

	void printTree(){
		for (int i = 0; i < l; ++i)
		{
			cout<<i<<" >> "<<M[i]<<endl;
		}
	}

	void update(int pos, int val){
		
		updateUtil(0,A.size()-1,pos,val,0);
	}

	void updateUtil(int m,int n,int pos,int val, int index){
		if(m==n && n==pos){
			A[pos]=val;
			return;
		}
		if(m<=pos && pos<=(m+n)/2){
			updateUtil(m,(m+n)/2,pos,val,2*(index+1) - 1);

		}else{
			updateUtil((m+n)/2 +1, n,pos,val,2*(index+1));
		}

		M[index] = A[M[2*(index+1) - 1]] < A[M[2*(index+1) ]] ? M[2*(index+1) -1]:M[2*(index+1)];
	}


};

int main(){
	int arr[] = {5,4,32,1,6,2};
	std::vector<int> v(arr,arr+6);
	RMQmin segTree;
	segTree.inilialize(v);
	segTree.printTree();
	
	cout<<segTree.query(0,5)<<endl;
	cout<<"@@@@@@@@@@@@@@@@@@@"<<endl;
	segTree.update(3,1);
	segTree.printTree();
	
	cout<<segTree.query(0,5)<<endl;
}
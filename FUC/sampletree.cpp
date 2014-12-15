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
struct node
{
	node *left, *right;
	int data;

	node(){
		left = NULL;
		right = NULL;
	}
};

int MAX;
int getHeight(node *root){
	if(root==NULL){
		return 0;
	}
	int lht = getHeight(root->left);
	int rht = getHeight(root->right);
	if(MAX< lht + rht + 1){
		MAX = lht + rht + 1;
	}
	return lht>rht? (lht +1 ): (rht + 1);
}
int main(){
	node *arr[10];

	for (int i = 0; i < 10; ++i)
	{
		arr[i] = new node();
		arr[i]->data = i;
	}
	arr[0]->left = arr [1];
	arr[0]->right = arr [2];
	arr[1]->left = arr[3];
	arr[1]->right = arr[4];
	arr[4]->right = arr[5];
	arr[5]->left = arr[6];
	arr[2]->right = arr[7];
	arr[2]->left  = arr[8];
	node* root = arr[0];

	cout<<getHeight(root)<<endl;



}
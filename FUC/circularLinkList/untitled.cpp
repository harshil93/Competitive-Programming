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
typedef int T;
typedef struct node
{
	T data;
	node *next;
	node *prev;
} node;
class circularLinkList
{

public:
	node *head;
	node *tail;
	circularLinkList(){
		head = NULL;
		tail = NULL;
	}
	void insertNode(int val){
		if(head==NULL && tail==NULL){
			node *newnode = new node();
			newnode->data = val;
			newnode->next = head;
			newnode->prev = head;
			head = newnode;
			tail = NULL;
		}else if(tail==NULL){
			node *newnode = new node();
			newnode->data = val;
			newnode->next = head;
			newnode->prev = head;
			head->next = newnode;
			tail = newnode;
		}else{
			node *newnode = new node();
			newnode->data = val;
			newnode->next = head;
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
		}

	}
	void delNode(node *nodeToDel){
		nodeToDel->prev->next = nodeToDel->next;
		nodeToDel->next->prev = nodeToDel->prev;
		if(nodeToDel == head){
			if(nodeToDel->next == head)
				head = NULL;
			else
				head = nodeToDel->next;
				tail = head->prev;
		}
	}
};

int main(){

}
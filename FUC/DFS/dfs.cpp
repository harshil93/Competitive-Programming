




















\/*CODE NOT COMPLETE*/
#include <iostream>
#include <list>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

list <int> *createAdjList(int size){	
	list <int> *nodes;
	getchar();
	nodes=new list<int>[size+1];

	for (int i = 1; i < size+1; ++i)
	{	int tempData;
		do{
			cout<<"Enter the nodes to which "<<i<<" is connected"<<endl;
			cin>>tempData;
			nodes[i].push_back(tempData);
		}
		while(getchar()!='\n');
	}
	return nodes;

}

void printAdjList(list <int> *nodes,int nodes_size){
	std::list<int>::const_iterator iterator;
	for (int i = 1; i < nodes_size +1; ++i)
	{
		for (iterator= nodes[i].begin();iterator !=nodes[i].end();++iterator)
		{
			cout<<*iterator<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	list <int> *nodes;
	int nodes_size;
	bool *explored=new bool[nodes_size+1];
	for (int i = 1; i < nodes_size+1; ++i)
	{	
		explored[i]=false;
	}
	cin>>nodes_size;
	nodes= createAdjList(nodes_size);
	printAdjList(nodes,nodes_size);
	s< list<int> > q;

	q.push(nodes[1]);
	explored[1]=true;

	while(!q.empty()){
		
		list<int> temp=q.front();
		q.pop();
		std::list<int>::const_iterator iterator;

		for (iterator= temp.begin();iterator !=temp.end();++iterator)
		{
			if (explored[*iterator]==true)
			{
				continue;
			}
			cout<<*iterator<<" poped out"<<endl;
			explored[*iterator]=true;
			q.push(nodes[*iterator]);
		}
			cout<<"out"<<endl;

	}
	return 0;
}
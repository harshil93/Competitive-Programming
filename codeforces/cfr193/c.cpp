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
struct order
{
	int index;
	int hair;
	int displease;
};

struct myclass1{bool operator()(const struct order& t1,const struct order& t2){
	if(t1.displease==t2.displease){
		return t1.hair<t2.hair;
	}else
		return t1.displease>t2.displease;
}} myobj1;

struct myclass2{bool operator()(const struct order& t1,const struct order& t2){
	if(t1.hair==t2.hair){
		return t1.displease>t2.displease;
	}
	return t1.hair>t2.hair;
}} myobj2;
int main(){
	int n,p,k;
	cin>>n>>p>>k;
	std::vector< struct order > orders;

	for (int i = 0; i < n; ++i)
	{
		int t1,t2; cin>>t1>>t2;
		struct order temp;
		temp.index = i;
		temp.hair = t1;
		temp.displease = t2;
		orders.push_back(temp);
	}

	sort(orders.begin(),orders.end(),myobj1);
	std::vector<int> v;
	for (int i = 0; i < k; ++i)
	{
		v.push_back(orders[i].index);
	}

		/*for (int i = 0; i < n; ++i)
		{
			cout<<orders[i].hair<<"-"<<orders[i].displease<<"\t";
		}
		cout<<endl;*/
	std::vector< struct order > remorders;
	for (int i = k; i < n; ++i)
	{
		remorders.push_back(orders[i]);
	}

	sort(remorders.begin(),remorders.end(),myobj2);
	
	/*for (int i = 0; i < remorders.size(); ++i)
	{
		cout<<remorders[i].hair<<"-"<<remorders[i].displease<<"-"<<remorders[i].index<<"\t";
	}
	cout<<endl;
	PR(p-k);*/
	

	for (int i = 0; i < p-k; ++i)
	{
		v.push_back(remorders[i].index);
	}
	

	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]+1<<" ";
	}
	cout<<endl;

}
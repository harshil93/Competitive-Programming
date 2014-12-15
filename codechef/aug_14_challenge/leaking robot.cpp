#include<iostream>

using namespace std;

int main()
{
	std::cout.sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int x,y;
		cin>>x>>y;

		if((x == 0 && y == 0) 
			|| ((x>0) && (x & 1) && (-1*x+1<=y) && (y<=x+1))
			|| ((x<0) && !(x & 1) && (x<=y) && (y<=-1*x))
			|| ((y>0) && !(y & 1) && (-1*y<=x) && (x<=y-1))
			|| ((y<0) && !(y & 1) && (y<=x) && (x<=-1*y+1))
			
		){
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
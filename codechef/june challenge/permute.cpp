#include <iostream>     // std::cout
#include <algorithm> 
#include <cstdio>   // std::next_permutation, std::sort
using namespace std;

int main () {
	int myints[] = {1,2,3,4,5,6,7,8,0};
	int temp=0;
	int sum;
	cin>>sum;
	do {
		int flag =0;
		for (int i = 0; i < 8; ++i)
		{
			
			if ((myints[i]+myints[i+1])>sum)
			{
				flag = 1;
			}
		}

			if (flag==1)
			{
			}else{
				temp++;
			}
			flag=0;
	} while ( std::next_permutation(myints,myints+8) );

	cout<<"ANSWER = "<<temp<<endl;

	return 0;
}
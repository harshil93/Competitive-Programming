#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
inline int fast_int()
{
int n=0;
int ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

int bin(vector <int> array, int lowerbound, int upperbound, int key)
{
       int position;
       position = ( lowerbound + upperbound) / 2;

       while((array[position] != key) && (lowerbound <= upperbound))
       {
              if (array[position] > key)              
             {                                                     
                    upperbound = position - 1;    
             }                                                      
             else                                                
            { 
                   lowerbound = position + 1;     
             }
             position = (lowerbound + upperbound) / 2;
       }

      if (lowerbound <= upperbound)
      {
            return position +1;
       }      
       else
             return lowerbound;
       
} 

int main()
{
	std::vector<int> v;

	v.push_back(2);v.push_back(5);v.push_back(8);v.push_back(12);v.push_back(22);v.push_back(25);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<"\t";
	}
	while(1){
		int temp;

		cin>>temp;
		// cout<<"Hello"<<endl;
		cout<<bin(v,0,v.size()-1,temp)<<endl;
		// cout<<"End"<<endl;
	}
}
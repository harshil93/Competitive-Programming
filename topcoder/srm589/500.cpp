#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class GearsDiv2 {
public:
	int getmin(string Directions) {
		int cont=1; int removed=0; char cur = Directions[0];
		int first = 0; int last = 0;
		int j=1;
		while(j<Directions.size() && cur == Directions[j]){
			j++;
		}
		first = j;
		if(j == Directions.size() ) return j/2;
		
		j= Directions.size()-2;
		int count = 1;
		while( j>=0 && Directions[Directions.size() - 1] == Directions[j]){
			
			j--;
			count++;
		}
		last = count;
		
		cur = Directions[first];
		for(int i=first+1; i< Directions.size() - last; i++){
			if(cur == Directions[i]){
				cout<<cont<<endl;
				cont++;
			}
			else{
				removed += cont/2;
				cont = 1;
				cur = Directions[i];
			}
			
		}
		removed += cont/2;
		
		if(Directions[0] ==  Directions[Directions.size() - 1]){
			removed += (first+last)/2;
		}
		
		
		
		return removed;
	}
};


int main(){
	GearsDiv2 test;
	string inp = "LRRR";

	cout<<test.getmin(inp)<<endl;

}
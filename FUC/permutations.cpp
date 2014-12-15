#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";


std::map<string,int> mymap;
void swap(char *a, char *b){
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
void permute(char *str, int s, int e){
	string st1(str,str+4);
	if(s==e){
		printf("%s\n", str);
		return ;
	}else{
		for (int i = s; i <= e; ++i)
		{

			if(i!=s && (*(str+s) != *(str+i))){
				swap(str+s,str+i);
				permute(str,s+1,e);
				swap(str+s,str+i);
			}else if(i==s){
				swap(str+s,str+i);
				permute(str,s+1,e);
				swap(str+s,str+i);
			}
						
		}
	}
}

int main(){
	char s[]= "aabc";

	permute(s,0,3);

}
#include <iostream>

using namespace std;

int gcd(int a, int b){
	int t;
	if(a<b){t=a;a=b;b=t;}
	while(b!=0){
		t = a;
		a=b;
		b= t%b;
	}
	return a;
}

int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}


int main(){
	int a,b;
	cin>>a>>b;
	cout<<"LCM is "<<lcm(a,b)<<endl;
	cout<<"Gcd is "<<gcd(a,b)<<endl;
	return 0;
}

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define INT_LEN 10000

class bigInt{
	
public:
	char a[INT_LEN];
	int digits;

	bigInt(){
		fill_n(a,INT_LEN,0);
	}
	bigInt & operator=(const char x){
		a[INT_LEN -1 ]=x;
		digits=1;
		return *this;
	}
	bigInt & operator=(const int x){
		int y=x;
		int i=INT_LEN -1 ;
		digits=0;
		while(y!=0){
			char c = y%10;
			a[i]=c;
			i--;
			digits++;
			y=y/10;
		}
		return *this;

	}

	bigInt & operator=(const bigInt x){
		for (int i = 0; i < x.digits; ++i)
		{
			a[INT_LEN -1 -i] = x.a[INT_LEN -1 -i];
		}
		digits = x.digits;

		return *this;
	}

	bigInt & operator+(const bigInt x){
		bigInt *temp= new bigInt();
		int max_digits=digits;
		if (x.digits>digits)
		{
			max_digits = x.digits;
		}

		for (int i = 0; i < max_digits; ++i)
		{
			temp->a[INT_LEN-1-i] = (a[INT_LEN-1-i] + x.a[INT_LEN-1-i])%10;
			temp->a[INT_LEN-2-i] += (a[INT_LEN-1-i] + x.a[INT_LEN-1-i])/10;
		}
		return *temp;
	}

	friend ostream &operator<<(ostream &out,const bigInt x);
};

ostream &operator<<(ostream &out,const bigInt x)
{
		char buff[INT_LEN];
		for (int i = x.digits; i>0; --i)
		{
			
			buff[x.digits - i] = x.a[INT_LEN - i]+'0';
		}
		buff[x.digits]='\0';
		out<<buff;
		return out;
};

int main(){
	bigInt a,b;
	a=10;
	

}
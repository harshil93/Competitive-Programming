/*This code demostrates how to remove ac and b from a string in a single pass without using any extra space*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

void remove_b_ac(char *s){
	int i=0,j=0,state=0;
	char buff;
	while(s[i]!='\0'){

		if (s[i]!='a' && s[i]!='b')
		{
			s[j++]=s[i++];
		}else if (s[i]=='b')
		{
			i++;
		}else
		{
			if (s[++i]=='c')
			{
				++i;
			}else{
				s[j++]= 'a';
				if (s[i]!='b')
				{
					s[j++] = s[i++];
				}else{
					i++;
				}
			}
		}
	}
	s[j]='\0';
}

int main(){
	char string[1000];
	scanf("%s",string);
	remove_b_ac(string);

	printf("%s\n", string);
}
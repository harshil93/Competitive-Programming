#include "cstdio"
#include "string"
#include "cstdlib"
using namespace std;
#define SIZE 65536
 int main()
{
	char buffer[SIZE];
	unsigned long n,k, input, output,count;
	int c;
	count=0;
	input=0;
	scanf("%lu %lu",&n,&k);

	while(c=fread(buffer, sizeof(char),SIZE,stdin)){
		for (int i = 0; i < c; ++i)
		{
			if(buffer[i]=='\n'){
				if (input%k==0)
				{
					count++;
				}
				input=0;
			}else{
				input = (input * 10) + (buffer[i] - '0');
			}
		}
	}
    printf("%lu\n", count);
	return 0;
}
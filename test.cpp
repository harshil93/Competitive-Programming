#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX1 100000007
#define NOD 20
 
int epow(int a, int b)
{
	if (b==0) return 1;
	if (b%2==0)
	{
		long long int t = epow(a,b/2);
		return (t*t)%MAX1;
		
	}
	return (epow(a,b-1)*a)%MAX1;
}
 
int pow1(int a, int b)
{
	int i;
	int rem=1;
	for (i=1; i<=b; i++)
	{
		rem=(rem*a)%MAX1;
	}
	return rem;
}
 
 
 
int arr_to_int(int a[], int low, int high)
{
	int i=low;
	int num=0;
	for (i=low; i<=high; i++)
	{
		num=(num*10)+a[i];
	}
	return num;
}
 
 
 
int main()
{
	int t;
	scanf("%d", &t);
	int i;
	char s[NOD];
	//int a[20];
 
	//precalculating remainders of 2^n, 3^n, 4^n for 0<=n<=100000005
 
	int t1 = MAX1-1;
/**/	
/*	int *Rem2 = malloc(MAX1*sizeof(int));
	int *Rem3 = malloc(MAX1*sizeof(int));
	int *Rem4 = malloc(MAX1*sizeof(int));
//	printf("hi\n");
//	rem[0][2]=rem[0][3]=rem[0][4]=1;
	*(Rem2)=*(Rem3)=*(Rem4)=1;
	for (i=1; i<MAX1; i++)
	{
		*(Rem2+i)=(*(Rem2+i-1)*2)%MAX1;
		*(Rem3+i)=(*(Rem3+i-1)*3)%MAX1;
		*(Rem4+i)=(*(Rem4+i-1)*4)%MAX1;
	}
*/
 
int rem2_2, rem3_1_2, rem4_2;
int rem2,rem3,rem4;
int sum,ans1,ans2;
 
	for (i=1; i<=t; i++)
	{
		scanf("%s", s);
		int l=strlen(s);
		int a[l];
		int k;
		for (k=0; k<l; k++)
		{
			a[k]=s[k];
			a[k]=a[k]-48;
			//printf("%d", a[k]);
		}
		//printf("\n");
		if (l%8==0) k=l/8;
		else k=(l/8)+1;
		int j;
		int t2=1;
		int t3=l-1;
		int r1=0;
 
		int n=arr_to_int(a,0,l-1);
 
		for (j=0; j<k; j++)
		{
			if (t3>=7) r1=(r1+(t2*arr_to_int(a,t3-7,t3)))%t1;
			else r1=(r1+(t2*arr_to_int(a,0,t3)))%t1;
			t3=t3-8;
			t2=-6*t2;
			//printf("%d\n", r1);
		}
		if (r1<0) r1=r1+t1;
		//printf("%d\n", r1);
		//printf("%d %d\n", n,n%t1);
		rem2=epow(2,r1);
		rem3=epow(3,r1);
		rem4=epow(4,r1);
 
 
		if (rem2%2==0) rem2_2=rem2/2;
		else rem2_2=(rem2+MAX1)/2;
 
		if ((rem3+1)%2==0) rem3_1_2=(rem3+1)/2;
		else rem3_1_2=((rem3+MAX1+1)/2)%MAX1;
 
		if (rem4%2==0) rem4_2=rem4/2;
		else rem4_2=(rem4+MAX1)/2;
 
		sum=(rem4_2+rem2_2-rem3)%MAX1;
		if (sum<0) sum=sum+MAX1;
 
		ans1 = (rem3_1_2-rem2)%MAX1;
		if (ans1<0) ans1=ans1+MAX1;
 
		ans2=(sum-ans1)%MAX1;
		if (ans2<0) ans2=ans2+MAX1;
 
		//printf("%d %d\n", rem2_2, rem4_2);
 
		printf("%d %d\n", ans1, ans2);
		
	}
	//free(Rem2);free(Rem3);free(Rem4);
	return 0;
} 
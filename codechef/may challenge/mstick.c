#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double b[100005];
double bc[100005];


int main()
{
	int n,q,i;
	scanf("%d",&n);

	for ( i = 0; i < n; ++i)
	{
		scanf("%lf",&b[i]);
		bc[i] = b[i];
	}

	scanf("%d",&q);
	int l,r;
	while(q--){
		
		scanf("%d%d",&l,&r);
		int min_index=l;

		for ( i = l+1; i <= r; ++i)
		{
			if(b[i]<b[min_index]) min_index =i;
		}

		for ( i = l; i <= r; ++i)
		{
			bc[i] -= b[min_index];
			bc[i] = bc[i]/2;
		}

		int max_index=0;

		for ( i = 1; i < n; ++i)
		{
			if (bc[i]>bc[max_index])
			{
				max_index = i;
			}
		}
		/*float finalanswer=0;
		double temp;
		finalanswer = (int)(bc[max_index]+b[min_index]);
		float fractpart = modf(bc[max_index]+b[min_index],&temp);
		fractpart = fractpart*10;
		int slicedpart = fractpart;
		finalanswer = finalanswer + (slicedpart/10.0);
		printf("%.1f\n", finalanswer);*/
		printf("%0.1f\n",bc[max_index]+b[min_index] );

		for ( i = l; i <= r; ++i)
		{
			bc[i] = b[i];
		}

	}
	return 0;
}
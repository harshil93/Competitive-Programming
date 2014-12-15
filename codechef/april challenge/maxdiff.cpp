#include "cstdio"
#include "algorithm"

using namespace std;

int main(){
	int t, n, k;
	int weight[102];
	scanf("%d",&t);
	long long int sum_t=0,sum_k=0;
	while(t--){
		scanf("%d %d",&n,&k);
		sum_t=0;
		sum_k=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&weight[i]);
			sum_t+=weight[i];

		}

		std:: sort(weight,weight+n);
	

		
			for (int i = 0; i < k; ++i)
			{
				sum_k += weight[i];
			}

			long long int diff_f = sum_t-2*sum_k;
			diff_f = diff_f>0?diff_f:(-1)*diff_f;
			sum_k =0;
			for (int i = 0; i < k; ++i)
			{
				sum_k+=weight[n-1-i];
			}
			long long int diff_b = sum_k - (sum_t - sum_k) ;
			diff_b = diff_b>0?diff_b:(-1)*diff_b;

			printf("%lld\n", diff_b>diff_f?diff_b:diff_f );
		


	}
	return 0;
}
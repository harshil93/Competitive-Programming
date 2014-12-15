#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
#define iprin(x) cout << #x " = " << x << "\n";
int main()
{
	int t;
	char str[10004];
	scanf("%d",&t);
	getchar();
	std::vector<int> hash;
	while(t--){
		int len=0;len=0;
		char c;
		while((c=getchar())!='\n'){
			str[len]=c;
			if (c=='#')
			{
				hash.push_back(len);
			}
			len++;
		}
		str[len]='\0';
		if (hash.size()<3)
		{
			printf("0\n");
			hash.clear();
			continue;

		}
		if (len<7)
		{
			printf("0\n");
			hash.clear();
			continue;
		}

		int **before = (int**)calloc(hash.size(),sizeof(int *));
		int **after = (int**)calloc(hash.size(),sizeof(int *));

		for (int i = 0; i < hash.size(); ++i)
		{
			before[i] = new int[26];
			after[i] = new int[26];
		}
			int hashcnt = 0;
			int culfreq[26]={0};
			for (int i = 0; i < 26; ++i)
			{
				culfreq[i]=0;
			}
		for (int i = 0; i < len ; ++i)
		{
			
			if (str[i]!='#')
			{
				culfreq[str[i]-'a']++;
			}else{
				for (int i = 0; i < 26; ++i)
				{
					before[hashcnt][i] = culfreq[i];
				}
				hashcnt++;
			}
		}

		for (int i = 0; i < hash.size(); ++i)
		{

			for (int j = 0; j < 26; ++j)
			{
				after[i][j]=culfreq[j]-before[i][j];
			}
		}
		int sum =0;sum=0;

		for (int i = 0; i < hashcnt-2; ++i)
		{
			int max_before = before[i][0];
			int max_betw1 = before[i+1][0]-before[i][0];
			int max_betw2 = before[i+2][0]-before[i+1][0];
			int max_after = after[i+2][0];
			for (int j = 1; j < 26; ++j)
			{
				if (before[i][j]>max_before)
				{
					max_before = before[i][j];
				}

				max_betw1 = before[i+1][j]-before[i][j]>max_betw1?before[i+1][j]-before[i][j]:max_betw1;
				max_betw2 = before[i+2][j]-before[i+1][j]>max_betw2?before[i+2][j]-before[i+1][j]:max_betw2;
				if (after[i+2][j]>max_after)
				{
					max_after = after[i+2][j];
				}

			}
			int tempsum;
			if (max_before==0 || max_betw1==0 || max_betw2==0 || max_after==0)
			{
				tempsum=0;
			}else
			 {
			 	tempsum = max_before + max_betw1 + max_betw2 + max_after;
			 }
			 // iprin(max_before);iprin(max_betw1);iprin(max_betw2);iprin(max_after);
			 if (tempsum>sum)
			 {
			 	sum	= tempsum;
			 }
			 iprin(i);
			 iprin(sum);
		}
		if (sum<=3)
		{
			printf("0\n");
		}else{
			printf("%d\n", sum+3);
		}
		

		free(before);
		free(after);
		hash.clear();




	}
	return 0;
}
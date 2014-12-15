#include "cstdio"
#include "string"
#include "stack"
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
struct pr
{
	char c;
	int pos1;
	int pos2;
};

std::stack<struct pr> s;

int lcs_length(char* s1,int len1, char* s2, int len2){
	//printf("%c %c\n",s1[len1-1],s2[len2-1] );
	if (len1==0 || len2==0)
	{
			return 0;
	}
	if (s1[len1-1]==s2[len2-1])
	{
		struct pr p;
		p.c = s1[len1-1];
		p.pos1 = len1;
		p.pos2 = len2;
		//printf("pushing %c %d %d\n" ,p.c,p.pos1,p.pos2);
		s.push(p);
		
			return 1 + lcs_length(s1,len1-1,s2,len2-1);
	}else{
			//printf("going to max %d %d\n", len1,len2 );
			int i1=lcs_length(s1,len1-1,s2,len2);
			int i2 = lcs_length(s1,len1,s2,len2-1);
			if(i1>i2){
				for (int i = 0; i < i2; ++i)
				{
					s.pop();
				}
			}else{
				struct pr arr[1000];
				for (int i = 0; i < i2; ++i)
				{
					arr[i]=s.top();
					s.pop();
				}
				for (int i = 0; i < i1; ++i)
				{
					s.pop();
				}
				for (int i = 0; i < i2; ++i)
				{
					s.push(arr[i2-1-i]);
				}

			}
			return max(i1,i2);
	}
}

int main()
{
	int t,m,n;
	char s1[1005],s2[1005];
	scanf("%d",&t);
	int _t=t;
	while(t--){
		scanf("%d %s %d %s",&m,s1,&n,s2);
		int ans = lcs_length(s1,m,s2,n);
		if (ans==1)
		{
			printf("case %d N\n",_t-t);
			s.pop();
			continue;
		}
		if (ans==0)
		{
			printf("case %d N\n",_t-t);
			continue;
		}
		printf("case %d Y\n",_t-t);
		printf("%d\n",ans);
		//printf("size of stack%d \n",s.size() );
		int size=s.size();
		for (int i = 0; i < size; ++i)
		{
			struct pr p=s.top();
			s.pop();
			
			printf("%c %d %d\n",p.c,p.pos1,p.pos2);
		}
	}
}
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i, j;
	int n;
	int a;
	int b;
	int r = 0;
	int c = 0;
	scanf("%d", &n);
	for(i = 0; i < n * 2; i++)
	{
		scanf("%d.%d", &a, &b);
		r += b;
		if(b == 0)
			c++;
	}
	r -= 1000 * n;
	while(c > 0 && r < -500)
	{
		r += 1000;
		c--;
	}
	if(r < 0)
		r = -r;
	printf("%d.%03d\n", r / 1000, r % 1000);
	return 0;
}
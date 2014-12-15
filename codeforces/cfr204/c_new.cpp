#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double a[2*n],s=0;
    for (int i = 0; i < 2*n; ++i)
    {
        cin>>a[i];s=s+a[i];
    }
    int ans;
    ans=(int)s;
    // val=double(ans);
    if((s-ans)>.50000)
    {
        printf("%.3lf\n",1 -(s-ans));
    }
    else
    {
        printf("%.3lf\n",s-ans);
    }
    return 0;
}
    #include <iostream>
    #include <string>
    #include <climits>
    #include <cstdio>
    #include <cstdlib>
    #include <cmath>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <map>
    #include <set>
using namespace std;
    #define PR(x) cout << #x " = " << x << "\n";
bool areAllZero(std::vector<int> &curr)
{
    int n=curr.size();
    for (int i = 0; i < n; ++i)
    {
        if (curr[i]!=0)
        {
            return false;
        }
    }
    return true;
}

int retMin(std::vector<int> &v)
{
    int n=v.size(), pos=0;
    int min=v[0];
    for (int i = 1; i < n; ++i)
    {
        if (min>v[i])
        {
            min=v[i];
            pos=i;
        }
    }
    return pos;
}
bool allLess(std::vector<int> &v)
{
    int n=v.size();
    int cnt0 = 0,cntn=0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i]<0)
        {
            cntn++;
            
        }else if(v[i] == 0){
            cnt0++;
        }
    }
    if(cnt0>2)
        return true;
    else if(cnt0 == 1 && cntn>0) return true;
    else{
        if(cntn>1) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int t,n,temp; scanf("%d",&t);
    while(t--)
    {
        std::vector<int> curr;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&temp);
            curr.push_back(temp);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&temp);
            curr[i]=temp-curr[i];
        }
        if (n==1 && curr[0]>0)
        {
            printf("-1\n");
            continue;
        }

        int ans=0;
        while(!areAllZero(curr) && ans<=54)
        {
            if (allLess(curr))
            {
                ans=-1;
                break;
            }
            ans++;
            int pos=retMin(curr);
            for (int i = 0; i < n; ++i)
            {
                if (i==pos)
                {
                    curr[i]++;
                }
                else
                    curr[i]--;
            }

        }
        if (ans>=54)
        {
            ans=-1;
        }
        printf("%d\n", ans);
    }
    return 0;
} 
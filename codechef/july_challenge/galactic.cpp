#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
 #define PR(x) cout << #x " = " << x << "\n";
 inline int fast_int()
 {
 int n=0;
 int ch=getchar();
 while(ch<48)ch=getchar();
 while(ch >47)
 n=(n<<3)+(n<<1)+ch-'0',ch=getchar();
 return n;
 }
typedef int T;
vector<int> parent;
vector<T> value;
#define setClear() { parent.clear(); value.clear(); }
#define setMake(v) { value.push_back(v); parent.push_back(parent.size()); }
#define setUnion(x, y) { parent[setFind(x)] = setFind(y); }
#define min(x,y) x < y ? x : y
int setFind(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = setFind(parent[x]);
}
 
int main() {
    int n=fast_int(); int m = fast_int();
    int *setMinCost = (int *) calloc(n,sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        setMake(i);
    }

    for (int i = 0; i < m; ++i)
    {
        int val1 = fast_int(); int val2 = fast_int();
        setUnion(val1-1,val2-1);
    };

    std::vector<int> cost;
    for (int i = 0; i < n; ++i)
    {
        int cost_temp;
        scanf("%d",&cost_temp);
        setMinCost[i] = cost_temp;
        cost.push_back(cost_temp);
    };
    int *freq =(int *) calloc(n,sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        int temp = setFind(i);
        freq[temp]++;
        if(cost[i]>=0 && setMinCost[temp]>cost[i]){
                setMinCost[temp] = cost[i];
        }else if(setMinCost[temp]<0 && cost[i]>=0){
            setMinCost[temp] = cost[i];
        }

    }
    bool notFulfilled = false;
    int minofall = 10000000;
    int minindex = -1;
    for (int i = 0; i < n; ++i)
    {
        printf("@@ %d\n", freq[i] );
        printf("!! %d \n", setMinCost[i] );
    }
    for (int i = 0; i < n; ++i)
    {
        if(freq[i]>0 && setMinCost[i]<0){
            notFulfilled = true;
            break;
        }
        if(freq[i]> 0 && setMinCost[i]>=0 && minofall>setMinCost[i]){
            minofall = setMinCost[i];
            minindex = i;
        }
    }

    

    printf("%d %d \n",minindex, minofall );
    int64_t totalcost=0;
    int count=0;
    for (int i = 0; i < n; ++i)
    {
        if(freq[i]>0){
            totalcost += setMinCost[i];
            count++;
        }
    }

    totalcost = totalcost + (count-2)*minofall;
    if(count ==1 ){
        printf("0\n");
    }else if(count>1 && notFulfilled){
        printf("-1\n");
    }else
        printf("%lld\n", totalcost);
    return 0;
}
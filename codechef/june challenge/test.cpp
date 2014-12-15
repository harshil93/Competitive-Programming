#include "stdio.h"
#include "stdlib.h"

int64_t pow(int a, int b, int MOD) {
int64_t x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            
            x=(x*y);
            if (x==0)
            {
                printf("y = %lld\n",y);
            }
            if(x>MOD) x%=MOD;
            if (x==0)
            {
                printf("x = %lld\n",x);
            }
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
int64_t modInverse(int a, int m) {
    return pow(a,m-2,m);
}

int main(){
    int64_t j = 2482702;
    int64_t z = 2482702*2482702;
    printf("%lld\n", z);
    printf("%d\n",sizeof(unsigned long long) );
}
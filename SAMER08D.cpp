#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1001;

char a[ MAXN ], b[ MAXN ];
int A, B;
int dp[ MAXN ][ MAXN ];

int main(void) {
#ifdef DEBUG
     freopen( "sample.in" , "r" , stdin );
#endif

    while( 1 ) {
        int k;
        scanf( "%d" , &k );
        if( !k )
break;
        memset( dp , 0 , sizeof dp );

        scanf( "%s" , a + 1 );
        scanf( "%s" , b + 1 );

        A = strlen(a + 1) , B = strlen(b + 1);
        int old = 0, now = 1;
        for(int i = k; i <= A; ++i) {
            for(int j = k; j <= B; ++j) {
                dp[i][j] = max( dp[i - 1][j] , dp[i][j - 1] );
                for(int t = 0; t <= i; ++t) {
                    if( t >= k )
                        dp[i][j] = max( dp[i][j] , dp[i - t][j - t] + t );
                    if( a[i - t] != b[j - t] )break;
                }
            }
            // swap( old , now );
        }

        printf( "%d\n" , dp[A][B] );
    }

    return 0;
}
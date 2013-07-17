    #include "cstdio"
using namespace std;
    #define SCANFINT(n) scanf("%d",&n)

int max(int a , int b){
    if(a>b) return a;
    return b;
}


int matrix[102][102];
    /*void printmatrix(int n){
    for (int i = 1; i <= n; ++i)
    {
    for (int j = 1; j <= i; ++j)
    {
    printf("%d ",matrix[i][j]);
    }
    printf("\n");
    }
     
    }*/
    int main(){
        int t,n;
        SCANFINT(t);
        while(t--){
            SCANFINT(n);
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= i; ++j)
                {
                    SCANFINT(matrix[i][j]);
                }
            }
            
            for (int i = n; i >1; --i)
            {
                for (int j = 1; j <=i; ++j)
                {
                    matrix[i-1][j] = matrix[i-1][j] + max(matrix[i][j],matrix[i][j+1]);
                }
    //printmatrix(n);
            }
            printf("%d\n", matrix[1][1]);
        }
        return 0;
    } 
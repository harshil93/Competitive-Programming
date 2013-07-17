#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll res[50001]; int res_size;
ll q[1000001]; int q_st, q_size;
int n3[1000001], n5[1000001], n8[1000001];

int main(){
  int i,j,k;
  ll n;

  q_st = q_size = 0;
  n3[q_st+q_size] = 1; n5[q_st+q_size] = 0; n8[q_st+q_size] = 0; q[q_st+q_size++] = 3;
  n3[q_st+q_size] = 0; n5[q_st+q_size] = 1; n8[q_st+q_size] = 0; q[q_st+q_size++] = 5;
  n3[q_st+q_size] = 0; n5[q_st+q_size] = 0; n8[q_st+q_size] = 1; q[q_st+q_size++] = 8;

  res_size = 0;
  while(res_size < 50000){
    i = n3[q_st]; j = n5[q_st]; k = n8[q_st];
    n = q[q_st++]; q_size--;
    if(i <= j && j <= k) res[res_size++] = n;
    n3[q_st+q_size] = i+1; n5[q_st+q_size] = j;   n8[q_st+q_size] = k;   q[q_st+q_size++] = 10*n + 3;
    n3[q_st+q_size] = i;   n5[q_st+q_size] = j+1; n8[q_st+q_size] = k;   q[q_st+q_size++] = 10*n + 5;
    n3[q_st+q_size] = i;   n5[q_st+q_size] = j;   n8[q_st+q_size] = k+1; q[q_st+q_size++] = 10*n + 8;
  }

  rep(i,res_size) printf("%lld\n",res[i]);

  return 0;
}

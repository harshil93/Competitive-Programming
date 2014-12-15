#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define MOD 3046201

int64_t *factMod;

inline int64_t fast_int()
{
int64_t n=0;
int64_t ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

int64_t powa(int64_t a, int64_t b) {
int64_t x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
int64_t modInverse(int64_t a, int64_t m) {
    return powa(a,m-2);
}

int64_t ipow(int64_t a, int64_t b) {
int64_t x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
int64_t getMid(int64_t s, int64_t e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the sum of values in given range of the array.
    The following are parameters for this function.
 
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int64_t getSumUtil(int64_t *st, int64_t ss, int64_t se, int64_t qs, int64_t qe, int64_t index)
{
    // If segment of this node is a part of given range, then return the
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int64_t mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
/* A recursive function to update the nodes which have the given index in
   their range. The following are parameters
    st, index, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int64_t *st, int64_t ss, int64_t se, int64_t i, int64_t diff, int64_t index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int64_t mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int64_t arr[], int64_t *st, int64_t n, int64_t i, int64_t new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    int64_t diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
int64_t getSum(int64_t *st, int64_t n, int64_t qs, int64_t qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int64_t constructSTUtil(int64_t arr[], int64_t ss, int64_t se, int64_t *st, int64_t si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int64_t mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int64_t *constructST(int64_t arr[], int64_t n)
{
    // Allocate memory for segment tree
    int64_t x = (int64_t)(ceil(log2(n))); //Height of segment tree
    int64_t max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int64_t *st = new int64_t[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

int64_t fact(int64_t n){
    return factMod[n];
}

int64_t invfact(int64_t n){
    return ipow(n, MOD - 2)%MOD;
}
int64_t nCk(int64_t n,int64_t k)
{
    return (((fact(n) * invfact(fact(n-k)))%MOD) * invfact(fact(k)))%MOD;
}


/*int64_t main(){
    int64_t n;
    int64_t B[100005];
    B[0]=0;
    factMod= (int64_t *)calloc(3000010,sizeof(int));
    factMod[0] = 1;
    // int64_t temp=1;
    n = 8;
    int64_t temp[] = {0,2,3,5,4,2,5,7,1};
    int64_t *sum = constructST(temp,n+1);
    updateValue(temp,sum,n+1,5,0);
    for (int64_t i = 1; i <= 8; ++i)
    {
        for (int64_t j = i; j <=8; ++j)
        {
            printf("i=%d j=%d\n",i,j );
            printf("%d\n",getSum(sum,n+1,i,j));
        }

    }
    


}*/

int main(){
	int64_t n;
	int64_t B[100005];
	B[0]=0;
    factMod= (int64_t *)calloc(3000010,sizeof(int64_t));
    factMod[0] = 1;
    int64_t temp=1;
    for (int64_t i = 1; i < 3000001; ++i)
    {
        temp = (temp*i)%MOD;
        factMod[i]=temp;
    }

    // printf("%lld\n",invfact(2482702) );
	n=fast_int();

	for (int64_t i = 1; i <= n; ++i)
	{
		B[i]=fast_int();
		
	}
	int64_t *sum = constructST(B, n+1);
	int64_t q;
	q = fast_int();
	char str[10];
	while(q--){
		str[0] = getchar();
		while(getchar()!=' '){
			
		}
		if (str[0] =='c')
		{
			int64_t t1,t2;
			t1 = fast_int();
			t2 = fast_int();
			updateValue(B, sum, n+1, t1, t2);
		}else{
			int64_t t1,t2;
			t1 = fast_int();
			t2 = fast_int();
			int64_t tempsum=0;
			int64_t no_persons = t2 - t1 +1;
			int64_t product=1;
			tempsum = getSum(sum, n+1, t1, t2);
            // PR(tempsum)
			int64_t aplus1 = tempsum/no_persons +1;
			int64_t tempsum_b = tempsum;

            product = (((fact(tempsum) * invfact(ipow(fact(aplus1),tempsum%no_persons)))%MOD) * invfact(ipow(fact(aplus1-1),no_persons - tempsum%no_persons)))%MOD;
			product = (product * nCk(no_persons,tempsum%no_persons))%MOD;


            printf("%lld\n",product );
		}

	}
}
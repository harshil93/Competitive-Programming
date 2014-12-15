#include <iostream>
#include <string>
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

#define MOD 1000000007


// A utility function to get the middle index from corner indexes.
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
    return (getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
               getSumUtil(st, mid+1, se, qs, qe, 2*index+2))%MOD;
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
    return st[si]%MOD;
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int64_t *constructST(int64_t arr[], int64_t n)
{
    // Allocate memory for segment tree
    int64_t x = (int64_t)(ceil(log2(n))); //Height of segment tree
    int64_t max_size = 2*(int64_t)pow(2, x) - 1; //Maximum size of segment tree
    int64_t *st = new int64_t[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

int64_t magicVal(int64_t n){
    int64_t ans = 0;

    while(n>0){
        int64_t mod = n%10;
        ans = ans + mod*mod;
        n = n/10;
    }
    return ans;
}


int digs(int n){
    int dig = 0;

    while(n>0){
        dig++; n = n/10;    }
}

// Driver program to test above functions
int main()
{

    int64_t q; cin>>q; int64_t n; cin>>n;
    int64_t *a= new int64_t[1000000];

    for (int64_t i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    int64_t m; cin>>m;
    std::vector<int> v;
    for (int64_t i = 1; v.size() < 3*100000 + 1; ++i)
    {
        int64_t t = magicVal(i);
        if(t<=q){
            v.push_back(i);
            // cout<<i<<" "<<t<<endl;
        }
    }

    int64_t *b= new int64_t[1000000];

    for (int64_t i = 0; i < n; ++i)
    {
        b[i] = v[a[i] - 1];
        // PR(a[i])
        // PR(b[i]);
    }

 
    // Build segment tree from given array
    int64_t *st = constructST(b, n);
 
    // Print64_t sum of values in array from index 1 to 3
    // printf("Sum of values in given range = %d\n", getSum(st, n, 1, 3));
 
    // Update: set arr[1] = 10 and update corresponding segment
    // tree nodes
    // updateValue(arr, st, n, 1, 10);
 
    // Find sum after the value is updated
    // printf("Updated sum of values in given range = %d\n",
                                                  // getSum(st, n, 1, 3));

    for (int64_t i = 0; i < m; ++i)
    {
        int64_t a, b; cin>>a>>b;
        cout<<getSum(st,n,a-1,b-1)<<endl;;
    }


 
    return 0;
}


#include <stdio.h>
#define MAX 1000000

void print(int *a, int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
}
 
void radixsort(int *a, int n)
{
  int i, b[MAX], m = 0, exp = 1;
  for (i = 0; i < n; i++)
  {
    if (a[i] > m)
      m = a[i];
  }
 
  while (m / exp > 0)
  {
    int bucket[10] =
    {
      0
    };
    for (i = 0; i < n; i++)
      bucket[a[i] / exp % 10]++;
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    for (i = n - 1; i >= 0; i--)
      b[--bucket[a[i] / exp % 10]] = a[i];
    for (i = 0; i < n; i++)
      a[i] = b[i];
    exp *= 10;
 
    
  }
}
 
 
int main()
{
  int arr[MAX];
  int i, n;
 
 // printf("Enter total elements (n < %d) : ", MAX);
  scanf("%d", &n);
 
 // printf("Enter %d Elements : ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
 
   radixsort(&arr[0], n);
  print(&arr[0], n);
 
  return 0;
}
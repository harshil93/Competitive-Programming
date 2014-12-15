#include<iostream>
#include<algorithm>
using namespace std;
// #define PR(x) cout << #x " = " << x << "\n";

#define llu long long int
int p[100001],size[100001];
inline int find(int x)
{
 if(p[x]== x)
  return x;
else
{
  p[x]=find(p[x]);
  return find(p[x]);
}
}
inline void mer(int s1,int s2)
{
  int r1,r2;
  r1=find(s1);
  r2=find(s2);
  if(r1==r2)
    return;
  if(size[r1]>=size[r2])
  {
    size[r1]=size[r1]+size[r2];
    p[r2]=r1;
  }
  else
  {
    size[r2]=size[r1]+size[r2];
    p[r1]=r2;
  }
}
struct edge
{
 int x,y,w;
 bool use;
 edge(){use=0;}
}a[10001];
bool cmp(edge l,edge r)
{
 return l.w<r.w;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    // cout<<endl<<endl;
    int n,m,cos,i;
    cin>>n>>m>>cos;
    for(i=0;i<n;i++)
    {
      p[i]=i;
      size[i]=1;
    }
    for(i=0;i<m;i++)
    {
     cin>>a[i].x>>a[i].y>>a[i].w;
   }
   sort(a,a+m,cmp);
   for (int i = 0; i < m; ++i)
   {
     a[i].use  = 0;
   }
   for(i=m-1;i>=0;i--)
   {
     int k1=find(a[i].x),k2=find(a[i].y);
     // PR(k1) PR(k2)
     if(k1!=k2){mer(k1,k2);a[i].use=1;}
   }
   int c=0;       
   for(i=0;i<n;i++)if(p[i]==i)c++;
    int re=0,ne=0,co=0;
  // PR(c)
  if(c>1)
  {
   for(i=0;i<m;i++)
   {
    // PR(i)
    // PR(a[i].use)
     if(!a[i].use)
     {
      // PR(a[i].w) PR(cos)
      if(c>1)
      {
       re++;
       co+=a[i].w;
       c--;
     }
   }
 }
 if(c>1){ne=c-1;co+=ne*(cos);}
}
cout<<ne<<" "<<re<<" "<<co<<endl;
}
return 0;
}



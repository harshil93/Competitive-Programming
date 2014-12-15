#include <bits/stdc++.h>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<long long> VI; 
typedef vector<VI> VVI; 
typedef pair<long long,long long> II; 
#define SZ(a) long long((a).size()) 
#define PB push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FOR(i,n) for( long long i =0 ; i < n ; i++ )
#define ll long long
#define FF first
#define SS second

template<int MSize = 26, class T = double >
class SqMx {
  typedef T Ax[MSize][MSize];
  typedef SqMx<MSize, T> Mx;
 
public:
      Ax a;
  SqMx() { }
  SqMx(const Ax &_a) { // constructor with pre-defined array
    for (int r = 0; r < MSize; r++)
      for (int c = 0; c < MSize; c++)
        a[r][c] = _a[r][c];
  }
 
  static Mx identity() {
    Mx m;
    for (int r = 0; r < MSize; r++)
      for (int c = 0; c < MSize; c++)
        m.a[r][c] = (r == c ? 1 : 0);
    return m;
  }
 
  friend ostream &operator<<(ostream& os, const Mx &p)
  { // ugly print
    for (int i = 0; i < MSize; i++) {
      for (int j = 0; j < MSize; j++)
        os << p.a[i][j] << ",";
      os << endl;
    }
    return os;
  }
 
  Mx operator*(const Mx &b) {
    Mx d;
    for (int r = 0; r < MSize; r++)
      for (int c = 0; c < MSize; c++) {
        d.a[r][c] = 0;
        for (int k = 0; k < MSize; k++)
          d.a[r][c] += a[r][k] * b.a[k][c];
      }
    return d;
  }
  // C++ does not have a ** operator, instead, ^ (bitwise Xor) is used.
  Mx operator^(int n) {
    if (n < 0)
      throw "Negative exponent not implemented";
 
    Mx d = identity();
    for (Mx sq = *this; n > 0; sq = sq * sq, n /= 2)
      if (n % 2 != 0)
        d = d * sq;
    return d;
  } 
};

typedef SqMx<> M26;

int main(){
    std::ios_base::sync_with_stdio(false);
    long long T;
    cin>>T;
    cout<<fixed<<setprecision(16);

    while(T--){

        double arr[26][26];
        long long n,k; cin>>n>>k;
        string ostr;
        cin>>ostr;
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                cin>>arr[i][j];
            }
        }
        
        M26 F(arr);
        if(k==1)
            ;
        else
            F = F^(k);

        double ans = 0;
        set<string> ss;
        while(n--){
            string str;
            cin>>str;
            ss.insert(str);
        }

        for(auto it = ss.begin() ; it!= ss.end(); it++){
            string str = *it;
            if(str.size() == ostr.size()){
                double tempans = 1;
                for (long long i = 0; i < str.size(); ++i)
                {
                    tempans *= F.a[ (ostr[i] - 'a')][ (str[i] - 'a') ];
                }
                ans += tempans;
            }
        }
        
        cout<<ans<<endl;

    }
}
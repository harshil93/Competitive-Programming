#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int64_t fact[65];
void preprocess(){
	fact[1]= 1u;
	fact[2]= 2u;
	fact[3]= 3u;
	fact[4]= 6u;
	fact[5]= 10u;
	fact[6]= 20u;
	fact[7]= 35u;
	fact[8]= 70u;
	fact[9]= 126u;
	fact[10]= 252u;
	fact[11]= 462u;
	fact[12]= 924u;
	fact[13]= 1716u;
	fact[14]= 3432u;
	fact[15]= 6435u;
	fact[16]= 12870u;
	fact[17]= 24310u;
	fact[18]= 48620u;
	fact[19]= 92378u;
	fact[20]= 184756u;
	fact[21]= 352716u;
	fact[22]= 705432u;
	fact[23]= 1352078u;
	fact[24]= 2704156u;
	fact[25]= 5200300u;
	fact[26]= 10400600u;
	fact[27]= 20058300u;
	fact[28]= 40116600u;
	fact[29]= 77558760u;
	fact[30]= 155117520u;
	fact[31]= 300540195u;
	fact[32]= 601080390u;
	fact[33]= 1166803110u;
	fact[34]= 2333606220u;
	fact[35]= 4537567650u;
	fact[36]= 9075135300u;
	fact[37]= 17672631900u;
	fact[38]= 35345263800u;
	fact[39]= 68923264410u;
	fact[40]= 137846528820u;
	fact[41]= 269128937220u;
	fact[42]= 538257874440u;
	fact[43]= 1052049481860u;
	fact[44]= 2104098963720u;
	fact[45]= 4116715363800u;
	fact[46]= 8233430727600u;
	fact[47]= 16123801841550u;
	fact[48]= 32247603683100u;
	fact[49]= 63205303218876u;
	fact[50]= 126410606437752u;
	fact[51]= 247959266474052u;
	fact[52]= 495918532948104u;
	fact[53]= 973469712824056u;
	fact[54]= 1946939425648112u;
	fact[55]= 3824345300380220u;
	fact[56]= 7648690600760440u;
	fact[57]= 15033633249770520u;
	fact[58]= 30067266499541040u;
	fact[59]= 59132290782430712u;
	fact[60]= 118264581564861424u;
	fact[61]= 232714176627630544u;
	fact[62]= 465428353255261088u;
	fact[63]= 916312070471295267u;
	fact[64]= 1832624140942590534u;
}

int64_t binarySearchGreater(int64_t *v,int64_t s,int64_t e,int64_t val){
	int64_t mid = s + (e-s)/2;
	if(v[mid]== val){
		return mid+1;
	}
	if(s==e){
		if(v[s] > val){
			return s+1;
		}else{
			return s+2;
		}
	}
	if(v[mid] > val){
		if(s<=mid-1)
			return binarySearchGreater(v,s,mid-1,val);
		else
			return s;
	}else{
		if(mid+1<=e)
			return binarySearchGreater(v,mid+1,e,val);
		else
			return e+1;
	}
}

int main(){
	int t;
	cin>>t;
	preprocess();

	/*for (int i = 0; i < 65; ++i)
	{
		cout<<i<<" "<<fact[i]<<endl;
	}*/
	while(t--){
		int64_t n; cin>>n;
		cout<<binarySearchGreater(fact,0,63,n) -1<<endl;
	}
	return 0;
}
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class KeyDungeonDiv2 {
public:
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
		int opened = 0;
		for(int i=0; i< doorG.size(); i++){

			// cout<<doorR[i]<<" "<<doorG[i]<<" ";
			int white = keys[2];
			// cout<<"##"<<white<<endl;
			int doorRO = 0;
			int doorGO = 0;
			if(doorR[i] != 0){
				if(doorR[i] <= keys[0]){
					doorRO = 1;
				}else if(doorR[i] <= keys[0] + white){
					white = white - doorR[i] + keys[0];
					doorRO = 1;
			
			}
			
			}else{
				doorRO = 1;
			}
			// cout<<"white "<<white<<endl; 	
			if(doorG[i] !=0){
				if(doorG[i] <= keys[1]){
					doorGO = 1;
				}else if(doorG[i] <= keys[1] + white){
					white = white - doorR[i] + keys[0];
					doorGO = 1;
				}
			}else{
				doorGO = 1;
			}
			
			
			if(doorRO && doorGO){
				opened++;
				// cout<<"opened ";
			}
			// cout<<"@@"<<keys[0]<<" "<<keys[1]<<" "<<keys[2]<<endl;
		}
		
		return opened;
	}
};

int main(){
	int red[] = {41,44,41,57,58,74,84,100,58,2,43,32,82,97,44,13,35,98,96,81,43,77,18,51,27,
 27,39,39,45,82,59,20,28,93,6,39,64,78,28,85,17,56,3,68,4,0,36,80,41,77};

 	int green[] = {67,15,53,36,88,29,26,57,68,99,97,27,51,70,3,49,65,75,35,92,66,0,23,96,38,86,
 98,31,26,75,30,2,92,78,100,99,38,26,85,74,77,15,16,48,100,88,55,93,99,54};
int keys[] = {39,31,34};

	std::vector<int> redv(red,red+50);
	std::vector<int> greenv(green,green+50);
	std::vector<int> keysv(keys,keys+3);

	KeyDungeonDiv2 k;

	cout<<k.countDoors(redv,greenv,keysv)<<endl;


}
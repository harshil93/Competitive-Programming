#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
inline int fast_int()
{
int n=0;
int ch=getchar();
while(ch<48)ch=getchar();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar();
return n;
}


class GUMIAndSongsDiv2 {
public:
	std::vector< vector<int> > songs;
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		
		songs.resize(duration.size());

		for (int i = 0; i < songs.size(); ++i)
		{
			songs[i].resize(songs.size());
		}
		for (int i = 0; i < songs.size(); ++i)
		{
			for (int j = 0; j < songs.size(); ++j)
			{
				
					songs[i][j] = duration[j] + abs(tone[i] - tone[j]);
				
			}
		}
	std::vector<bool> done;
	int timerem = T;
		done.resize(songs.size());
		for (int i = 0; i < done.size(); ++i)
		{
			done[i] = false;
		}
		int maxcount = 0;
		for (int i = 0; i < songs.size(); ++i)
		{
			for (int z = 0; z < done.size(); ++z)
			{
				done[z] = false;
			}

			int k = i;
			done[i] = true;
			timerem = timerem - duration[i];
			int minval = 100000000;
			int ans;
			int minindex;
			int count=0;
				while(timerem>0){
					for (int j = 0; j < count; ++j)
					{
						if(j!=k && songs[k][j]<minval){
							minindex = j;
							minval = songs[k][j];
						}
					}
					ans = timerem;
					timerem = timerem - minval;
					cout<<"time rem "<<timerem<<endl;
					k = minindex;
					count++;
				}
			maxcount = maxcount>count?maxcount:count;

		}
		return maxcount;
	}


};


int main()
{
	int i;
	return 0;
}
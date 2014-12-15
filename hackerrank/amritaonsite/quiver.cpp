#include <iostream>
#include <queue>
using namespace std;

int v[100005];
int ht[100005];
int n,m,c;

int lru(int ws){
	int qs=0;
	int pagefaults=0;
	queue<int> q;
	fill(ht, ht+n+1, 0);
	for (int i=0; i<m; i++){
		if (!ht[v[i]]){
			if (qs<ws){
				q.push(v[i]);
				ht[v[i]]++;
				qs++;
			} else {
				//evict and push
				while (1){
					int e = q.front();
					q.pop();
					ht[e]--;
					if (ht[e]==0) break;
				}
				q.push(v[i]);
				ht[v[i]]++;
			}
			pagefaults++;
		} else {
			q.push(v[i]);
			ht[v[i]]++;
		}
	}
	return pagefaults;
}

int main(){
	int tc;
	cin>>tc;
	while (tc--){
		cin>>n>>m>>c;
		for (int i=0; i<m; i++){
			cin>>v[i];
		}
		int l=m; int r=1; int m;
		if (lru(l)>c){
			cout<<"-1\n";
			continue;
		}
		if (lru(r)<=c){
			cout<<r<<"\n";
			continue;
		}
		while (l-r>1){
			m=(l+r)/2;
			if (lru(m)<=c){
				l=m;
			} else {
				r=m;
			}
		}
		cout<<l<<"\n";
	}
	return 0;
}
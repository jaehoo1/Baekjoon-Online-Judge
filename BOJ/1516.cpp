# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<int> G[501];
int N, in[501], res[501], time[501];

void tsort(void) {
	queue<int> q;
	for(int i=1 ; i<=N ; i++)
		if(!in[i]) {
			q.push(i);
			res[i]=time[i];
		}
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i];
			in[next]--;
			res[next]=max(res[next], res[cur]+time[next]);
			if(!in[next])
				q.push(next);
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++) {
		scanf("%d", &time[i]);
		int num;
		while(scanf("%d", &num)) {
			if(num==-1)
				break;
			G[num].push_back(i);
			in[i]++;
		}
	}
	tsort();
	for(int i=1 ; i<=N ; i++)
		printf("%d\n", res[i]);
	return 0;
}

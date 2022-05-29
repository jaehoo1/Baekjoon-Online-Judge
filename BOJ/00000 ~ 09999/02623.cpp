# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<int> G[1001];
int N, in[1001];

void tsort(void) {
	vector<int> res;
	queue<int> q;
	for(int i=1 ; i<=N ; i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()) {
		int cur=q.front();
		res.push_back(cur);
		q.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			in[G[cur][i]]--;
			if(!in[G[cur][i]])
				q.push(G[cur][i]);
		}
	}
	if(res.size()!=N)
		puts("0");
	else
		for(int i=0 ; i<N ; i++)
			printf("%d\n", res[i]);
}

int main(void) {
	int M;
	scanf("%d%d", &N, &M);
	while(M--) {
		int A, arr[1000];
		scanf("%d", &A);
		for(int i=0 ; i<A ; i++)
			scanf("%d", &arr[i]);
		for(int i=0 ; i<A-1 ; i++) {
			G[arr[i]].push_back(arr[i+1]);
			in[arr[i+1]]++;
		}
	}
	tsort();
	return 0;
}

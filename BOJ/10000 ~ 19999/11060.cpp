# include <cstdio>
# include <queue>

using namespace std;

bool visited[1001];
int N, cou, map[1001];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			if(cur==N)
				return;
			for(int i=1 ; i<=map[cur]&&cur+i<=N ; i++)
				if(!visited[cur+i]) {
					q.push(cur+i);
					visited[cur+i]=true;
				}
		}
		cou++;
	}
}

int main(void) {
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++)
		scanf("%d", &map[i]);
	bfs(1);
	printf("%d", visited[N]?cou:-1);
	return 0;
}

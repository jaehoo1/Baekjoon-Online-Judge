# include <cstdio>
# include <queue>

using namespace std;

int A, K;

int bfs(void) {
	bool visited[1000001]={false, };
	queue<pair<int, int>> q;
	q.push({0, A});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cou=q.front().first;
			int num=q.front().second;
			q.pop();
			if(num==K)
				return cou;
			int next=num+1;
			if(next<=K&&!visited[next]) {
				visited[next]=true;
				q.push({cou+1, next});
			}
			next=num*2;
			if(next<=K&&!visited[next]) {
				visited[next]=true;
				q.push({cou+1, next});
			}
		}
	}
}

int main(void) {
	scanf("%d%d", &A, &K);
	printf("%d", bfs());
	return 0;
}
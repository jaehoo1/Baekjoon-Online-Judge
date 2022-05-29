# include <cstdio>
# include <queue>

using namespace std;

int N, b, cou, arr[10001];
bool visited[10001];

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			if(cur==b)
				return;
			for(int i=0 ; cur+i<=N ; i+=arr[cur])
				if(!visited[cur+i]) {
					q.push(cur+i);
					visited[cur+i]=true;
				}
			for(int i=0 ; cur+i>0 ; i-=arr[cur])
				if(!visited[cur+i]) {
					q.push(cur+i);
					visited[cur+i]=true;
				}
		}
		cou++;
	}
}

int main(void) {
	int a;
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++)
		scanf("%d", &arr[i]);
	scanf("%d%d", &a, &b);
	bfs(a);
	if(visited[b])
		printf("%d", cou);
	else
		puts("-1");
	return 0;
}

# include <iostream>
# include <queue>
# include <algorithm>

using namespace std;
queue<int> q;
int K, cou=0, parent[200004];
bool visited[200004];

void bfs(int n) {
	q.push(n);
	visited[n]=true;
	while(!q.empty()) {
		int size=q.size();
		for(int i=0 ; i<size ; i++) {
			int cur=q.front();
			q.pop();
			if(cur==K)
				return;
			if(cur-1>=0&&!visited[cur-1]) {
				q.push(cur-1);
				visited[cur-1]=true;
				parent[cur-1]=cur;
			}
			if(cur+1<=100002&&!visited[cur+1]) {
				q.push(cur+1);
				visited[cur+1]=true;
				parent[cur+1]=cur;
			}
			if(cur*2<=100002&&!visited[cur*2]) {
				q.push(cur*2);
				visited[cur*2]=true;
				parent[cur*2]=cur;
			}
		}
		cou++;
	}
}

int main(void) {
	int N, arr[100001];
	scanf("%d%d", &N, &K);
	bfs(N);
	printf("%d\n", cou);
	arr[0]=K;
	for(int i=1 ; i<=cou ; i++) {
		arr[i]=parent[K];
		K=parent[K];
	}
	reverse(arr, arr+cou+1);
	for(int i=0 ; i<=cou ; i++)
		printf("%d ", arr[i]);
	return 0;
}

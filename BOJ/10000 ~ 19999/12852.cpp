# include <cstdio>
# include <queue>
# include <algorithm>

using namespace std;

int cou, parent[1000001];
bool visited[1000001];
queue<int> q;

void bfs(int n) {
	q.push(n);
	visited[n]=true;
	while(!q.empty()) {
		int size=q.size();
		for(int i=0 ; i<size ; i++) {
			int cur=q.front();
			q.pop();
			if(cur==1)
				return;
			if(cur%3==0&&!visited[cur/3]) {
				q.push(cur/3);
				visited[cur/3]=true;
				parent[cur/3]=cur;
			}
			if(cur%2==0&&!visited[cur/2]) {
				q.push(cur/2);
				visited[cur/2]=true;
				parent[cur/2]=cur;
			}
			if(!visited[cur-1]) {
				q.push(cur-1);
				visited[cur-1]=true;
				parent[cur-1]=cur;
			}
		}
		cou++;
	}
}

int main(void) {
	int N, p=1;
	scanf("%d", &N);
	bfs(N);
	printf("%d\n", cou);
	int arr[cou+1]={1};
	for(int i=1 ; i<=cou ; i++) {
		arr[i]=parent[p];
		p=parent[p];
	}
	reverse(arr, arr+cou+1);
	for(int i=0 ; i<=cou ; i++)
		printf("%d ", arr[i]);
	return 0;
}

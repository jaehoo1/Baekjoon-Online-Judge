# include <iostream>
# include <queue>

using namespace std;

int n, map[100001];
bool visited[100001];
queue<int> q;

bool cango(int cur, char vec) {
	int jump=map[cur];
	if(vec=='L') {
		if(cur-jump<1)return false;
		if(visited[cur-jump])return false;
		return true;
	} else if(vec=='R') {
		if(cur+jump>n)return false;
		if(visited[cur+jump])return false;
		return true;
	}
}
void bfs(int x) {
	q.push(x);
	visited[x]=true;
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		if(cango(cur, 'L')) {
			q.push(cur-map[cur]);
			visited[cur-map[cur]]=true;
		}
		if(cango(cur, 'R')) {
			q.push(cur+map[cur]);
			visited[cur+map[cur]]=true;
		}
	}
}

int main(void) {
	int cou=0, s;
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++)
		scanf("%d", &map[i]);
	scanf("%d", &s);
	bfs(s);
	for(int i=1 ; i<=n ; i++)
		if(visited[i])
			cou++;
	printf("%d", cou);
	return 0;
}

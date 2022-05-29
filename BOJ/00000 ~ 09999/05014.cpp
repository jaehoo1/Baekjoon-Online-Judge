# include <iostream>
# include <queue>

using namespace std;
queue<int> q;
int F, G, U, D, cou;
bool visited[1000001], reach;

void bfs(int n) {
	q.push(n);
	visited[n]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			if(cur==G) {
				reach=true;
				return;
			}
			if(cur+U<=F&&!visited[cur+U]) {
				q.push(cur+U);
				visited[cur+U]=true;
			}
			if(cur-D>=1&&!visited[cur-D]) {
				q.push(cur-D);
				visited[cur-D]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	int S;
	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
	bfs(S);
	if(reach)
		printf("%d", cou);
	else
		puts("use the stairs");
	return 0;
}

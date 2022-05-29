# include <cstdio>
# include <queue>

using namespace std;

int S, cou;
bool visited[2001][2001];

void bfs(void) {
	queue<pair<int, int>> q;
	visited[1][0]=true;
	q.push({1, 0});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curimti=q.front().first;
			int curclip=q.front().second;
			q.pop();
			if(curimti==S)
				return;
			if(!visited[curimti][curimti]) {
				visited[curimti][curimti]=true;
				q.push({curimti, curimti});
			}
			if(curimti+curclip<=2000&&!visited[curimti+curclip][curclip]) {
				visited[curimti+curclip][curclip]=true;
				q.push({curimti+curclip, curclip});
			}
			if(curimti-1>=0&&!visited[curimti-1][curclip]) {
				visited[curimti-1][curclip]=true;
				q.push({curimti-1, curclip});
			}
		}
		cou++;
	}
}

int main(void) {
	scanf("%d", &S);
	bfs();
	printf("%d", cou);
	return 0;
}

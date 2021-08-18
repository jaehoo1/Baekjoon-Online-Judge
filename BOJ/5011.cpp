# include <cstdio>
# include <queue>

using namespace std;

int n;
char map[1000][1001];

typedef struct {
	int x, y;
}pos;
bool bfs(pos p) {
	queue<pos> q;
	bool visited[1000][1000]={false, };
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==n-1&&cur.y==n-1)
				return true;
			if(cur.x)if(map[cur.x-1][cur.y]!='#'&&!visited[cur.x-1][cur.y]) {
				q.push({cur.x-1, cur.y});
				visited[cur.x-1][cur.y]=true;
			}
			if(cur.x<n-1)if(map[cur.x+1][cur.y]!='#'&&!visited[cur.x+1][cur.y]) {
				q.push({cur.x+1, cur.y});
				visited[cur.x+1][cur.y]=true;
			}
			if(cur.y)if(map[cur.x][cur.y-1]!='#'&&!visited[cur.x][cur.y-1]) {
				q.push({cur.x, cur.y-1});
				visited[cur.x][cur.y-1]=true;
			}
			if(cur.y<n-1)if(map[cur.x][cur.y+1]!='#'&&!visited[cur.x][cur.y+1]) {
				q.push({cur.x, cur.y+1});
				visited[cur.x][cur.y+1]=true;
			}
		}
	}
	return false;
}

int main(void) {
	long long dp[1000][1000]={1, };
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++)
		scanf("%s", map[i]);
	if(!bfs({0, 0})) {
		puts("INCONCEIVABLE");
		return 0;
	}
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			if(map[i][j]=='.')
				if(!i&&!j)continue;
				else if(!i)dp[i][j]=dp[i][j-1];
				else if(!j)dp[i][j]=dp[i-1][j];
				else	dp[i][j]=(dp[i-1][j]%2147483647+dp[i][j-1]%2147483647)%2147483647;
	if(dp[n-1][n-1])
		printf("%lld", dp[n-1][n-1]);
	else
		puts("THE GAME IS A LIE");
	return 0;
}

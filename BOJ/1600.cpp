# include <cstdio>
# include <queue>
# include <cstring>

using namespace std;

typedef struct {
	int x, y, z;
}pos;

queue<pos> q;
int K, H, W, cou;
bool map[200][200], visited[200][200][31];

bool cango(pos cur, char *vec) {
	if(!strcmp(vec, "UR")) {
		if(cur.x>1&&cur.y<W-1&&cur.z<K)if(!map[cur.x-2][cur.y+1]&&!visited[cur.x-2][cur.y+1][cur.z+1])return true;
	} else if(!strcmp(vec, "RU")) {
		if(cur.x&&cur.y<W-2&&cur.z<K)if(!map[cur.x-1][cur.y+2]&&!visited[cur.x-1][cur.y+2][cur.z+1])return true;
	} else if(!strcmp(vec, "RD")) {
		if(cur.x<H-1&&cur.y<W-2&&cur.z<K)if(!map[cur.x+1][cur.y+2]&&!visited[cur.x+1][cur.y+2][cur.z+1])return true;
	} else if(!strcmp(vec, "DR")) {
		if(cur.x<H-2&&cur.y<W-1&&cur.z<K)if(!map[cur.x+2][cur.y+1]&&!visited[cur.x+2][cur.y+1][cur.z+1])return true;
	} else if(!strcmp(vec, "DL")) {
		if(cur.x<H-2&&cur.y&&cur.z<K)if(!map[cur.x+2][cur.y-1]&&!visited[cur.x+2][cur.y-1][cur.z+1])return true;
	} else if(!strcmp(vec, "LD")) {
		if(cur.x<H-1&&cur.y>1&&cur.z<K)if(!map[cur.x+1][cur.y-2]&&!visited[cur.x+1][cur.y-2][cur.z+1])return true;
	} else if(!strcmp(vec, "LU")) {
		if(cur.x&&cur.y>1&&cur.z<K)if(!map[cur.x-1][cur.y-2]&&!visited[cur.x-1][cur.y-2][cur.z+1])return true;
	} else if(!strcmp(vec, "UL")) {
		if(cur.x>1&&cur.y&&cur.z<K)if(!map[cur.x-2][cur.y-1]&&!visited[cur.x-2][cur.y-1][cur.z+1])return true;
	} else if(!strcmp(vec, "U")) {
		if(cur.x)if(!map[cur.x-1][cur.y]&&!visited[cur.x-1][cur.y][cur.z])return true;
	} else if(!strcmp(vec, "D")) {
		if(cur.x<H-1)if(!map[cur.x+1][cur.y]&&!visited[cur.x+1][cur.y][cur.z])return true;
	} else if(!strcmp(vec, "L")) {
		if(cur.y)if(!map[cur.x][cur.y-1]&&!visited[cur.x][cur.y-1][cur.z])return true;
	} else if(!strcmp(vec, "R")) {
		if(cur.y<W-1)if(!map[cur.x][cur.y+1]&&!visited[cur.x][cur.y+1][cur.z])return true;
	}
	return false;
}
void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y][p.z]=true;
	while(!q.empty()) {
		int size=q.size();
		for(int i=0 ; i<size ; i++) {
			pos cur=q.front();
			q.pop();
			if(cur.x==H-1&&cur.y==W-1)
				return;
			if(cango(cur, "UR")) {
				q.push({cur.x-2, cur.y+1, cur.z+1});
				visited[cur.x-2][cur.y+1][cur.z+1]=true;
			}
			if(cango(cur, "RU")) {
				q.push({cur.x-1, cur.y+2, cur.z+1});
				visited[cur.x-1][cur.y+2][cur.z+1]=true;
			}
			if(cango(cur, "RD")) {
				q.push({cur.x+1, cur.y+2, cur.z+1});
				visited[cur.x+1][cur.y+2][cur.z+1]=true;
			}
			if(cango(cur, "DR")) {
				q.push({cur.x+2, cur.y+1, cur.z+1});
				visited[cur.x+2][cur.y+1][cur.z+1]=true;
			}
			if(cango(cur, "DL")) {
				q.push({cur.x+2, cur.y-1, cur.z+1});
				visited[cur.x+2][cur.y-1][cur.z+1]=true;
			}
			if(cango(cur, "LD")) {
				q.push({cur.x+1, cur.y-2, cur.z+1});
				visited[cur.x+1][cur.y-2][cur.z+1]=true;
			}
			if(cango(cur, "LU")) {
				q.push({cur.x-1, cur.y-2, cur.z+1});
				visited[cur.x-1][cur.y-2][cur.z+1]=true;
			}
			if(cango(cur, "UL")) {
				q.push({cur.x-2, cur.y-1, cur.z+1});
				visited[cur.x-2][cur.y-1][cur.z+1]=true;
			}
			if(cango(cur, "U")) {
				q.push({cur.x-1, cur.y, cur.z});
				visited[cur.x-1][cur.y][cur.z]=true;
			}
			if(cango(cur, "D")) {
				q.push({cur.x+1, cur.y, cur.z});
				visited[cur.x+1][cur.y][cur.z]=true;
			}
			if(cango(cur, "L")) {
				q.push({cur.x, cur.y-1, cur.z});
				visited[cur.x][cur.y-1][cur.z]=true;
			}
			if(cango(cur, "R")) {
				q.push({cur.x, cur.y+1, cur.z});
				visited[cur.x][cur.y+1][cur.z]=true;
			}
		}
		cou++;
	}
}
bool goal(void) {
	for(int i=0 ; i<=K ; i++)
		if(visited[H-1][W-1][i])
			return true;
	return false;
}

int main(void) {
	scanf("%d%d%d", &K, &W, &H);
	for(int i=0 ; i<H ; i++)
		for(int j=0 ; j<W ; j++)
			scanf("%1d", &map[i][j]);
	bfs({0, 0, 0});
	if(goal())
		printf("%d", cou);
	else
		puts("-1");
	return 0;
}

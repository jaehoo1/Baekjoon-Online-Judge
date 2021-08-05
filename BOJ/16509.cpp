# include <iostream>
# include <queue>
# include <cstring>

using namespace std;

typedef struct {
	int x, y;
}pos;

bool visited[10][9];
int R2, C2, cou;
queue<pos> q;

bool cango(pos cur, char *vec) {
	if(!strcmp(vec, "UL")) {
		if(cur.x<3||cur.y<2)return false;
		if(visited[cur.x-3][cur.y-2])return false;
		if(cur.x-1==R2&&cur.y==C2)return false;
		if(cur.x-2==R2&&cur.y-1==C2)return false;
	} else if(!strcmp(vec, "UR")) {
		if(cur.x<3||cur.y>6)return false;
		if(visited[cur.x-3][cur.y+2])return false;
		if(cur.x-1==R2&&cur.y==C2)return false;
		if(cur.x-2==R2&&cur.y+1==C2)return false;
	} else if(!strcmp(vec, "RU")) {
		if(cur.x<2||cur.y>5)return false;
		if(visited[cur.x-2][cur.y+3])return false;
		if(cur.x==R2&&cur.y+1==C2)return false;
		if(cur.x-1==R2&&cur.y+2==C2)return false;
	} else if(!strcmp(vec, "RD")) {
		if(cur.x>7||cur.y>5)return false;
		if(visited[cur.x+2][cur.y+3])return false;
		if(cur.x==R2&&cur.y+1==C2)return false;
		if(cur.x+1==R2&&cur.y+2==C2)return false;
	} else if(!strcmp(vec, "DR")) {
		if(cur.x>6||cur.y>6)return false;
		if(visited[cur.x+3][cur.y+2])return false;
		if(cur.x+1==R2&&cur.y==C2)return false;
		if(cur.x+2==R2&&cur.y+1==C2)return false;
	} else if(!strcmp(vec, "DL")) {
		if(cur.x>6||cur.y<2)return false;
		if(visited[cur.x+3][cur.y-2])return false;
		if(cur.x+1==R2&&cur.y==C2)return false;
		if(cur.x+2==R2&&cur.y-1==C2)return false;
	} else if(!strcmp(vec, "LD")) {
		if(cur.x>7||cur.y<3)return false;
		if(visited[cur.x+2][cur.y-3])return false;
		if(cur.x==R2&&cur.y-1==C2)return false;
		if(cur.x+1==R2&&cur.y-2==C2)return false;
	} else if(!strcmp(vec, "LU")) {
		if(cur.x<2||cur.y<3)return false;
		if(visited[cur.x-2][cur.y-3])return false;
		if(cur.x==R2&&cur.y-1==C2)return false;
		if(cur.x-1==R2&&cur.y-2==C2)return false;
	}
	return true;
}
void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==R2&&cur.y==C2)
				return;
			if(cango(cur, "UL")) {
				q.push({cur.x-3, cur.y-2});
				visited[cur.x-3][cur.y-2]=true;
			}
			if(cango(cur, "UR")) {
				q.push({cur.x-3, cur.y+2});
				visited[cur.x-3][cur.y+2]=true;
			}
			if(cango(cur, "RU")) {
				q.push({cur.x-2, cur.y+3});
				visited[cur.x-2][cur.y+3]=true;
			}
			if(cango(cur, "RD")) {
				q.push({cur.x+2, cur.y+3});
				visited[cur.x+2][cur.y+3]=true;
			}
			if(cango(cur, "DR")) {
				q.push({cur.x+3, cur.y+2});
				visited[cur.x+3][cur.y+2]=true;
			}
			if(cango(cur, "DL")) {
				q.push({cur.x+3, cur.y-2});
				visited[cur.x+3][cur.y-2]=true;
			}
			if(cango(cur, "LD")) {
				q.push({cur.x+2, cur.y-3});
				visited[cur.x+2][cur.y-3]=true;
			}
			if(cango(cur, "LU")) {
				q.push({cur.x-2, cur.y-3});
				visited[cur.x-2][cur.y-3]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	int R1, C1;
	scanf("%d%d%d%d", &R1, &C1, &R2, &C2);
	bfs({R1, C1});
	if(visited[R2][C2])
		printf("%d", cou);
	else
		puts("-1");
	return 0;
}

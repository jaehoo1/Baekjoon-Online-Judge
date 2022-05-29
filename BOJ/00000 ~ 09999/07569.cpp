# include <cstdio>
# include <queue>

using namespace std;

typedef struct { int x, y, z; }pos;

int N, M, H, map[100][100][100];
vector<pos> arr;

int bfs(void) {
	int cou=-1, dx[]={-1, 1, 0, 0, 0, 0}, dy[]={0, 0, -1, 1, 0, 0}, dz[]={0, 0, 0, 0, -1, 1};
	queue<pos> q;
	for(int i=0 ; i<arr.size() ; i++)
		q.push(arr[i]);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			for(int i=0 ; i<6 ; i++) {
				int x=dx[i]+cur.x;
				int y=dy[i]+cur.y;
				int z=dz[i]+cur.z;
				if(x<0||x>H-1||y<0||y>N-1||z<0||z>M-1)
					continue;
				if(!map[x][y][z]) {
					map[x][y][z]=1;
					q.push({x, y, z});
				}
			}
		}
		cou++;
	}
	for(int i=0 ; i<H ; i++)
		for(int j=0 ; j<N ; j++)
			for(int k=0 ; k<M ; k++)
				if(!map[i][j][k])
					return -1;
	return cou;
}

int main(void) {
	scanf("%d%d%d", &M, &N, &H);
	for(int i=0 ; i<H ; i++)
		for(int j=0 ; j<N ; j++)
			for(int k=0 ; k<M ; k++) {
				scanf("%d", &map[i][j][k]);
				if(map[i][j][k]==1)
					arr.push_back({i, j, k});
			}
	printf("%d", bfs());
	return 0;
}

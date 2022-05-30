# include <cstdio>
# include <cmath>
# include <vector>
# include <queue>

using namespace std;

int N, L, R, arr[50][50], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
bool border[50][50], isallay;

void allay(void) {
	int nx, ny, dif;
	isallay=false;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			border[i][j]=false;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			for(int k=0 ; k<4 ; k++) {
				nx=i+dx[k];
				ny=j+dy[k];
				if(nx<0||nx>=N||ny<0||ny>=N)
					continue;
				dif=abs(arr[i][j]-arr[nx][ny]);
				if(dif>=L&&dif<=R) {
					isallay=true;
					border[i][j]=border[nx][ny]=true;
				}
			}
}
void bfs(int startx, int starty) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	int sum=0;
	q.push({startx, starty});
	border[startx][starty]=false;
	while(!q.empty()) {
		int curx=q.front().first;
		int cury=q.front().second;
		q.pop();
		sum+=arr[curx][cury];
		v.push_back({curx, cury});
		for(int i=0 ; i<4 ; i++) {
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N)
				continue;
			int dif=abs(arr[curx][cury]-arr[nx][ny]);
			if(border[nx][ny]&&dif>=L&&dif<=R) {
				q.push({nx, ny});
				border[nx][ny]=false;
			}
		}
	}
	sum/=v.size();
	for(int i=0 ; i<v.size() ; i++)
		arr[v[i].first][v[i].second]=sum;
}

int main(void) {
	int cou=0;
	scanf("%d%d%d", &N, &L, &R);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			scanf("%d", &arr[i][j]);
	while(true) {
		allay();
		if(!isallay)
			break;
		cou++;
		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<N ; j++)
				if(border[i][j])
					bfs(i, j);
	}
	printf("%d", cou);
	return 0;
}
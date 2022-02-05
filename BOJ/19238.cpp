# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

typedef struct { int x, y; }pos;
typedef struct { pos s, d; }guest;

int N, M, map[20][20], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
guest arr[400];

bool cmp(const pos &a, const pos &b) {
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
pair<int, pos> bfs(pos taxi) {
	queue<pos> q;
	vector<pos> v;
	int dist=0;
	bool visited[20][20]={false, };
	q.push(taxi);
	visited[taxi.x][taxi.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(map[cur.x][cur.y]<0) {
				v.push_back(cur);
				continue;
			}
			for(int i=0 ; i<4 ; i++) {
				pos next;
				next.x=cur.x+dx[i];
				next.y=cur.y+dy[i];
				if(next.x<0||next.x>=N||next.y<0||next.y>=N)
					continue;
				if(map[next.x][next.y]==1||visited[next.x][next.y])
					continue;
				q.push(next);
				visited[next.x][next.y]=true;
			}
		}
		if(v.size())
			break;
		dist++;
	}
	if(v.size()) {
		sort(v.begin(), v.end(), cmp);
		return {dist, v[0]};
	}
	return {-1, {-1, -1}};
}
pair<int, pos> drive(pos gt) {
	queue<pos> q;
	int dist=0;
	bool visited[20][20]={false, };
	pos dest=arr[-map[gt.x][gt.y]-1].d;
	q.push(gt);
	visited[gt.x][gt.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==dest.x&&cur.y==dest.y)
				return {dist, dest};
			for(int i=0 ; i<4 ; i++) {
				pos next;
				next.x=cur.x+dx[i];
				next.y=cur.y+dy[i];
				if(next.x<0||next.x>=N||next.y<0||next.y>=N)
					continue;
				if(map[next.x][next.y]==1||visited[next.x][next.y])
					continue;
				q.push(next);
				visited[next.x][next.y]=true;
			}
		}
		dist++;
	}
	return {-1, {-1, -1}};
}

int main(void) {
	int fuel, remainguest;
	pos taxi;
	scanf("%d%d%d", &N, &M, &fuel);
	remainguest=M;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			scanf("%d", &map[i][j]);
	scanf("%d%d", &taxi.x, &taxi.y);
	taxi.x--;
	taxi.y--;
	for(int i=0 ; i<M ; i++) {
		scanf("%d%d%d%d", &arr[i].s.x, &arr[i].s.y, &arr[i].d.x, &arr[i].d.y);
		arr[i].s.x--;
		arr[i].s.y--;
		arr[i].d.x--;
		arr[i].d.y--;
		map[arr[i].s.x][arr[i].s.y]=-(i+1);
	}
	while(remainguest) {
		pair<int, pos> p=bfs(taxi);
		if(p.first==-1)
			break;
		fuel-=p.first;
		if(fuel<0)
			break;
		pos gt=p.second;
		p=drive(gt);
		map[gt.x][gt.y]=0;
		if(p.first==-1)
			break;
		fuel-=p.first;
		if(fuel<0)
			break;
		taxi=p.second;
		fuel+=p.first*2;
		remainguest--;
	}
	printf("%d", remainguest?-1:fuel);
	return 0;
}

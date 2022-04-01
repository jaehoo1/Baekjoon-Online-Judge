# include <cstdio>
# include <vector>
# include <queue>
# include <tuple>
# include <algorithm>

using namespace std;

vector<int> res;
int A, B, C;
bool visited[201][201][201];

void bfs(tuple<int, int, int> t) {
	queue<tuple<int, int, int>> q;
	q.push(t);
	visited[get<0>(t)][get<1>(t)][get<2>(t)]=true;
	while(!q.empty()) {
		tuple<int, int, int> cur=q.front();
		int a=get<0>(cur), b=get<1>(cur), c=get<2>(cur);
		q.pop();
		if(!a)
			res.push_back(c);
		if(!visited[a-min(a, B-b)][b+min(a, B-b)][c]) {
			q.push(make_tuple(a-min(a, B-b), b+min(a, B-b), c));
			visited[a-min(a, B-b)][b+min(a, B-b)][c]=true;
		}
		if(!visited[a-min(a, C-c)][b][c+min(a, C-c)]) {
			q.push(make_tuple(a-min(a, C-c), b, c+min(a, C-c)));
			visited[a-min(a, C-c)][b][c+min(a, C-c)]=true;
		}
		if(!visited[a+min(b, A-a)][b-min(b, A-a)][c]) {
			q.push(make_tuple(a+min(b, A-a), b-min(b, A-a), c));
			visited[a+min(b, A-a)][b-min(b, A-a)][c]=true;
		}
		if(!visited[a][b-min(b, C-c)][c+min(b, C-c)]) {
			q.push(make_tuple(a, b-min(b, C-c), c+min(b, C-c)));
			visited[a][b-min(b, C-c)][c+min(b, C-c)]=true;
		}
		if(!visited[a+min(c, A-a)][b][c-min(c, A-a)]) {
			q.push(make_tuple(a+min(c, A-a), b, c-min(c, A-a)));
			visited[a+min(c, A-a)][b][c-min(c, A-a)]=true;
		}
		if(!visited[a][b+min(c, B-b)][c-min(c, B-b)]) {
			q.push(make_tuple(a, b+min(c, B-b), c-min(c, B-b)));
			visited[a][b+min(c, B-b)][c-min(c, B-b)]=true;
		}
	}
}

int main(void) {
	scanf("%d%d%d", &A, &B, &C);
	bfs(make_tuple(0, 0, C));
	sort(res.begin(), res.end());
	for(int i=0 ; i<res.size() ; i++)
		printf("%d ", res[i]);
	return 0;
}

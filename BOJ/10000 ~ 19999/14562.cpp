# include <cstdio>
# include <queue>

using namespace std;

int bfs(int S, int T) {
	int cou=0;
	queue<pair<int, int>> q;
	q.push({S, T});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curS=q.front().first;
			int curT=q.front().second;
			q.pop();
			if(curS==curT)
				return cou;
			if(curS>curT)
				continue;
			q.push({curS*2, curT+3});
			q.push({curS+1, curT});
		}
		cou++;
	}
}

int main(void) {
	int C, S, T;
	scanf("%d", &C);
	while(C--) {
		scanf("%d%d", &S, &T);
		printf("%d\n", bfs(S, T));
	}
	return 0;
}
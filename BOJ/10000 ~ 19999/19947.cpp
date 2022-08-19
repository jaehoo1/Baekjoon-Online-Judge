# include <cstdio>
# include <queue>

using namespace std;

int H, Y;

int interest(int money, int rate) { return (double)money/100*rate; }
int bfs(void) {
	int max=0;
	queue<pair<int, int>> q;
	q.push({H, Y});
	while(!q.empty()) {
		int money=q.front().first;
		int year=q.front().second;
		q.pop();
		if(!year) {
			if(money>max)
				max=money;
			continue;
		}
		if(year>=5)
			q.push({money+interest(money, 35), year-5});
		if(year>=3)
			q.push({money+interest(money, 20), year-3});
		q.push({money+interest(money, 5), year-1});
	}
	return max;
}

int main(void) {
	scanf("%d%d", &H, &Y);
	printf("%d", bfs());
	return 0;
}
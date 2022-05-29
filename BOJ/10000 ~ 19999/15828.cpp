# include <cstdio>
# include <queue>

using namespace std;

int main(void) {
	int N, num;
	queue<int> q;
	scanf("%d", &N);
	while(scanf("%d", &num)) {
		if(num==-1)
			break;
		if(!num)
			q.pop();
		else if(q.size()<N)
			q.push(num);
	}
	if(q.empty())
		puts("empty");
	else
		while(!q.empty()) {
			printf("%d ", q.front());
			q.pop();
		}
	return 0;
}

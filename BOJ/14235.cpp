# include <cstdio>
# include <queue>

using namespace std;

int main(void) {
	int n, a, num;
	priority_queue<int> pq;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &a);
		if(a)
			while(a--) {
				scanf("%d", &num);
				pq.push(num);
			}
		else
			if(pq.empty())
				puts("-1");
			else {
				int front=pq.top();
				pq.pop();
				printf("%d\n", front);
			}
	}
	return 0;
}

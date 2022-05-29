# include <cstdio>
# include <queue>

using namespace std;

int main(void) {
	int N, num;
	priority_queue<int, vector<int>, greater<int>> pq;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++) {
			scanf("%d", &num);
			if(pq.size()<N)
				pq.push(num);
			else if(pq.top()<num) {
					pq.pop();
					pq.push(num);
				}
		}
	printf("%d", pq.top());
	return 0;
}

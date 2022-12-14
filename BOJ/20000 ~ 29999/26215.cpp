# include <cstdio>
# include <queue>

using namespace std;

int main(void) {
	int N, a, time;
	priority_queue<int> pq;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &a);
		pq.push(a);
	}
	for(time=0 ; time<1440&&!pq.empty() ; time++) {
		int first=pq.top();
		int second=-1;
		pq.pop();
		if(!pq.empty()) {
			second=pq.top();
			pq.pop();
		}
		if(--first)
			pq.push(first);
		if(second!=-1&&--second)
			pq.push(second);
	}
	printf("%d", pq.empty()?time:-1);
	return 0;
}
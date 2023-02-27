# include <cstdio>
# include <queue>

using namespace std;

int main(void) {
	int N;
	long long a, first, second;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%lld", &a);
		if(a)
			pq.push(a);
	}
	while(pq.size()!=1) {
		first=pq.top();
		pq.pop();
		second=pq.top();
		pq.pop();
		pq.push(first==second?first*2:second);
	}
	printf("%lld", pq.top());
	return 0;
}
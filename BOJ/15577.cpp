# include <cstdio>
# include <queue>

using namespace std;

int main(void) {
	int N, num;
	priority_queue<double, vector<double>, greater<double>> pq;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &num);
		pq.push((double)num);
	}
	while(pq.size()>1) {
		double first=pq.top();
		pq.pop();
		double second=pq.top();
		pq.pop();
		pq.push((first+second)/2);
	}
	printf("%lf", pq.top());
	return 0;
}

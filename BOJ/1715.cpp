# include <iostream>
# include <queue>
# include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	int N, num, first, second, sum=0;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &num);
		pq.push(num);
	}
	for(int i=1 ; i<N ; i++) {
		first=pq.top();		pq.pop();
		second=pq.top();	pq.pop();
		sum+=first+second;
		pq.push(first+second);
	}
	printf("%d", sum);
	return 0;
}

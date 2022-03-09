# include <cstdio>
# include <queue>
# define	LL	long long

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) {
		int K, num;
		LL res=0;
		priority_queue<LL, vector<LL>, greater<LL>> pq;
		scanf("%d", &K);
		for(int i=0 ; i<K ; i++) {
			scanf("%d", &num);
			pq.push(num);
		}
		while(pq.size()>1) {
			LL first=pq.top();
			pq.pop();
			LL second=pq.top();
			pq.pop();
			res+=first+second;
			pq.push(first+second);
		}
		printf("%lld\n", res);
	}
	return 0;
}

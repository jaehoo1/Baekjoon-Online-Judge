# include <cstdio>
# include <queue>
# define	LL	long long

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		priority_queue<LL, vector<LL>, greater<LL>> pq;
		LL num, res=1;
		scanf("%d", &N);
		for(int i=0 ; i<N ; i++) {
			scanf("%lld", &num);
			pq.push(num);
		}
		while(pq.size()>1) {
			LL first=pq.top();
			pq.pop();
			LL second=pq.top();
			pq.pop();
			LL temp=first*second;
			res=(res*(temp%1000000007))%1000000007;
			pq.push(temp);
		}
		printf("%lld\n", res);
	}
	return 0;
}

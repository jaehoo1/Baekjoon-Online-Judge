# include <stdio.h>

long long tree[1000001];
int N;

void update(int idx, long long diff) {
	while(idx<=N) {
		tree[idx]+=diff;
		idx+=idx&-idx;
	}
}
long long prefix_sum(int idx) {
	long long res=0;
	while(idx) {
		res+=tree[idx];
		idx-=idx&-idx;
	}
	return res;
}
long long interval_sum(int begin, int end) {
	return prefix_sum(end)-prefix_sum(begin-1);
}

int main(void) {
	int M, K, i, a, b;
	long long num, arr[1000001], c;
	scanf("%d%d%d", &N, &M, &K);
	for(i=1 ; i<=N ; i++) {
		scanf("%lld", &arr[i]);
		update(i, arr[i]);
	}
	for(i=0 ; i<M+K ; i++) {
		scanf("%d%d%lld", &a, &b, &c);
		if(a==1) {
			update(b, c-arr[b]);
			arr[b]=c;
		} else if(a==2)
			printf("%lld\n", interval_sum(b, c));
	}
	return 0;
}

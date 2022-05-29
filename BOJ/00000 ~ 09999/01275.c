# include <stdio.h>
# define	LL	long long

int N;
LL tree[100001];

void swap(int *a, int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}
void update(int idx, LL diff) {
	while(idx<=N) {
		tree[idx]+=diff;
		idx+=idx&-idx;
	}
}
LL prefix_sum(int idx) {
	LL res=0;
	while(idx) {
		res+=tree[idx];
		idx-=idx&-idx;
	}
	return res;
}
LL interval_sum(int begin, int end) {
	return prefix_sum(end)-prefix_sum(begin-1);
}

int main(void) {
	int Q, arr[100001], i, x, y, a, b;
	scanf("%d%d", &N, &Q);
	for(i=1 ; i<=N ; i++) {
		scanf("%d", &arr[i]);
		update(i, arr[i]);
	}
	while(Q--) {
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if(x>y)
			swap(&x, &y);
		printf("%lld\n", interval_sum(x, y));
		update(a, (LL)b-arr[a]);
		arr[a]=b;
	}
	return 0;
}

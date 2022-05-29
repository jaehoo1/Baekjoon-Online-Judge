# include <stdio.h>

int N, arr[1000001];
long long tree[1000001];

void swap(int *a, int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}
void update(int idx, int diff) {
	while(idx<=N) {
		tree[idx]+=diff;
		idx+=(idx&-idx);
	}
}
long long prefix_sum(int idx) {
	long long res=0;
	while(idx) {
		res+=tree[idx];
		idx-=(idx&-idx);
	}
	return res;
}
long long interval_sum(int begin, int end) {
	return prefix_sum(end)-prefix_sum(begin-1);
}

int main(void) {
	int M, a, b, c;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d%d", &a, &b, &c);
		if(a) {
			update(b, c-arr[b]);
			arr[b]=c;
		}
		else {
			if(b>c)
				swap(&b, &c);
			printf("%lld\n", interval_sum(b, c));
		}
	}
	return 0;
}

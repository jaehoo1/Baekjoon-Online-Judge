# include <stdio.h>

int N, arr[100001], tree[100001];

int min(int a, int b) { return a<b?a:b; }
void update(int idx, int num) {
	while(idx<=N) {
		tree[idx]=min(num, tree[idx]);
		idx+=idx&-idx;
	}
}
int interval(int begin, int end) {
	int idx=end, res=1000000000;
	while(idx>=begin)
		if(idx-(idx&-idx)>=begin-1) {
			res=min(res, tree[idx]);
			idx-=idx&-idx;
		} else
			res=min(res, arr[idx--]);
	return res;
}

int main(void) {
	int M, a, b, i;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		tree[i]=1000000000;
	for(i=1 ; i<=N ; i++) {
		scanf("%d", &arr[i]);
		update(i, arr[i]);
	}
	while(M--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", interval(a, b));
	}
	return 0;
}

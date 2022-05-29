# include <stdio.h>

long long tree[4000000];

void update(int node, int start, int end, int idx, long long diff) {
	int mid=(start+end)/2;
	if(idx<start||idx>end)
		return;
	if(start==end) {
		tree[node]+=diff;
		return;
	}
	update(node*2, start, mid, idx, diff);
	update(node*2+1, mid+1, end, idx, diff);
	tree[node]=tree[node*2]+tree[node*2+1];
}
long long query(int node, int start, int end, int left, int right) {
	int mid=(start+end)/2;
	if(left>end||right<start)
		return 0;
	if(left<=start&&end<=right)
		return tree[node];
	return query(node*2, start, mid, left, right)+query(node*2+1, mid+1, end, left, right);
}

int main(void) {
	int N, Q, a, b, c;
	scanf("%d%d", &N, &Q);
	while(Q--) {
		scanf("%d%d%d", &a, &b, &c);
		if(a==1)
			update(1, 0, N-1, b-1, c);
		else if(a==2)
			printf("%lld\n", query(1, 0, N-1, b-1, c-1));		
	}
	return 0;
}

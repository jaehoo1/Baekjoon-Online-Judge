# include <stdio.h>

int arr[100000], tree[400000];

int min(int a, int b) { return a<b?a:b; }
int maketree(int node, int start, int end) {
	int left, right, mid=(start+end)/2;
	if(start==end)
		return tree[node]=arr[start];
	left=maketree(node*2, start, mid);
	right=maketree(node*2+1, mid+1, end);
	return tree[node]=min(left, right);
}
int query(int node, int start, int end, int left, int right) {
	int mid=(start+end)/2;
	if(left>end||right<start)
		return 1000000001;
	if(left<=start&&right>=end)
		return tree[node];
	return min(query(node*2, start, mid, left, right), query(node*2+1, mid+1, end, left, right));
}
void update(int node, int start, int end, int index, int num) {
	int mid=(start+end)/2;
	if(index<start||index>end)
		return;
	if(start==end) {
		arr[index]=num;
		tree[node]=num;
		return;
	}
	update(node*2, start, mid, index, num);
	update(node*2+1, mid+1, end, index, num);
	tree[node]=min(tree[node*2], tree[node*2+1]);
}

int main(void) {
	int N, M, i, a, b, c;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	maketree(1, 0, N-1);
	scanf("%d", &M);
	while(M--) {
		scanf("%d%d%d", &a, &b, &c);
		if(a==1)
			update(1, 0, N-1, b-1, c);
		else
			printf("%d\n", query(1, 0, N-1, b-1, c-1));
	}
	return 0;
}

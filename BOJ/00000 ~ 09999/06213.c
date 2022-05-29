# include <stdio.h>

int arr[50000], maxtree[200000], mintree[200000];

int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }
int maxinit(int node, int start, int end) {
	int left, right, mid=(start+end)/2;
	if(start==end)
		return maxtree[node]=arr[start];
	left=maxinit(node*2, start, mid);
	right=maxinit(node*2+1, mid+1, end);
	return maxtree[node]=max(left, right);
}
int maxquery(int node, int start, int end, int left, int right) {
	int mid=(start+end)/2;
	if(left>end||right<start)
		return 0;
	if(left<=start&&right>=end)
		return maxtree[node];
	return max(maxquery(node*2, start, mid, left, right), maxquery(node*2+1, mid+1, end, left, right));
}
int mininit(int node, int start, int end) {
	int left, right, mid=(start+end)/2;
	if(start==end)
		return mintree[node]=arr[start];
	left=mininit(node*2, start, mid);
	right=mininit(node*2+1, mid+1, end);
	return mintree[node]=min(left, right);
}
int minquery(int node, int start, int end, int left, int right) {
	int mid=(start+end)/2;
	if(left>end||right<start)
		return 1000001;
	if(left<=start&&right>=end)
		return mintree[node];
	return min(minquery(node*2, start, mid, left, right), minquery(node*2+1, mid+1, end, left, right));
}

int main(void) {
	int N, Q, i, A, B;
	scanf("%d%d", &N, &Q);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	maxinit(1, 0, N-1);
	mininit(1, 0, N-1);
	while(Q--) {
		scanf("%d%d", &A, &B);
		printf("%d\n", maxquery(1, 0, N-1, A-1, B-1)-minquery(1, 0, N-1, A-1, B-1));
	}
	return 0;
}

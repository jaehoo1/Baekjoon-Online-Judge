# include <stdio.h>

int N, arr[100001], maxtree[100001], mintree[100001];

int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }
void maxupdate(int idx, int num) {
	while(idx<=N) {
		maxtree[idx]=max(num, maxtree[idx]);
		idx+=idx&-idx;
	}
}
void minupdate(int idx, int num) {
	while(idx<=N) {
		mintree[idx]=min(num, mintree[idx]);
		idx+=idx&-idx;
	}
}
int intervalmax(int st, int ed) {
	int ret=0, idx=ed;
	while(idx>=st)
		if(idx-(idx&-idx)<st-1)
			ret=max(ret, arr[idx--]);
		else {
			ret=max(ret, maxtree[idx]);
			idx-=idx&-idx;
		}
	return ret;
}
int intervalmin(int st, int ed) {
	int ret=1000000001, idx=ed;
	while(idx>=st)
		if(idx-(idx&-idx)<st-1)
			ret=min(ret, arr[idx--]);
		else {
			ret=min(ret, mintree[idx]);
			idx-=idx&-idx;
		}
	return ret;
}

int main(void) {
	int M, i, a, b;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		mintree[i]=1000000001;
	for(i=1 ; i<=N ; i++) {
		scanf("%d", &arr[i]);
		maxupdate(i, arr[i]);
		minupdate(i, arr[i]);
	}
	while(M--) {
		scanf("%d%d", &a, &b);
		printf("%d %d\n", intervalmin(a, b), intervalmax(a, b));
	}
	return 0;
}

# include <stdio.h>
# define	parent(node)	node/2

int depth(long long node) {
	int i;
	for(i=0 ; node ; i++)
		node>>=1;
	return i;
}
int lca_dist(long long a, long long b) {
	int dist=0;
	long long depth_a=depth(a), depth_b=depth(b);
	while(depth_a!=depth_b) {
		if(depth_a<depth_b) {
			b=parent(b);
			depth_b--;
		} else {
			a=parent(a);
			depth_a--;
		}
		dist++;
	}
	while(a!=b) {
		a=parent(a);
		b=parent(b);
		dist+=2;
	}
	return dist;
}

int main(void) {
	int Q;
	long long A, B;
	scanf("%d", &Q);
	while(Q--) {
		scanf("%lld%lld", &A, &B);
		printf("%d\n", lca_dist(A, B));
	}
	return 0;
}
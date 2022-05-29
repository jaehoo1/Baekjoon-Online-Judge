# include <stdio.h>

typedef struct { long long s, e; }line;

int main(void) {
	int N, i;
	line l, cur;
	long long sum=0;
	scanf("%d%lld%lld", &N, &cur.s, &cur.e);
	for(i=1 ; i<N ; i++) {
		scanf("%lld%lld", &l.s, &l.e);
		if(l.s>cur.e) {
			sum+=cur.e-cur.s;
			cur=l;
		} else
			cur.e=cur.e>l.e?cur.e:l.e;
	}
	sum+=cur.e-cur.s;
	printf("%lld", sum);
	return 0;
}

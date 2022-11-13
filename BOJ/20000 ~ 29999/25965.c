# include <stdio.h>
# define	LL	long long

typedef struct { LL K, D, A; }mission;

LL donation(mission money, mission kda) {
	LL prize=money.K*kda.K-money.D*kda.D+money.A*kda.A;
	return prize<0?0:prize;
}

int main(void) {
	int N, M, i;
	LL money;
	mission arr[100], kda;
	scanf("%d", &N);
	while(N--) {
		money=0;
		scanf("%d", &M);
		for(i=0 ; i<M ; i++)
			scanf("%lld%lld%lld", &arr[i].K, &arr[i].D, &arr[i].A);
		scanf("%lld%lld%lld", &kda.K, &kda.D, &kda.A);
		for(i=0 ; i<M ; i++)
			money+=donation(arr[i], kda);
		printf("%lld\n", money);
	}
	return 0;
}
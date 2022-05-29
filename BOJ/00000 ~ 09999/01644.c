# include <stdio.h>

int main(void) {
	int i, j, temp, ptr=0, prime[283146], N, start=0, end=0, sum=0, cou=0;
	prime[ptr++]=2;	prime[ptr++]=3;
	for(i=5 ; i<=4000000 ; i+=2) {
		temp=0;
		for(j=1 ; prime[j]*prime[j]<=i ; j++)
			if(i%prime[j]==0) {
				temp++;
				break;
			}
		if(temp==0)
			prime[ptr++]=i;
	}
	scanf("%d", &N);
	while(end<=ptr) {
		if(sum>=N)
			sum-=prime[start++];
		else
			sum+=prime[end++];
		if(sum==N)
			cou++;
	}
	printf("%d", cou);
	return 0;
}

# include <stdio.h>

int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int N, i, arr[1000000], dp1[1000000], dp2[1000000], R=0, B=0;
	scanf("%d%d", &N, &arr[0]);
	dp1[0]=arr[0];
	for(i=1 ; i<N ; i++) {
		scanf("%d", &arr[i]);
		dp1[i]=max(dp1[i-1], arr[i]);
	}
	dp2[N-1]=arr[N-1];
	for(i=N-2 ; i!=0 ; i--)
		dp2[i]=max(dp2[i+1], arr[i]);
	for(i=0 ; i<N-1 ; i++)
		if(dp1[i]>dp2[i+1])
			R++;
		else if(dp1[i]<dp2[i+1])
			B++;
	if(R>B)
		puts("R");
	else if(R<B)
		puts("B");
	else
		puts("X");
	return 0;
}

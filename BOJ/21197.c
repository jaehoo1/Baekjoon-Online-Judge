# include <stdio.h>

int main(void) {
	int N, i, arr[1000], sum=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	if(N%2)
		puts("still running");
	else {
		for(i=0 ; i<N ; i+=2)
			sum+=arr[i+1]-arr[i];
		printf("%d", sum);
	}
	return 0;
}

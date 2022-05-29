# include <stdio.h>

int main(void) {
	int N, arr[9]={0, 2}, i;
	scanf("%d", &N);
	for(i=2 ; i<N ; i++)
		arr[i]=arr[i-1]*3;
	printf("%d", arr[N-1]);
	return 0;
}

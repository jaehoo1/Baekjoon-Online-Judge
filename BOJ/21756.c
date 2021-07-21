# include <stdio.h>

int main(void) {
	int N, i, arr[100];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		arr[i]=i+1;
	while(N!=1) {
		if(N%2)
			N--;
		N/=2;
		for(i=0 ; i<N ; i++)
			arr[i]=arr[(i+1)*2-1];
	}
	printf("%d", arr[0]);
	return 0;
}

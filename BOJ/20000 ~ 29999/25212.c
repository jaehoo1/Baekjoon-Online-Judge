# include <stdio.h>

int N, arr[10], cou;

void recur(int depth, double sum) {
	if(depth==N) {
		if(sum>=(double)99/100&&sum<=(double)101/100)
			cou++;
		return;
	}
	recur(depth+1, sum+(double)1/arr[depth]);
	recur(depth+1, sum);
}

int main(void) {
	int i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	recur(0, 0);
	printf("%d", cou);
	return 0;
}
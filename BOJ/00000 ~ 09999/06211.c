# include <stdio.h>

int C, B, max, arr[21];

void recur(int sum, int depth) {
	if(sum>max&&sum<=C)
		max=sum;
	if(depth==B)
		return;
	recur(sum+arr[depth], depth+1);
	recur(sum, depth+1);
}

int main(void) {
	int i;
	scanf("%d%d", &C, &B);
	for(i=0 ; i<B ; i++)
		scanf("%d", &arr[i]);
	recur(0, 0);
	printf("%d", max);
	return 0;
}
# include <stdio.h>
# include <math.h>

int arr[4], left[4], right[4], llen, rlen, lsum, rsum, min=500;

void dfs(int depth) {
	int i;
	if(depth==4) {
		for(i=0, lsum=0 ; i<llen ; i++)
			lsum+=left[i];
		for(i=0, rsum=0 ; i<rlen ; i++)
			rsum+=right[i];
		if(abs(lsum-rsum)<min)
			min=abs(lsum-rsum);
		return;
	}
	left[llen++]=arr[depth];
	dfs(depth+1);
	llen--;
	right[rlen++]=arr[depth];
	dfs(depth+1);
	rlen--;
}

int main(void) {
	int i;
	for(i=0 ; i<4 ; i++)
		scanf("%d", &arr[i]);
	dfs(0);
	printf("%d", min);
	return 0;
}

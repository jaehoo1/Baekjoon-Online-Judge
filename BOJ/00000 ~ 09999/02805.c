# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return 1;
	else if(*a>*b)return -1;
	else	return 0;
}

int main(void) {
	int N, M, arr[1000000], i, max=0, left=0, right, mid, res=0;
	long long sum;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	max=arr[0];
	right=max;
	while(left<=right) {
		sum=0;
		mid=(left+right)/2;
		for(i=0 ; arr[i]>mid ; i++)
			sum+=arr[i]-mid;
		if(sum>=M) {
			if(mid>res)
				res=mid;
			left=mid+1;
		} else
			right=mid-1;
	}
	printf("%d", res);
	return 0;
}

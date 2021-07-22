# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}

int main(void) {
	int N, i, arr[100000], start=0, end, res1, res2, abs_min=2000000001;
	scanf("%d", &N);
	end=N-1;
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	while(start!=end) {
		if(abs(arr[start]+arr[end])<abs_min){
			abs_min=abs(arr[start]+arr[end]);
			res1=arr[start];
			res2=arr[end];
		}
		if(arr[start]+arr[end]<0)
			start++;
		else if(arr[start]+arr[end]>0)
			end--;
		else
			break;
	}
	printf("%d %d", res1, res2);
	return 0;
}

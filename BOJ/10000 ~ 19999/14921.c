# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}

int main(void) {
	int N, i, arr[100000], start=0, end, min=200000001, temp;
	scanf("%d", &N);
	end=N-1;
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	while(start<end) {
		temp=arr[start]+arr[end];
		if(abs(temp)<abs(min))
			min=temp;
		if(temp<0)
			start++;
		else if(temp>0)
			end--;
		else
			break;
	}
	printf("%d", min);
	return 0;
}

# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}

int main(void) {
	int x, n, i, arr[1000000], start, end, l1, l2;
	while(~scanf("%d", &x)) {
		x*=10000000;
		scanf("%d", &n);
		start=0;
		end=n-1;
		l1=0;
		for(i=0 ; i<n ; i++)
			scanf("%d", &arr[i]);
		qsort(arr, n, 4, (int(*)(const void*, const void*))intcmp);
		while(start<end)
			if(arr[start]+arr[end]<x)
				start++;
			else if(arr[start]+arr[end]>x)
				end--;
			else {
				l1=arr[start];
				l2=arr[end];
				break;
			}
		if(l1)
			printf("yes %d %d\n", l1, l2);
		else
			puts("danger");
	}
	return 0;
}

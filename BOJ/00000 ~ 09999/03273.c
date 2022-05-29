# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}

int main(void) {
	int n, x, i, arr[100000], cou=0, start=0, end, temp;
	scanf("%d", &n);
	end=n-1;
	for(i=0 ; i<n ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, 4, (int(*)(const void*, const void*))intcmp);
	scanf("%d", &x);
	while(start<end) {
		temp=arr[start]+arr[end];
		if(temp<=x)
			start++;
		else
			end--;
		if(temp==x)
			cou++;
	}
	printf("%d", cou);
	return 0;
}

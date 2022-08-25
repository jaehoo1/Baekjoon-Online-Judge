# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int cmp(const int *a, const int *b) { return abs(*a)>abs(*b); }

int main(void) {
	int T, N, arr[50000], i, pos=0, disp=0, cou=0;
	scanf("%d%d", &T, &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))cmp);
	for(i=0 ; i<N ; i++)
		if(disp+abs(pos-arr[i])<=T) {
			disp+=abs(pos-arr[i]);
			pos=arr[i];
			cou++;
		} else
			break;
	printf("%d", cou);
	return 0;
}
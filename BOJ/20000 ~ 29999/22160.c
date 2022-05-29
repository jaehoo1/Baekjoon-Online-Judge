# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int arr[12], i, j, flag;
	while(1) {
		for(i=0 ; i<12 ; i++)
			scanf("%d", &arr[i]);
		if(!arr[0])
			break;
		flag=1;
		qsort(arr, 12, 4, (int(*)(const void*, const void*))intcmp);
		for(i=0 ; i<12 ; i+=4)
			for(j=i+1 ; j<i+4 ; j++)
				if(arr[i]!=arr[j]) {
					flag=0;
					break;
				}
		puts(flag?"yes":"no");
	}
	return 0;
}

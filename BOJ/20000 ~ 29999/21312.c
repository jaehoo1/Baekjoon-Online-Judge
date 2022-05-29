# include <stdio.h>
# include <stdlib.h>
# define	A	arr[0]
# define	B	arr[1]
# define	C	arr[2]

int intcmp(const int *a, const int *b) {
	if((*a)%2&&(*b)%2==0)return -1;
	else if((*a)%2==0&&(*b)%2)return 1;
	else
		if(*a>*b)return -1;
		else if(*a<*b)return 1;
		else	return 0;
}

int main(void) {
	int arr[7];
	scanf("%d%d%d", &A, &B, &C);
	arr[3]=A*B;
	arr[4]=A*C;
	arr[5]=B*C;
	arr[6]=A*B*C;
	qsort(arr, 7, 4, (int(*)(const void*, const void*))intcmp);
	printf("%d", arr[0]);
	return 0;
}

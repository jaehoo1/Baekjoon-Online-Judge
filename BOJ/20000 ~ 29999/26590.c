# include <stdio.h>

int main(void) {
	char A[1001], B[1001];
	int i;
	scanf("%s%s", A, B);
	for(i=0 ; A[i]&&B[i] ; i++)
		printf("%c", i%2?B[i]:A[i]);
	return 0;
}
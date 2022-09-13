# include <stdio.h>

int main(void) {
	char A[8], B[8], maxA[8], maxB[8], minA[8], minB[8];
	int i;
	scanf("%s%s", A, B);
	for(i=0 ; A[i] ; i++)
		if(A[i]=='5'||A[i]=='6') {
			maxA[i]='6';
			minA[i]='5';
		} else
			maxA[i]=minA[i]=A[i];
	for(i=0 ; B[i] ; i++)
		if(B[i]=='5'||B[i]=='6') {
			maxB[i]='6';
			minB[i]='5';
		} else
			maxB[i]=minB[i]=B[i];
	printf("%d %d", atoi(minA)+atoi(minB), atoi(maxA)+atoi(maxB));
	return 0;
}
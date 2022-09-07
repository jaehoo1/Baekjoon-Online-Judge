# include <stdio.h>
# include <math.h>

int main(void) {
	char A[5], B[5];
	int cou=0, i;
	scanf("%s%s", A, B);
	for(i=0 ; i<4 ; i++)
		if(A[i]!=B[i])
			cou++;
	printf("%d", (int)pow(2, cou));
	return 0;
}
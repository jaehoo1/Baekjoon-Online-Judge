# include <stdio.h>
# include <string.h>

int main(void) {
	char str[100], A[100], B[100], C[100];
	int len;
	scanf("%s", str);
	len=strlen(str);
	strcpy(A, str);
	A[len/3]=0;
	strcpy(B, &str[len/3]);
	B[len/3]=0;
	strcpy(C, &str[len/3*2]);
	C[len/3]=0;
	if(!strcmp(A, B)||!strcmp(A, C))puts(A);
	else if(!strcmp(B, A)||!strcmp(B, C))puts(B);
	else if(!strcmp(C, A)||!strcmp(C, B))puts(C);
	return 0;
}

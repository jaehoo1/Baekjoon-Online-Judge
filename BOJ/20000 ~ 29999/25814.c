# include <stdio.h>

int weight(char *str) {
	int sum=0, i;
	for(i=0 ; str[i] ; i++)
		sum+=str[i]-'0';
	return sum*i;
}

int main(void) {
	char A[8], B[8];
	scanf("%s%s", A, B);
	if(weight(A)>weight(B))
		puts("1");
	else if(weight(A)<weight(B))
		puts("2");
	else
		puts("0");
	return 0;
}
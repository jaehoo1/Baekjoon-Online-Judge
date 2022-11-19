# include <stdio.h>
# include <ctype.h>
# include <stdbool.h>

int main(void) {
	char A[100001], c;
	bool change_upper[26]={false, };
	int i;
	scanf("%s", A);
	getchar();
	while(true) {
		c=getchar();
		if(c==EOF)
			break;
		change_upper[c-'A']=true;
		getchar();
	}
	for(i=0 ; A[i] ; i++)
		if(isupper(A[i])&&change_upper[A[i]-'A'])
			A[i]=tolower(A[i]);
	puts(A);
	return 0;
}
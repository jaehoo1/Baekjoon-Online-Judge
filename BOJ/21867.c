# include <stdio.h>

int main(void) {
	char S[200001];
	int N, i, pt=0;
	scanf("%d%s", &N, S);
	for(i=0 ; S[i] ; i++)
		if(S[i]=='J'||S[i]=='A'||S[i]=='V')
			continue;
		else {
			printf("%c", S[i]);
			pt=1;
		}
	if(!pt)
		puts("nojava");
	return 0;
}

# include <stdio.h>

int main(void) {
	char S[1001];
	int i, A=0, B=0, C=0;
	scanf("%s", S);
	for(i=0 ; S[i] ; i++)
		if(S[i]=='A')A=1;
		else if(S[i]=='B')B=1;
		else if(S[i]=='C')C=1;
	if(A) {
		for(i=0 ; S[i] ; i++)
			if(S[i]=='B'||S[i]=='C'||S[i]=='D'||S[i]=='F')
				S[i]='A';
	} else if(B) {
		for(i=0 ; S[i] ; i++)
			if(S[i]=='C'||S[i]=='D'||S[i]=='F')
				S[i]='B';
	} else if(C) {
		for(i=0 ; S[i] ; i++)
			if(S[i]=='D'||S[i]=='F')
				S[i]='C';
	} else
		for(i=0 ; S[i] ; i++)
			S[i]='A';
	puts(S);
	return 0;
}

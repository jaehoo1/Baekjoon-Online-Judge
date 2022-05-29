# include <stdio.h>
# include <string.h>

int main(void) {
	int N, i;
	char S[101], end=0, len;
	scanf("%d", &N);
	while(N--) {
		scanf("%s", S);
		len=strlen(S);
		if(!end)end=S[len-1];
		else
			if(end!=S[len-1]) {
				end=-1;
				break;
			}
	}
	if(end==-1)puts("0");
	else	puts("1");
	return 0;
}

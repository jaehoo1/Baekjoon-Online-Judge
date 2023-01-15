# include <stdio.h>
# include <string.h>

int main(void) {
	char str[11];
	int N, X, cou[4]={0, }, i;
	scanf("%d", &N);
	while(N--) {
		scanf("%s%d", str, &X);
		if(!strcmp(str, "STRAWBERRY"))
			cou[0]+=X;
		else if(!strcmp(str, "BANANA"))
			cou[1]+=X;
		else if(!strcmp(str, "LIME"))
			cou[2]+=X;
		else if(!strcmp(str, "PLUM"))
			cou[3]+=X;
	}
	for(i=0 ; i<4 ; i++)
		if(cou[i]==5) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}
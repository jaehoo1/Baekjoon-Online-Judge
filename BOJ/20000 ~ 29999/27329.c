# include <stdio.h>
# include <string.h>

int main(void) {
	int N, i;
	char S[101], left[101], right[100];
	scanf("%d%s", &N, S);
	for(i=1 ; i<N ; i++) {
		strcpy(left, S);
		left[i]=0;
		strcpy(right, &S[i]);
		if(!strcmp(left, right)) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
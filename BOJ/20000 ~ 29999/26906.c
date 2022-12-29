# include <stdio.h>
# include <string.h>

int T;
char cha[16], dict[16][5];

char find(char *str) {
	int i;
	for(i=0 ; i<T ; i++)
		if(!strcmp(str, dict[i]))
			return cha[i];
	return '?';
}

int main(void) {
	int i, j;
	char N[4001], temp[5]={0, };
	scanf("%d", &T);
	getchar();
	for(i=0 ; i<T ; i++) {
		scanf("%c %s", &cha[i], dict[i]);
		getchar();
	}
	scanf("%s", N);
	for(i=0 ; N[i] ; i+=4) {
		for(j=0 ; j<4 ; j++)
			temp[j]=N[i+j];
		printf("%c", find(temp));
	}
	return 0;
}
# include <stdio.h>
# include <string.h>

int main(void) {
	int N, i, cou;
	char str[11];
	scanf("%d", &N);
	for(i=0, cou=0 ; cou<N ; i++) {
		sprintf(str, "%d", i);
		if(strstr(str, "666"))
			cou++;
	}
	printf("%d", i-1);
	return 0;
}
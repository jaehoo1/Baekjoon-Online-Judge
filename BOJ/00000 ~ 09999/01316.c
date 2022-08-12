# include <stdio.h>

int is_group_word(char *str) {
	int i, j;
	for(i = 0 ; str[i] ; i++) {
		j = i - 1;
		while(j >= 0 && str[i] == str[j])
			j--;
		while(j >= 0) {
			if(str[i] == str[j])
				return 0;
			j--;
		}
	}
	return 1;
}

int main(void) {
	int N, cou=0;
	char str[101];
	scanf("%d", &N);
	while(N--) {
		scanf("%s", str);
		if(is_group_word(str))
			cou++;
	}
	printf("%d", cou);
	return 0;
}
# include <stdio.h>
# include <string.h>

void lower(char *str) {
	int i;
	for(i=0 ; str[i] ; i++)
		if(str[i]>='A'&&str[i]<='Z')
			str[i]+=32;
}

int main(void) {
	char str[31];
	int N, cou=0;
	scanf("%d", &N);
	while(N--) {
		scanf("%s", str);
		lower(str);
		if(strstr(str, "pink")||strstr(str, "rose"))
			cou++;
	}
	if(cou)
		printf("%d", cou);
	else
		puts("I must watch Star Wars with my daughter");
	return 0;
}

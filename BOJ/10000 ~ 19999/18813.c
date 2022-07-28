# include <stdio.h>

int m;

int isduplicate(char *str) {
	int alp[26]={0, }, i;
	for(i=0 ; str[i] ; i++) {
		if(alp[str[i]-'A'])
			return 1;
		if(str[i]>='A'+m)
			return 1;
		alp[str[i]-'A']=1;
	}
	return 0;
}

int main(void) {
	int n, i, cou=0;
	char str[16];
	scanf("%d%d", &n, &m);
	while(n--) {
		scanf("%s", str);
		if(!isduplicate(str))
			cou++;
	}
	printf("%d", cou);
	return 0;
}
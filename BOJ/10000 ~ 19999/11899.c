# include <stdio.h>

int main(void) {
	int i, cou=0, stack=0;
	char str[51];
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		if(str[i]=='(')stack++;
		else if(str[i]==')')
			if(!stack)cou++;
			else	stack--;
	cou+=stack;
	printf("%d", cou);
	return 0;
}

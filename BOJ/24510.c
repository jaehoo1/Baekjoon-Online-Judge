# include <stdio.h>

int main(void) {
	int C, i, cou, max=0;
	char str[10005]={0, };
	scanf("%d", &C);
	while(C--) {
		cou=0;
		scanf("%s", str);
		for(i=0 ; str[i] ; i++)
			if(str[i]=='f'&&str[i+1]=='o'&&str[i+2]=='r') {
				cou++;
				i+=2;
			} else if(str[i]=='w'&&str[i+1]=='h'&&str[i+2]=='i'&&str[i+3]=='l'&&str[i+4]=='e') {
				cou++;
				i+=4;
			}
		if(cou>max)
			max=cou;
	}
	printf("%d", max);
	return 0;
}

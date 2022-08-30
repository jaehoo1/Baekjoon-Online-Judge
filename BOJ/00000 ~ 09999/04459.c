# include <stdio.h>

int main(void) {
	int q, r, num, i;
	char str[50][66];
	scanf("%d", &q);
	getchar();
	for(i=0 ; i<q ; i++)
		gets(str[i]);
	scanf("%d", &r);
	while(r--) {
		scanf("%d", &num);
		printf("Rule %d: ", num);
		if(num<1||num>q)
			puts("No such rule");
		else
			puts(str[num-1]);
	}
	return 0;
}
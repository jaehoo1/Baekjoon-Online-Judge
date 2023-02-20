# include <stdio.h>
# include <stdbool.h>

bool win(int serial) {
	char str[9];
	int i;
	bool cond1=false, cond2=false, cond3=false, cond4=false;
	if(serial<2023)
		return false;
	sprintf(str, "%d", serial);
	for(i=0 ; str[i] ; i++)
		if(!cond1&&str[i]=='2')
			cond1=true;
		else if(cond1&&!cond2&&str[i]=='0')
			cond2=true;
		else if(cond2&&!cond3&&str[i]=='2')
			cond3=true;
		else if(cond3&&!cond4&&str[i]=='3')
			cond4=true;
	return cond1&&cond2&&cond3&&cond4;
}

int main(void) {
	int N, i, cou=0;
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++)
		if(win(i))
			cou++;
	printf("%d", cou);
	return 0;
}
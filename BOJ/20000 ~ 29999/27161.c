# include <stdio.h>
# include <string.h>
# include <stdbool.h>

void nexttime(bool rev, int *time) {
	rev?(*time)--:(*time)++;
	if(*time>12)
		(*time)-=12;
	if(*time<1)
		(*time)+=12;
}

int main(void) {
	int N, X, time=1, overload;
	char str[10];
	bool reverse=false;
	scanf("%d", &N);
	while(N--) {
		overload=0;
		scanf("%s%d", str, &X);
		if(!strcmp(str, "HOURGLASS"))
			overload++;
		if(time==X)
			overload++;
		if(overload>=2)
			printf("%d NO\n", time);
		else if(!strcmp(str, "HOURGLASS")) {
			printf("%d NO\n", time);
			reverse=!reverse;
		} else if(X==time)
			printf("%d YES\n", time);
		else
			printf("%d NO\n", time);
		nexttime(reverse, &time);
	}
	nexttime(true, &time);
	return 0;
}
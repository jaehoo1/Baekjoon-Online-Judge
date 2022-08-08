# include <stdio.h>

int isleapyear(int year) {
	if((year%100&&year%4==0)||year%400==0)
		return 1;
	return 0;
}

int main(void) {
	int T, y, m, d;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &y, &m);
		m--;
		if(!m) {
			y--;
			m=12;
		}
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
			d=31;
		else if(m==2)
			d=isleapyear(y)?29:28;
		else
			d=30;
		printf("%d %d %d\n", y, m, d);
	}
	return 0;
}
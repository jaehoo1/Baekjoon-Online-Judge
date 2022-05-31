# include <stdio.h>

int timeread(int h, int m) {
	if(h<0||h>=24)
		return 0;
	if(m<0||m>=60)
		return 0;
	return 1;
}
int dateread(int m, int d) {
	if(m<=0||m>12)
		return 0;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) {
		if(d>=1&&d<=31)
			return 1;
	} else if(m==4||m==6||m==9||m==11) {
		if(d>=1&&d<=30)
			return 1;
	} else if(m==2)
		if(d>=1&&d<=29)
			return 1;
	return 0;
}

int main(void) {
	int T, x, y;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &x, &y);
		printf(timeread(x, y)?"Yes ":"No ");
		printf(dateread(x, y)?"Yes\n":"No\n");
	}
	return 0;
}
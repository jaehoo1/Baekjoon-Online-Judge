# include <stdio.h>

int main(void) {
	char date[11], end;
	int num, max=-50, min=50;
	while(~scanf("%s", date)) {
		while(scanf("%d", &num)) {
			if(num>max)max=num;
			if(num<min)min=num;
			end=getchar();
			if(end=='\n'||end==EOF)
				break;
		}
		if(end==EOF)break;
	}
	printf("%d %d", min, max);
	return 0;
}

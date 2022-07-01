# include <stdio.h>
# include <string.h>

int firstcmp(char *str, char *lottery, int iter) {
	int i;
	for(i=0 ; i<iter ; i++)
		if(str[i]!=lottery[i])
			return 1;
	return 0;
}
int lastcmp(char *str, char *lottery, int iter) {
	int i;
	for(i=0 ; i<iter ; i++)
		if(str[i]!=lottery[6-iter+i])
			return 1;
	return 0;
}

int main(void) {
	char str[6][7], lottery[7];
	int money[6], res, i;
	for(i=0 ; i<6 ; i++)
		scanf("%s%d", str[i], &money[i]);
	while(scanf("%s", lottery)) {
		if(!strcmp(lottery, "-1"))
			break;
		res=0;
		if(!strcmp(str[0], lottery))
			res+=money[0];
		if(!firstcmp(str[1], lottery, 3))
			res+=money[1];
		if(!firstcmp(str[2], lottery, 3))
			res+=money[2];
		if(!lastcmp(str[3], lottery, 3))
			res+=money[3];
		if(!lastcmp(str[4], lottery, 3))
			res+=money[4];
		if(!lastcmp(str[5], lottery, 2))
			res+=money[5];
		printf("%d\n", res);
	}
	return 0;
}
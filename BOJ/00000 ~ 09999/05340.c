# include <stdio.h>
# include <string.h>

int main(void) {
	int x[6], i, j, len;
	char str[1001];
	for(i=0 ; i<6 ; i++) {
		gets(str);
		len=strlen(str);
		for(j=0 ; j<len&&str[len-j-1]==' ' ; j++);
		x[i]=len-j;
	}
	printf("Latitude ");
	for(i=0 ; i<2 ; i++)
		printf("%d:", x[i]);
	printf("%d\n", x[2]);
	printf("Longitude ");
	for(i=3 ; i<5 ; i++)
		printf("%d:", x[i]);
	printf("%d", x[5]);
	return 0;
}
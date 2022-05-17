# include <stdio.h>

int samedigit(int num) {
	char str[4];
	sprintf(str, "%d", num);
	if(str[0]==str[1]&&str[0]==str[2])
		return 1;
	return 0;
}

int main(void) {
	int a, b, eraseda, erasedb;
	for(a=100 ; a<1000 ; a++) {
		eraseda=a/10;
		for(b=100 ; b<1000 ; b++) {
			erasedb=b%100;
			if(!erasedb)
				continue;
			if(samedigit(a)&&samedigit(b))
				continue;
			if(a*(b%100)==(a/10)*b&&a%10==b/100)
				printf("%d / %d = %d / %d\n", a, b, eraseda, erasedb);
		}
	}
	return 0;
}

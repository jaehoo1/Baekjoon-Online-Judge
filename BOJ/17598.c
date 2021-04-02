# include <stdio.h>
# include <string.h>

int main(void) {
	char str[6];
	int i, T=0, L=0;
	for(i=0 ; i<9 ; i++) {
		scanf("%s", str);
		if(!strcmp(str, "Lion"))L++;
		else	T++;
	}
	if(L>=5)puts("Lion");
	else	puts("Tiger");
	return 0;
}

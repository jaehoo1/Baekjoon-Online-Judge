# include <stdio.h>
# include <string.h>

int main(void) {
	char city[257], coldest[257];
	int min=200, temp;
	while(scanf("%s%d", city, &temp)) {
		if(temp<min) {
			min=temp;
			strcpy(coldest, city);
		}
		if(!strcmp(city, "Waterloo"))
			break;
	}
	puts(coldest);
	return 0;
}
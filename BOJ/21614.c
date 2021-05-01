# include <stdio.h>
# include <string.h>

int main(void) {
	char str[6];
	int sum, temp;
	while(scanf("%s", str)) {
		if(!strcmp(str, "99999"))
			break;
		sum=str[0]-'0'+str[1]-'0';
		if(sum%2)
			printf("left %s\n", &str[2]);
		else if(!sum)
			if(temp%2)
				printf("left %s\n", &str[2]);
			else
				printf("right %s\n", &str[2]);
		else
			printf("right %s\n", &str[2]);
		temp=sum;
	}
	return 0;
}

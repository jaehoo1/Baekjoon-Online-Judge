# include <stdio.h>
# include <string.h>

int main(void) {
	char str[1001];
	int i;
	gets(str);
	while(!strstr(str, "CHIPMUNKS")&&!strstr(str, "LIVE")) {
		for(i=0 ; str[i] ; i++)
			if(str[i]>='A'&&str[i]<='Z') {
				str[i]--;
				if(str[i]<'A')
					str[i]+=26;
			}
	}
	puts(str);
	return 0;
}

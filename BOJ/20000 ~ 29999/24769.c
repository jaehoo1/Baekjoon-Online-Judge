# include <stdio.h>
# include <string.h>
# include <stdbool.h>

bool isvowel(char c) {
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
		return true;
	return false;
}

int main(void) {
	int N, i, cou, max;
	char str[81], res[81];
	while(scanf("%d", &N)) {
		if(!N)
			break;
		if(N==1) {
			scanf("%s", str);
			puts(str);
			continue;
		}
		max=0;
		while(N--) {
			cou=0;
			scanf("%s", str);
			for(i=0 ; str[i+1] ; i++)
				if(str[i]==str[i+1]&&isvowel(str[i])&&isvowel(str[i+1]))
					cou++;
			if(cou>max) {
				max=cou;
				strcpy(res, str);
			}
		}
		puts(res);
	}
	return 0;
}
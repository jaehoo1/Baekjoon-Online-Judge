# include <stdio.h>
# include <stdbool.h>
# include <string.h>

bool isvowel(char c) {
	switch(c) {
		case 'a':	case 'e':	case 'i':	case 'o':	case 'u':
			return true;
		default:
			return false;
	}
}

int main(void) {
	bool flag=true;
	char str[31];
	int len, i;
	scanf("%s", str);
	len=strlen(str);
	if(isvowel(str[0])) {
		for(i=0 ; i<len ; i+=2)
			if(!isvowel(str[i]))
				flag=false;
		for(i=1 ; i<len ; i+=2)
			if(isvowel(str[i]))
				flag=false;
	} else {
		for(i=0 ; i<len ; i+=2)
			if(isvowel(str[i]))
				flag=false;
		for(i=1 ; i<len ; i+=2)
			if(!isvowel(str[i]))
				flag=false;
	}
	printf("%d", flag);
	return 0;
}
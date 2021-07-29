# include <stdio.h>

int main(void) {
	char str[1001], c;
	int i, j;
	gets(str);
	for(i=0 ; str[i] ; i++)
		if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'&&str[i]!='y') {
			j=i+1;
			while(str[j]&&str[i]==str[j])
				j++;
			if(j-i>1)
				printf("%c%c", str[i], str[i]);
			else
				printf("%c", str[i]);
			i=j-1;
		} else
			printf("%c", str[i]);
	return 0;
}

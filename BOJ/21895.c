# include <stdio.h>

int main(void) {
	int N, i;
	char str1[101], str2[101];
	scanf("%d%s%s", &N, str1, str2);
	for(i=0 ; i<N ; i++)
		if(str1[i]==str2[i]) {
			if(str1[i]=='R')printf("P");
			else if(str1[i]=='P')printf("S");
			else if(str1[i]=='S')printf("R");
		} else {
			if((str1[i]=='R'&&str2[i]=='P')||(str1[i]=='P'&&str2[i]=='R'))printf("P");
			else if((str1[i]=='P'&&str2[i]=='S')||(str1[i]=='S'&&str2[i]=='P'))printf("S");
			else if((str1[i]=='R'&&str2[i]=='S')||(str1[i]=='S'&&str2[i]=='R'))printf("R");
		}
	return 0;
}

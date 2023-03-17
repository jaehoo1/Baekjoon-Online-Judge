# include <stdio.h>

int main(void) {
	char ann[101], ben[101];
	int cou[26]={0, }, i;
	scanf("%s%s", ann, ben);
	for(i=0 ; ann[i] ; i++)
		cou[ann[i]-'a']++;
	for(i=0 ; ben[i] ; i++)
		cou[ben[i]-'a']++;
	for(i=0 ; i<26 ; i++)
		while(cou[i]--)
			printf("%c", i+'a');
	return 0;
}
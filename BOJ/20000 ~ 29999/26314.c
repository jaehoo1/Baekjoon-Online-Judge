# include <stdio.h>

int main(void) {
	int n, consonant, vowel, i;
	char str[21];
	scanf("%d", &n);
	while(n--) {
		consonant=vowel=0;
		scanf("%s", str);
		for(i=0 ; str[i] ; i++)
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
				vowel++;
			else
				consonant++;
		printf("%s\n%d\n", str, vowel>consonant);
	}
	return 0;
}
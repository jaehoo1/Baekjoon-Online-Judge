# include <stdio.h>
# include <string.h>

int N;

int duramuri(char *str1, char *str2) {
	int alp1[26]={0, }, alp2[26]={0, }, i, ptr1=0, ptr2=0;
	char temp1[100001], temp2[100001];
	for(i=0 ; i<N ; i++) {
		alp1[str1[i]-'a']++;
		alp2[str2[i]-'a']++;
	}
	for(i=0 ; i<26 ; i++)
		if(alp1[i]!=alp2[i])
			return 0;
	if(str1[0]!=str2[0]||str1[N-1]!=str2[N-1])
		return 0;
	for(i=0 ; i<N ; i++) {
		if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u')
			continue;
		temp1[ptr1++]=str1[i];
	}
	temp1[ptr1]=0;
	for(i=0 ; i<N ; i++) {
		if(str2[i]=='a'||str2[i]=='e'||str2[i]=='i'||str2[i]=='o'||str2[i]=='u')
			continue;
		temp2[ptr2++]=str2[i];
	}
	temp2[ptr2]=0;
	return !strcmp(temp1, temp2);
}

int main(void) {
	char str1[100001], str2[100001];
	scanf("%d%s%s", &N, str1, str2);
	puts(duramuri(str1, str2)?"YES":"NO");
	return 0;
}
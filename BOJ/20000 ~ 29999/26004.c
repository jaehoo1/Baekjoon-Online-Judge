# include <stdio.h>

int main(void) {
	char S[100001], HIARC[6]="HIARC";
	int N, i, cou[26]={0, }, min=100000;
	scanf("%d%s", &N, S);
	for(i=0 ; i<N ; i++)
		cou[S[i]-'A']++;
	for(i=0 ; i<5 ; i++)
		if(cou[HIARC[i]-'A']<min)
			min=cou[HIARC[i]-'A'];
	printf("%d", min);
	return 0;
}
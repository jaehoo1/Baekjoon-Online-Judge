# include <stdio.h>

int main(void) {
	int n, cou[14], i, max;
	char card[3];
	scanf("%d", &n);
	while(n--) {
		max=0;
		for(i=1 ; i<=13 ; i++)
			cou[i]=0;
		for(i=0 ; i<5 ; i++) {
			scanf("%s", card);
			if(card[0]=='A')
				cou[1]++;
			else if(card[0]=='T')
				cou[10]++;
			else if(card[0]=='J')
				cou[11]++;
			else if(card[0]=='Q')
				cou[12]++;
			else if(card[0]=='K')
				cou[13]++;
			else
				cou[card[0]-'0']++;
		}
		for(i=1 ; i<=13 ; i++)
			if(cou[i]>max)
				max=cou[i];
		printf("%d\n", max);
	}
	return 0;
}
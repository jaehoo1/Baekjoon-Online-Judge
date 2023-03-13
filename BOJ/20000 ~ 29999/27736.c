# include <stdio.h>

int main(void) {
	int N, appr=0, rjct=0, inva=0, i, vote;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &vote);
		if(vote==1)
			appr++;
		else if(vote==-1)
			rjct++;
		else if(!vote)
			inva++;
	}
	if(inva>=(double)N/2)
		puts("INVALID");
	else if(appr>rjct)
		puts("APPROVED");
	else
		puts("REJECTED");
	return 0;
}
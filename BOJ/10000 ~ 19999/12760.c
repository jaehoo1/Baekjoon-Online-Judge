# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) {
	if(*a>*b)
		return -1;
	else if(*a<*b)
		return 1;
	else
		return 0;
}

int main(void) {
	int N, M, i, j, score[100]={0, }, card[100][100], max;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<M ; j++)
			scanf("%d", &card[i][j]);
		qsort(card[i], M, 4, (int(*)(const void*, const void*))intcmp);
	}
	for(j=0 ; j<M ; j++) {
		max=0;
		for(i=0 ; i<N ; i++)
			if(card[i][j]>max)
				max=card[i][j];
		for(i=0 ; i<N ; i++)
			if(card[i][j]==max)
				score[i]++;
	}
	max=0;
	for(i=0 ; i<N ; i++)
		if(score[i]>max)
			max=score[i];
	for(i=0 ; i<N ; i++)
		if(score[i]==max)
			printf("%d ", i+1);
	return 0;
}
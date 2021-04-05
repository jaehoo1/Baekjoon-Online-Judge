# include <stdio.h>

int main(void) {
	int N, M, i, j, num, TC[100], team[100]={0, }, max=-1, idx;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<M ; i++)
		scanf("%d", &TC[i]);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++) {
			scanf("%d", &num);
			if(TC[j]==num)
				team[i]++;
		}
	for(i=0 ; i<N ; i++)
		if(team[i]>max) {
			max=team[i];
			idx=i;
		}
	printf("%d", idx+1);
	return 0;
}

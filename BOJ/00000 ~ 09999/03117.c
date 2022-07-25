# include <stdio.h>
# define	MAX_EXP	30

int main(void) {
	int N, K, M, arr[100001][MAX_EXP], order[100000], i, j, cou, num;
	scanf("%d%d%d", &N, &K, &M);
	M--;
	for(i=0 ; i<N ; i++)
		scanf("%d", &order[i]);
	for(i=1 ; i<=K ; i++)
		scanf("%d", &arr[i][0]);
	for(j=1 ; j<MAX_EXP ; j++)
		for(i=1 ; i<=K ; i++)
			arr[i][j]=arr[arr[i][j-1]][j-1];
	for(i=0 ; i<N ; i++) {
		cou=M;
		num=order[i];
		for(j=MAX_EXP-1 ; j>=0 ; j--)
			if(cou>=1<<j) {
				cou-=1<<j;
				num=arr[num][j];
			}
		printf("%d ", num);
	}
	return 0;
}
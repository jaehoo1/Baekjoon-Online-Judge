# include <stdio.h>
# include <math.h>
# define	true	1
# define	false	0

int N, arr[8], tree[8], sum, max, visited[8];

void dfs(int depth) {
	int i;
	if(depth==N) {
		sum=0;
		for(i=1 ; i<N ; i++)
			sum+=abs(tree[i]-tree[i-1]);
		if(sum>max)
			max=sum;
		return;
	}
	for(i=0 ; i<N ; i++)
		if(!visited[i]) {
			visited[i]=true;
			tree[depth]=arr[i];
			dfs(depth+1);
			visited[i]=false;
		}
}

int main(void) {
	int i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	dfs(0);
	printf("%d", max);
	return 0;
}

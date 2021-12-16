# include <stdio.h>
# define	true	1
# define	false	0

int N, S, arr[20], res, visited[20];

void recur(int depth, int sum, int index) {
	int i;
	if(depth&&sum==S)
		res++;
	for(i=index ; i<N ; i++)
		if(!visited[i]) {
			visited[i]=true;
			recur(depth+1, sum+arr[i], i);
			visited[i]=false;
		}
}

int main(void) {
	int i;
	scanf("%d%d", &N, &S);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	recur(0, 0, 0);
	printf("%d", res);
	return 0;
}

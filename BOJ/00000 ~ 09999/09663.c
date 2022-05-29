# include <stdio.h>

int N, cou, arr[15][15], row[15], col[15];
void dfs(int depth) {
	int i, j, k, flag;
	if(depth==N) {
		cou++;
		return;
	}
	for(i=0 ; i<N ; i++) {
		flag=1;
		j=depth-1;
		k=i-1;
		while(j>=0&&k>=0)
			if(arr[j--][k--]) {
				flag=0;
				break;
			}
		j=depth-1;
		k=i+1;
		while(j>=0&&k<N)
			if(arr[j--][k++]) {
				flag=0;
				break;
			}
		j=depth+1;
		k=i-1;
		while(j<0&&k>=0)
			if(arr[j++][k--]) {
				flag=0;
				break;
			}
		j=depth+1;
		k=i+1;
		while(j<0&&k>=0)
			if(arr[j++][k++]) {
				flag=0;
				break;
			}
		if(flag&&!arr[depth][i]&&!row[depth]&&!col[i]) {
			arr[depth][i]=1;
			row[depth]=1;
			col[i]=1;
			dfs(depth+1);
			arr[depth][i]=0;
			row[depth]=0;
			col[i]=0;
		}
	}
}

int main(void) {
	scanf("%d", &N);
	dfs(0);
	printf("%d", cou);
	return 0;
}

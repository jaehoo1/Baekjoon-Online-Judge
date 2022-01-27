# include <stdio.h>

int N, visited[10];
long long max, min=9999999999, sum;
char arr[9], tree[11], maxstr[11], minstr[11];

void dfs(int depth);
void next(int visited[10], int depth, int input) {
	visited[input]=1;
	tree[depth]=input+'0';
	dfs(depth+1);
	visited[input]=0;
}
void dfs(int depth) {
	int i;
	if(depth==N+1) {
		sscanf(tree, "%lld", &sum);
		if(sum>max) {
			max=sum;
			strcpy(maxstr, tree);
		}
		if(sum<min) {
			min=sum;
			strcpy(minstr, tree);
		}
		return;
	}
	for(i=0 ; i<10 ; i++)
		if(!depth) {
			if(!visited[i])
				next(visited, depth, i);
		} else if(arr[depth-1]=='<'&&tree[depth-1]<i+'0'&&!visited[i])
			next(visited, depth, i);
		else if(arr[depth-1]=='>'&&tree[depth-1]>i+'0'&&!visited[i])
			next(visited, depth, i);
}

int main(void) {
	int i;
	scanf("%d", &N);
	getchar();
	for(i=0 ; i<N ; i++) {
		scanf("%c", &arr[i]);
		getchar();
	}
	dfs(0);
	puts(maxstr);
	puts(minstr);
	return 0;
}

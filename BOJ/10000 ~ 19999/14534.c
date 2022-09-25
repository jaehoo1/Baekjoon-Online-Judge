# include <stdio.h>
# include <string.h>

char L[6], tree[6];
int visited[5], len;

void recur(int depth) {
	int i;
	if(depth==len) {
		tree[depth]=0;
		puts(tree);
		return;
	}
	for(i=0 ; i<len ; i++)
		if(!visited[i]) {
			visited[i]=1;
			tree[depth]=L[i];
			recur(depth+1);
			visited[i]=0;
		}
}

int main(void) {
	int T, i;
	scanf("%d", &T);
	for(i=1 ; i<=T ; i++) {
		scanf("%s", L);
		len=strlen(L);
		printf("Case # %d:\n", i);
		recur(0);
	}
	return 0;
}
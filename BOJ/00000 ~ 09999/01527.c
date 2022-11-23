# include <stdio.h>

int A, B, cou;
char tree[10];

void recur(int depth) {
	tree[depth]=0;
	if(atoi(tree)>=A&&atoi(tree)<=B)
		cou++;
	if(depth==9)
		return;
	tree[depth]='4';
	recur(depth+1);
	tree[depth]='7';
	recur(depth+1);
}

int main(void) {
	scanf("%d%d", &A, &B);
	recur(0);
	printf("%d", cou);
	return 0;
}
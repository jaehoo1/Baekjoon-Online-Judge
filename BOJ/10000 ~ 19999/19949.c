# include <stdio.h>
# include <stdbool.h>

int answer[10], tree[10], cou;

bool triplesame(int depth) { return tree[depth-2]==tree[depth-1]&&tree[depth-2]==tree[depth]; }
bool isscoreover5(void) {
	int i, temp=0;
	for(i=0 ; i<10 ; i++)
		if(tree[i]==answer[i])
			temp++;
	return temp>=5;
}
void recur(int depth) {
	int i;
	if(depth==10) {
		if(isscoreover5())
			cou++;
		return;
	}
	for(i=1 ; i<=5 ; i++) {
		tree[depth]=i;
		if(triplesame(depth))
			continue;
		recur(depth+1);
	}
}

int main(void) {
	int i;
	for(i=0 ; i<10 ; i++)
		scanf("%d", &answer[i]);
	recur(0);
	printf("%d", cou);
	return 0;
}
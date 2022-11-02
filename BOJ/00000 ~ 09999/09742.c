# include <stdio.h>
# include <stdbool.h>

bool visited[10];
char str[11], tree[11];
int num, cou, len;

void init(bool visited[10]) {
	int i;
	for(i=0 ; i<10 ; i++)
		visited[i]=0;
	cou=0;
	len=strlen(str);
}
void recur(int depth) {
	int i;
	if(cou==num)
		return;
	if(len==depth) {
		cou++;
		return;
	}
	for(i=0 ; i<len&&cou<num ; i++)
		if(!visited[i]) {
			visited[i]=true;
			tree[depth]=str[i];
			recur(depth+1);
			visited[i]=false;
		}
}

int main(void) {
	while(~scanf("%s%d", str, &num)) {
		init(visited);
		recur(0);
		printf("%s %d = ", str, num);
		if(cou==num) {
			tree[len]=0;
			puts(tree);
		} else
			puts("No permutation");
	}
	return 0;
}
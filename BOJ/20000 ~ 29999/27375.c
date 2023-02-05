# include <stdio.h>
# include <stdbool.h>

typedef struct { int w, s, e; }lesson;

lesson arr[20];
int n, k, cou;
bool visited[5][11];

bool cantakelesson(lesson l) {
	int i;
	if(l.w==5)
		return false;
	for(i=l.s ; i<=l.e ; i++)
		if(visited[l.w][i])
			return false;
	return true;
}
void takelesson(lesson l, bool cancel) {
	int i;
	for(i=l.s ; i<=l.e ; i++)
		visited[l.w][i]=!cancel;
}
int lessoncredit(lesson l) { return l.e-l.s+1; }
void recur(int depth, int credit) {
	if(credit==k) {
		cou++;
		return;
	}
	if(credit>k||depth>=n)
		return;
	if(cantakelesson(arr[depth])) {
		takelesson(arr[depth], false);
		recur(depth+1, credit+lessoncredit(arr[depth]));
		takelesson(arr[depth], true);
	}
	recur(depth+1, credit);
}


int main(void) {
	int i;
	scanf("%d%d", &n, &k);
	for(i=0 ; i<n ; i++)
		scanf("%d%d%d", &arr[i].w, &arr[i].s, &arr[i].e);
	recur(0, 0);
	printf("%d", cou);
	return 0;
}
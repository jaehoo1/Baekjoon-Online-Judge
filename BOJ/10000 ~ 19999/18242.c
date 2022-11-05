# include <stdio.h>

typedef struct { int x, y; }pos;

char arr[100][101];
int N, M;
pos lu, ru, ld, rd;

int max(int a, int b) { return a>b?a:b; }
void findleftup(void) {
	int i, j;
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			if(arr[i][j]=='#') {
				lu.x=i;
				lu.y=j;
				return;
			}
}
void findrightdown(void) {
	pos down, right;
	for(down=lu ; down.x+1<N&&arr[down.x+1][down.y]=='#' ; down.x++);
	for( ; down.y+1<M&&arr[down.x][down.y+1]=='#' ; down.y++);
	for(right=lu ; right.y+1<M&&arr[right.x][right.y+1]=='#' ; right.y++);
	for( ; right.x+1<N&&arr[right.x+1][right.y]=='#' ; right.x++);
	rd.x=max(down.x, right.x);
	rd.y=max(down.y, right.y);
	ru.x=lu.x;
	ru.y=rd.y;
	ld.x=rd.x;
	ld.y=lu.y;
}
void finddirection(void) {
	pos p;
	for(p=lu ; p.x<=ld.x ; p.x++)
		if(arr[p.x][p.y]!='#') {
			puts("LEFT");
			return;
		}
	for(p=ru ; p.x<=rd.x ; p.x++)
		if(arr[p.x][p.y]!='#') {
			puts("RIGHT");
			return;
		}
	for(p=lu ; p.y<=ru.y ; p.y++)
		if(arr[p.x][p.y]!='#') {
			puts("UP");
			return;
		}
	for(p=ld ; p.y<=rd.y ; p.y++)
		if(arr[p.x][p.y]!='#') {
			puts("DOWN");
			return;
		}
}

int main(void) {
	int i;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		scanf("%s", arr[i]);
	findleftup();
	findrightdown();
	finddirection();
	return 0;
}
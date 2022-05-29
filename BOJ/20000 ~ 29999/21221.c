# include <stdio.h>

typedef struct {
	int x, y;
}pos;

int main(void) {
	int n, m, i, j, ptr=0;
	char str[100][101];
	pos arr[10000];
	scanf("%d%d", &n, &m);
	for(i=0 ; i<n ; i++)
		scanf("%s", str[i]);
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<m ; j++)
			if(str[i][j]=='#'&&i!=n-1&&j!=m-1) {
				arr[ptr].x=i;
				arr[ptr++].y=j;
			}
	for(i=0 ; i<ptr ; i++) {
		str[arr[i].x+1][arr[i].y]='#';
		str[arr[i].x][arr[i].y+1]='#';
		str[arr[i].x+1][arr[i].y+1]='#';
	}
	for(i=0 ; i<n ; i++)
		printf("%s\n", str[i]);
	return 0;
}

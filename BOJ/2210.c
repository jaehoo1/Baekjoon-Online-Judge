# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int ptr;
char stack[7], str[37332][7], arr[5][5];

void dfs(const int cou, const int x, const int y) {
	if(!cou) {
		stack[6]=0;
		strcpy(str[ptr++], stack);
		return;
	}
	stack[6-cou]=arr[x][y];
	if(x>0)dfs(cou-1, x-1, y);
	if(x<4)dfs(cou-1, x+1, y);
	if(y>0)dfs(cou-1, x, y-1);
	if(y<4)dfs(cou-1, x, y+1);
}

int main(void) {
	int i, j, cou=1;
	for(i=0 ; i<5 ; i++)
		for(j=0 ; j<5 ; j++) {
			scanf("%c", &arr[i][j]);
			getchar();
		}
	for(i=0 ; i<5 ; i++)
		for(j=0 ; j<5 ; j++)
			dfs(6, i, j);
	qsort(str, 37332, 7, (int(*)(const void*, const void*))strcmp);
	for(i=0 ; i<37331 ; i++)
		if(strcmp(str[i], str[i+1]))
			cou++;
	printf("%d", cou);
	return 0;
}

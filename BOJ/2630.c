# include <stdio.h>

typedef enum {
	false, true
}bool;

bool arr[128][128];
int w, b;

void recur(int x, int y, int N) {
	int i, j, flag=0;
	bool first=arr[x][y];
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			if(arr[i+x][j+y]!=first)
				flag=1;
	if(!flag)
		if(first)b++;
		else	w++;
	else {
		N/=2;
		recur(x, y, N);
		recur(x, y+N, N);
		recur(x+N, y, N);
		recur(x+N, y+N, N);
	}
}

int main(void) {
	int N, i, j;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			scanf("%d", &arr[i][j]);
	recur(0, 0, N);
	printf("%d\n%d", w, b);
	return 0;
}

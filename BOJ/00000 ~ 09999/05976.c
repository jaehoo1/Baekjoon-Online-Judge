# include <stdio.h>
# include <stdbool.h>

int N, curx, cury, arr[750][750], vec, dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};

bool ischangedirection(void) {
	int nx=curx+dx[vec], ny=cury+dy[vec];
	if(nx<0||nx>=N||ny<0||ny>=N)
		return true;
	if(arr[nx][ny])
		return true;
	return false;
}

int main(void) {
	int num, endnum, i, j;
	scanf("%d", &N);
	endnum=N*N;
	for(num=1 ; num<=endnum ; num++) {
		arr[curx][cury]=num;
		if(ischangedirection()) {
			vec++;
			if(vec==4)
				vec=0;
		}
		curx+=dx[vec];
		cury+=dy[vec];
	}
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++)
			printf("%d ", arr[i][j]);
		puts("");
	}
	return 0;
}
# include <stdio.h>

int main(void) {
	int N, M, train[100001]={0, }, cmd, i, x, bin, j, visited[1048576]={0, }, cou=0;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &cmd, &i);
		if(cmd==1||cmd==2) {
			scanf("%d", &x);
			bin=1;
			for(j=0 ; j<20-x ; j++)
				bin<<=1;
			if(cmd==1)
				train[i]|=bin;
			else if(cmd==2)
				train[i]&=~bin;
		} else if(cmd==3)
			train[i]>>=1;
		else if(cmd==4) {
			train[i]<<=1;
			bin=1048576;
			train[i]&=~bin;
		}
	}
	for(i=1 ; i<=N ; i++)
		if(!visited[train[i]]) {
			visited[train[i]]=1;
			cou++;
		}
	printf("%d", cou);
	return 0;
}

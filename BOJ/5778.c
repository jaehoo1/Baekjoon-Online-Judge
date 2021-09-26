# include <stdio.h>

int main(void) {
	int N, M, arr[10001], num, i;
	while(scanf("%d%d", &N, &M)) {
		if(!N&&!M)break;
		for(i=1 ; i<=N ; i++)
			arr[i]=0;
		while(M--) {
			scanf("%d", &num);
			arr[num]++;
		}
		num=0;
		for(i=1 ; i<=N ; i++)
			if(arr[i]>1)
				num++;
		printf("%d\n", num);
	}
	return 0;
}

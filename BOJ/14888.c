# include <stdio.h>

int N, arr[100], op[4], max=-1000000000, min=1000000000, sum;
char tree[99];

void dfs(int depth) {
	int i;
	if(depth==N-1) {
		sum=arr[0];
		for(i=0 ; i<depth ; i++)
			if(tree[i]=='+')
				sum+=arr[i+1];
			else if(tree[i]=='-')
				sum-=arr[i+1];
			else if(tree[i]=='*')
				sum*=arr[i+1];
			else if(tree[i]=='/')
				sum/=arr[i+1];
		if(sum>max)
			max=sum;
		if(sum<min)
			min=sum;
		return;
	}
	for(i=0 ; i<4 ; i++)
		if(op[i]) {
			if(!i)
				tree[depth]='+';
			else if(i==1)
				tree[depth]='-';
			else if(i==2)
				tree[depth]='*';
			else if(i==3)
				tree[depth]='/';
			op[i]--;
			dfs(depth+1);
			op[i]++;
		}
}

int main(void) {
	int i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	for(i=0 ; i<4 ; i++)
		scanf("%d", &op[i]);
	dfs(0);
	printf("%d\n%d", max, min);
	return 0;
}

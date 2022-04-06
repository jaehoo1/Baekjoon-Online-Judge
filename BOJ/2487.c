# include <stdio.h>

int G[20001], max, visited[20001];

void dfs(int depth, int node) {
	visited[node]=1;
	if(depth>max)
		max=depth;
	if(!visited[G[node]])
		dfs(depth+1, G[node]);
}
long long gcd(long long a, long long b) {
	if(!b)
		return a;
	return gcd(b, a%b);
}
long long lcm(long long a, long long b) {
	long long temp=gcd(a, b);
	return (a/temp)*(b/temp)*temp;
}

int main(void) {
	int N, i, cycle_size[20000], ptr=0;
	long long res;
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++)
		scanf("%lld", &G[i]);
	for(i=1 ; i<=N ; i++)
		if(!visited[i]) {
			max=1;
			dfs(1, i);
			cycle_size[ptr++]=max;
		}
	res=cycle_size[0];
	for(i=1 ; i<ptr ; i++)
		res=lcm(res, cycle_size[i]);
	printf("%lld", res);
	return 0;
}

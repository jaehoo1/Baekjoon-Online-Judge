# include <cstdio>
# include <unordered_set>

using namespace std;

bool isluckynum(int x) {
	char str[6];
	sprintf(str, "%d", x);
	for(int i=0 ; str[i] ; i++)
		if(str[i]!='5'&&str[i]!='8')
			return false;
	return true;
}

int main(void) {
	int T, N, M, K, A[50], B[50], C[50], sum;
	scanf("%d", &T);
	while(T--) {
		unordered_set<int> us;
		scanf("%d", &N);
		for(int i=0 ; i<N ; i++)
			scanf("%d", &A[i]);
		scanf("%d", &M);
		for(int i=0 ; i<M ; i++)
			scanf("%d", &B[i]);
		scanf("%d", &K);
		for(int i=0 ; i<K ; i++)
			scanf("%d", &C[i]);
		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<M ; j++)
				for(int k=0 ; k<K ; k++) {
					sum=A[i]+B[j]+C[k];
					if(isluckynum(sum))
						us.insert(sum);
				}
		printf("%d\n", us.size());
	}
	return 0;
}
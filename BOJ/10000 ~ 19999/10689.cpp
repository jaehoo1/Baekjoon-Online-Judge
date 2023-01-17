# include <cstdio>
# include <unordered_set>

using namespace std;

int main(void) {
	int T, N, R, arr[100000], num, size;
	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++) {
		R=0;
		unordered_set<int> us;
		scanf("%d", &N);
		for(int i=0 ; i<N ; i++) {
			scanf("%d", &num);
			us.insert(num);
			arr[i]=num;
		}
		size=us.size();
		us=unordered_set<int>();
		for(int i=0 ; i<N ; i++) {
			us.insert(arr[i]);
			if(us.size()==size) {
				printf("Case %d: %d\n", t, i+1);
				break;
			}
		}
	}
	return 0;
}
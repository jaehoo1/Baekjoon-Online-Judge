# include <cstdio>
# include <unordered_map>

using namespace std;

int main(void) {
	int n, k, a;
	unordered_map<int, int> um;
	scanf("%d%d", &n, &k);
	while(n--) {
		scanf("%d", &a);
		um[a]++;
	}
	for(unordered_map<int, int>::iterator iter=um.begin() ; iter!=um.end()&&k ; iter++, k--) {
		printf("%d ", iter->first);
		iter->second--;
	}
	for(unordered_map<int, int>::iterator iter=um.begin() ; iter!=um.end()&&k ; iter++) {
		int it=min(iter->second, k);
		for(int i=0 ; i<it ; i++)
			printf("%d ", iter->first);
		iter->second-=it;
		k-=it;
	}
	return 0;
}
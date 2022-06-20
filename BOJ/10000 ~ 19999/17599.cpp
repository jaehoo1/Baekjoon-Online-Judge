# include <cstdio>
# include <unordered_set>

using namespace std;

int main(void) {
	int n, a;
	unordered_set<int> us;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &a);
		us.insert(a);
	}
	printf("%d", us.size());
	return 0;
}
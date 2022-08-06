# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

struct compare {
	bool operator()(const int &a, const int &b) {
		return a>b;
	}
};

int main(void) {
	int N, num;
	vector<int> v;
	scanf("%d%d", &N, &num);
	v.push_back(num);
	for(int i=1 ; i<N ; i++) {
		scanf("%d", &num);
		if(num<v.back())
			v.push_back(num);
		else {
			vector<int>::iterator iter=lower_bound(v.begin(), v.end(), num, compare());
			*iter=num;
		}
	}
	printf("%d", N-v.size());
	return 0;
}
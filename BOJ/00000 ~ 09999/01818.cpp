# include <cstdio>
# include <vector>

using namespace std;

int main(void) {
	int N, num;
	vector<int> v;
	scanf("%d%d", &N, &num);
	v.push_back(num);
	for(int i=1 ; i<N ; i++) {
		scanf("%d", &num);
		if(num>v.back())
			v.push_back(num);
		else {
			vector<int>::iterator ptr=lower_bound(v.begin(), v.end(), num);
			*ptr=num;
		}
	}
	printf("%d", N-v.size());
	return 0;
}

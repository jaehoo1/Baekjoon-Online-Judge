# include <cstdio>
# include <vector>

using namespace std;

int main(void) {
	int n, num;
	vector<int> v;
	scanf("%d%d", &n, &num);
	v.push_back(num);
	for(int i=1 ; i<n ; i++) {
		scanf("%d", &num);
		if(num>v.back())
			v.push_back(num);
		else {
			vector<int>::iterator ptr=lower_bound(v.begin(), v.end(), num);
			*ptr=num;
		}
	}
	printf("%d", v.size());
	return 0;
}

# include <cstdio>
# include <unordered_map>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
	int n, a[100];
	unordered_map<int, int> um;
	vector<pair<int, int>> v;
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++) {
		scanf("%d", &a[i]);
		um[a[i]]++;
	}
	for(unordered_map<int, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
		v.push_back({iter->first, iter->second});
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i=0 ; i<v.size() ; i++)
		if(v[i].second==1)
			for(int j=0 ; j<n ; j++)
				if(v[i].first==a[j]) {
					printf("%d", j+1);
					return 0;
				}
	puts("none");
	return 0;
}
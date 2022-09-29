# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <unordered_map>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	if(a.second==b.second)
		return a.first<b.first;
	return a.second>b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	string s;
	unordered_map<string, int> um;
	cin>>n;
	for(int i=0 ; i<n ; i++) {
		cin>>s;
		um[s];
	}
	for(int i=0 ; i<n ; i++)
		while(cin>>s) {
			um[s]++;
			if(cin.get()=='\n')
				break;
		}
	vector<pair<string, int>> v(um.begin(), um.end());
	sort(v.begin(), v.end(), cmp);
	for(int i=0 ; i<n ; i++)
		cout<<v[i].first<<' '<<v[i].second<<'\n';
	return 0;
}
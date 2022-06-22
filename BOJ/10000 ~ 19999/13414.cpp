# include <iostream>
# include <string>
# include <unordered_map>
# include <vector>
# include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	return a.second<b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K, L;
	string s;
	unordered_map<string, int> um;
	vector<pair<string, int>> v;
	cin>>K>>L;
	for(int i=0 ; i<L ; i++) {
		cin>>s;
		um[s]=i;
	}
	for(unordered_map<string, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
		v.push_back({iter->first, iter->second});
	sort(v.begin(), v.end(), cmp);
	for(int i=0 ; i<K&&i<v.size() ; i++)
		cout<<v[i].first<<'\n';
	return 0;
}
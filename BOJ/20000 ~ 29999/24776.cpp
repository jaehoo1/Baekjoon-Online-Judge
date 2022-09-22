# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
# include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) { return a.second>b.second; }

int main(void) {
	unordered_map<string, int> um;
	string s;
	while(getline(cin, s)) {
		if(s=="***")
			break;
		um[s]++;
	}
	vector<pair<string, int>> v(um.begin(), um.end());
	sort(v.begin(), v.end(), cmp);
	if(v[0].second==v[1].second)
		cout<<"Runoff!";
	else
		cout<<v[0].first;
	return 0;
}
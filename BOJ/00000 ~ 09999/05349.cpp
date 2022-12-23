# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	unordered_map<string, int> um;
	vector<string> v;
	while(cin>>s) {
		um[s]++;
	}
	for(unordered_map<string, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
		if(iter->second>1)
			v.push_back(iter->first);
	sort(v.begin(), v.end());
	for(string s : v)
		cout<<s<<'\n';
	return 0;
}
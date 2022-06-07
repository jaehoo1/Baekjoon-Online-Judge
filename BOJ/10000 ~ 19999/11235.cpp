# include <iostream>
# include <unordered_map>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
	int n, max=0;
	string s;
	unordered_map<string, int> um;
	vector<string> v;
	cin>>n;
	while(n--) {
		cin>>s;
		um[s]++;
	}
	for(unordered_map<string, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
		if(iter->second>max)
			max=iter->second;
	for(unordered_map<string, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
		if(iter->second==max)
			v.push_back(iter->first);
	sort(v.begin(), v.end());
	for(int i=0 ; i<v.size() ; i++)
		cout<<v[i]<<'\n';
	return 0;
}
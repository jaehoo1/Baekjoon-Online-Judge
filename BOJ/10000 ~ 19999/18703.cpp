# include <iostream>
# include <unordered_map>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, N, id;
	string s;
	cin>>T;
	while(T--) {
		unordered_map<string, int> um;
		cin>>N;
		while(N--) {
			cin>>s>>id;
			if(um.find(s)==um.end())
				um[s]=id;
			else
				um[s]=min(um[s], id);
		}
		vector<int> v;
		for(unordered_map<string, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
			v.push_back(iter->second);
		sort(v.begin(), v.end());
		for(int i=0 ; i<v.size() ; i++)
			cout<<v[i]<<' ';
		cout<<'\n';
	}
	return 0;
}
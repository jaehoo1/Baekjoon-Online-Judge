# include <iostream>
# include <vector>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) { return a.second<b.second; }

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k, n, m, c, min, max, qtmk;
	string s;
	cin>>k;
	for(int t=1 ; t<=k ; t++) {
		min=max=qtmk=0;
		unordered_map<string, int> um;
		unordered_set<string> minset, maxset;
		cin>>n>>m;
		for(int i=0 ; i<n ; i++) {
			cin>>s>>c;
			um[s]=c;
		}
		vector<pair<string, int>> v(um.begin(), um.end());
		sort(v.begin(), v.end(), cmp);
		for(int i=0 ; i<m ; i++) {
			cin>>s;
			if(s=="?") {
				qtmk++;
				continue;
			}
			minset.insert(s);
			maxset.insert(s);
			min+=um[s];
			max+=um[s];
		}
		for(int i=0, j=0 ; j<qtmk ; i++)
			if(minset.find(v[i].first)==minset.end()) {
				minset.insert(v[i].first);
				min+=v[i].second;
				j++;
			}
		for(int i=v.size()-1, j=0 ; j<qtmk ; i--)
			if(maxset.find(v[i].first)==maxset.end()) {
				maxset.insert(v[i].first);
				max+=v[i].second;
				j++;
			}
		cout<<"Data Set "<<t<<":"<<'\n';
		cout<<min<<' '<<max<<'\n'<<'\n';
	}
	return 0;
}
# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, p, m, points;
	bool printed=false;
	string s;
	unordered_map<string, pair<int, bool>> um;
	cin>>n>>p>>m;
	while(n--) {
		cin>>s;
		um[s];
	}
	while(m--) {
		cin>>s>>points;
		um[s].first+=points;
		if(um[s].first>=p&&!um[s].second) {
			printed=true;
			um[s].second=true;
			cout<<s<<" wins!"<<'\n';
		}
	}
	if(!printed)
		cout<<"No winner!";
	return 0;
}
# include <iostream>
# include <vector>
# include <string>
# include <sstream>
# include <algorithm>
# include <unordered_map>

using namespace std;

vector<string> split(string str, char delim) {
	vector<string> v;
	stringstream ss(str);
	string temp;
	while(getline(ss, temp, delim))
		v.push_back(temp);
	return v;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	string s;
	for(int t=1 ; ; t++) {
		cin>>n;
		cin.ignore();
		if(!n)
			break;
		unordered_map<string, int> um;
		while(n--) {
			getline(cin, s);
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			vector<string> v=split(s, ' ');
			um[v.back()]++;
		}
		vector<pair<string, int>> v(um.begin(), um.end());
		sort(v.begin(), v.end());
		cout<<"List "<<t<<':'<<'\n';
		for(int i=0 ; i<v.size() ; i++)
			cout<<v[i].first<<" | "<<v[i].second<<'\n';
	}
	return 0;
}
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
	string s;
	while(getline(ss, s, delim))
		v.push_back(s);
	return v;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	string s;
	unordered_map<string, int> um;
	cin>>N;
	while(N--) {
		cin>>s;
		if(s.length()>3)
			sort(s.begin()+1, s.end()-1);
		um[s]++;
	}
	cin>>M;
	cin.get(); 
	while(M--) {
		int cou=1;
		getline(cin, s);
		vector<string> v=split(s, ' ');
		for(int i=0 ; i<v.size() ; i++) {
			if(v[i].length()>3)
				sort(v[i].begin()+1, v[i].end()-1);
			cou*=um[v[i]];
		}
		cout<<cou<<'\n';
	}
	return 0;
}

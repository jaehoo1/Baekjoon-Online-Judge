# include <iostream>
# include <string>
# include <unordered_map>
# include <vector>
# include <sstream>

using namespace std;

vector<string> split(string s, char delim) {
	vector<string> v;
	stringstream ss(s);
	string temp;
	while(getline(ss, temp, delim))
		v.push_back(temp);
	return v;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	unordered_map<string, string> um;
	while(getline(cin, s)) {
		if(s=="")
			break;
		vector<string> v=split(s, ' ');
		um[v[1]]=v[0];
	}
	while(cin>>s)
		if(um.find(s)==um.end())
			cout<<"eh"<<'\n';
		else
			cout<<um[s]<<'\n';
	return 0;
}
# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	string s;
	unordered_map<string, bool> um;
	cin>>s;
	for(int i=0 ; i<s.length() ; i++)
		for(int j=0 ; j<s.length()-i ; j++)
			um[s.substr(i, j+1)];
	cout<<um.size();
	return 0;
}

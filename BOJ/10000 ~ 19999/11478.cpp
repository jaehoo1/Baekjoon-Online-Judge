# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	string s;
	unordered_set<string> um;
	cin>>s;
	for(int i=0 ; i<s.length() ; i++)
		for(int j=0 ; j<s.length()-i ; j++)
			um.insert(s.substr(i, j+1));
	cout<<um.size();
	return 0;
}

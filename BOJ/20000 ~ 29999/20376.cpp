# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string d, s;
	unordered_set<string> us;
	while(cin>>d) {
		cin.get();
		getline(cin, s);
		us.insert(s);
	}
	cout<<us.size();
	return 0;
}
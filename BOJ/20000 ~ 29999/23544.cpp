# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	int n;
	string s;
	unordered_set<string> us;
	cin>>n;
	for(int i=0 ; i<n ; i++) {
		cin>>s;
		us.insert(s);
	}
	cout<<n-us.size();
	return 0;
}
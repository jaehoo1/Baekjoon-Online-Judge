# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, cou=0;
	string s;
	unordered_set<string> us;
	cin>>N;
	while(N--) {
		cin>>s;
		if(s=="ENTER")
			us=unordered_set<string>();
		else if(us.find(s)==us.end()) {
			cou++;
			us.insert(s);
		}
	}
	cout<<cou;
	return 0;
}
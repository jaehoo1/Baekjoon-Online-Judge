# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	char game;
	string s;
	unordered_set<string> us;
	cin>>N>>game;
	while(N--) {
		cin>>s;
		us.insert(s);
	}
	if(game=='Y')
		cout<<us.size();
	else if(game=='F')
		cout<<us.size()/2;
	else if(game=='O')
		cout<<us.size()/3;
	return 0;
}
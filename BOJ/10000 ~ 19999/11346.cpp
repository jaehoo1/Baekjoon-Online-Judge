# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, N, M;
	string s;
	cin>>T;
	while(T--) {
		unordered_set<string> us;
		cin>>N>>M;
		while(N--) {
			cin>>s;
			us.insert(s);
		}
		while(M--) {
			cin>>s;
			us.insert(s);
		}
		cout<<us.size()<<'\n';
	}
	return 0;
}